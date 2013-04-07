// ========================================
//  Logique EnviRobotCité (Implémentation)
// ========================================

// *********************************
// * Guillaume Genty, Octobre 2008 *
// *     Projet  EnviRobotCité     *
// * Association  Planète Sciences *
// *********************************
// guillaume.genty@planete-sciences.org
//

#include <stdio.h>
#include <string.h>
#include <signal.h>

#include "envirobot.h"
#include "envirobot_shm.h"
#include "../../iCreateLib/iCreateLib.h"

int main( int argc, char* args[] )
{
	char* serialport = "/dev/ttyUSB0";

	if(argc>1)
	{
		int arg=1;

		while(arg<argc)
		{		
			if(args[arg][0]!='-' || strlen(args[arg])!=2) // "-x" = 2 chars
			{
				printf("Bad argument: %s\nRun %s -h for help...\n",args[arg],args[0]);
				return;
			}
		
			switch(args[arg][1])
			{
				case 'h':
				case 'V':
					usage(args[0]);
					return;
					
				case 's':
					if(arg+1<argc)
						serialport = args[arg+1];
					arg+=2;
					break;
					
				case 'l':
					if(arg+1<argc)
						low_charge = atoi(args[arg+1]);
					arg+=2;
					break;
					
				case 'c':
					if(arg+1<argc)
						high_charge = atoi(args[arg+1]);
					arg+=2;
					break;
					
				case 'k':
					if(arg+1<argc)
						shm_key = atoi(args[arg+1]);
					arg+=2;
					break;
					
				case 'b':
					base_is_flower = 1;
					printf("Homebase will now be seen as a flower...\n");
					arg++;
					break;
					
				default:
					printf("Unknow argument -%c\nRun %s -h for help...\n",args[arg][1],args[0]);
					return;
			}
		}
	}
	
	printf("Connecting to %s...\n",serialport);
	initICreateCom(serialport);
	iC_Start();
	iC_Full();
	
	signal(SIGINT,quit);
  signal(SIGTERM,quit);
  signal(SIGQUIT,quit);
  
 	shm_master();
 	init_erc_shared();
 	
 	srand ( time(NULL) ); // Init random
	
	printf("Connected... (Battery=%d)\n",iC_getBattCharge()); // La lecture sert à tester la connection avec le robot

	state = state_search;
	ERC->alive=1;

	while(loop)
	{
		usleep(100000); // 100ms
		
		if(!sub_delay)
		{
			sub_delay = 50; // Toutes les 5 secondes
			int flwid;
			for(flwid=0;flwid<NB_PLANTES;flwid++)
			{
				if(flwid==flower) continue; // Pas sur la plante en cours d'arrosage...
							
				if(ERC->level_w[flwid]<6)
					ERC->level_w[flwid]=0;
				else
					ERC->level_w[flwid]-= rand()%6;
				
				if(ERC->level_p[flwid]<3)
					ERC->level_p[flwid]=0;
				else
					ERC->level_p[flwid]-= rand()%3;
					
				if(ERC->level_n[flwid]<3)
					ERC->level_n[flwid]=0;
				else
					ERC->level_n[flwid]-= rand()%3;
					
				if(ERC->level_k[flwid]<3)
					ERC->level_k[flwid]=0;
				else
					ERC->level_k[flwid]-= rand()%3;
			}
		}
		sub_delay--;
		
		if(strcmp(robot_laststatus,robot_status)!=0)
		{
			printf("New status: %s (was: %s)\n",robot_status,robot_laststatus);
			strcpy(robot_laststatus,robot_status);
			strcpy(ERC->status,robot_status);
		}
		
		ERC->Battery = iC_getBattCharge();
	
		if(ERC->ManualControl)
		{
			set_status(0,"Manual control");
			drive_direct(ERC->vl, ERC->vr);
		}
		else
			(*state)(); // state est un pointeur vers la bonne fonction
	}

	ERC->alive=0;

	iC_DriveDirect(0,0,0,0); // le quit() était une interruption, il ne peut pas lancer de commande car il y en a peut être déjà une en cours...
	closeICreateCom();
	printf("Terminated...\n");
	
	shm_leave();
}

void usage(char* appname)
{
	printf("*** EnviRobotC v1 ***\n");
	printf("Guillaume Genty - Planète Sciences\n");
	printf("<guillaume.genty@planete-sciences.org>\n");
	printf("\n");
	printf("Usage: %s\n",appname);
	printf("	-h | -V       Display this help & version\n");
	printf("	-s <device>   Select serial port (def: /dev/ttyUSB0)\n");
	printf("	-l <charge>   Low battery level (def: 2200)\n");
	printf("	              0: Never charge - 9999: Always charge\n");
	printf("	-c <charge>   Battery charged level (def: 2500)\n");
	printf("	-b            Homebase is a flower ! (def: disabled)\n");
	printf("	-k <key>      Shared Memory Key (def: 1962)\n");
	printf("\n");
}

void quit()
{
	printf("*** Stopping current actions! ***\n");
	loop=0;
	ERC->alive=0;
}

void set_status(int id, const char* status)
{
	strcpy(robot_status,status);
	ERC->id_status = id;
}

void drive_direct(int l, int r)
{
	if(l==lastl && r==lastr) return;
	iC_DriveDirect((r>>8)&0xFF, r&0xFF, (l>>8)&0xFF, l&0xFF);
	lastr=r; lastl=l;
}

bool search_around()
{
	int vl = 100;
	int vr = 100;
	
	int bumpers = iC_getBumper();
	bumperL = (bumpers&2)>0;
	bumperR = (bumpers&1)>0;
	
	if(iC_getWallSig()>50)
	{
		vl = -50;
		vr = 50;
		lastrot=1;
	}
	
	if(bumperL && bumperR)
	{
		state = state_back;
	}
	else
	{
		if(bumperL)
		{
			vl = 0;
			vr = -100;
			lastrot = -1;
		}
	
		if(bumperR)
		{
			vl = -100;
			vr = 0;
			lastrot = 1;
		}
	}
	
	drive_direct(vl,vr);
	return bumperL || bumperR;
}

void state_search()
{
	set_status(1,"Searching flowers");
	
	if(search_around()) return;
	
	if(iC_getBattCharge()<low_charge) // -l 2200
	{
		state = state_search_base;
	}
	
	short ir = iC_getIRByte();
	
	if(base_is_flower && ir != 255) // Base is a flower ! <=> -b
	{
		state = state_docking;
		ERC->plante_a_portee = flower = 0; // Base = Plante 0
	}
	
	if(ir<240)
	{
		state = state_docking;
		ERC->plante_a_portee = flower = ir>>4;
	}
}

void state_search_base()
{
	set_status(2,"Searching base");

	if(search_around()) return;
	
	//if(iC_getIRByte()<255 && iC_getIRByte()>240 && iC_getIRByte()!=242 && iC_getIRByte()!=240) // 242 = F !R !G  &  240 = Reserved ?! mais arrive quand même quand dans F
	if(iC_getIRByte()==254)
	{
		drive_direct(0,0);
		iC_Demo(1);
		state = state_demo_dock;
	}
}

void state_back()
{
	set_status(3,"Backwarding");
	backstep++;
	if(backstep<10)
	{
		drive_direct(-100,-100);
	}
	else
	{
		drive_direct(-100*lastrot,100*lastrot); // lastrot = 1 (gauche) ou -1 (droite)
	}
	
	if(backstep>20)
	{
		drive_direct(0,0);
		backstep=0;
		state = state_search;
	}
}

void state_demo_dock()
{
	set_status(4,"Docking on base");
	//iC_Demo(1); --> Lors de la transition (ci-dessus)

	if(iC_getChargeState()>0)
	{
		state = state_charge;
	}

	int ir = iC_getIRByte();
	if(ir<240 || ir==255 || ir==242 || ir==240) // 242 = F !R !G  &  240 = Reserved ?! mais arrive quand même quand dans F
		demo_dock_timeout++;
	
	if(demo_dock_timeout>30)
	{
		iC_Demo(-1); // STOP DEMO
		usleep(500000);
		iC_Full();
		state = state_search_base;
		demo_dock_timeout = 0;
	}
}

void state_charge()
{
	set_status(5,"Charging battery");
	if(iC_getBattCharge()>high_charge)
	{
		iC_Demo(-1); // STOP DEMO
		usleep(500000);
		iC_Full();
		state = state_undock;		
	}
}

void state_docking()
{
	set_status(6,"Approching flower");
	int ir = iC_getIRByte();
	bool G = (ir&4)>0;
	bool R = (ir&8)>0;
	
	if(ir==255)
	{
		G=0;
		R=0;
	}
	
	int vl = 100;
	int vr = 100;
	
	if(R && G && !gobase_found) gobase_found=1;
	//if(!R && !G) gobase_found=0; // Ca servait à rien...

	if(gobase_found)
	{
		//printf("Base located !");
		if(R && !G)
		{
			vl = -50;
			vr = 50;
			//printf("The base is at left... (<==)");
		}
		if(G && !R)
		{
			vl = 50;
			vr = -50;		
			//printf("The base is at right... (==>)");
		}
	}	
	
	drive_direct(vl,vr);

	if(iC_getBumper()) //bumperL || bumperR
	{
		drive_direct(0,0);
		if(gobase_found)
		{
			state = state_action;
		}
		else
		{
			state = state_search;
			ERC->plante_a_portee = flower = -1;
		}
		gobase_found=0; // RAZ pour prochain dock
	}
}

void state_action()
{

	switch(action_state)
	{
		case 2:
			ERC->level_w[flower]++;
			break;
			
		case 3:
			ERC->level_p[flower]++;
			break;
			
		case 4:
			ERC->level_n[flower]++;
			break;
			
		case 5:
			ERC->level_k[flower]++;
			break;
	}

	// action_lenght et _state sont à 0 au début de l'action
	if(action_lenght<=0)
	{
		action_state++;
		
		switch(action_state)
		{
			case 1:
				set_status(10,"[flower] Scanning");
				action_lenght = 50; //5s
				break;

			case 2:
				set_status(11,"[flower] Watering");
				action_lenght = 100 - ERC->level_w[flower];
				break;
				
			case 3:
				set_status(12,"[flower] Distributing P.");
				action_lenght = 100 - ERC->level_p[flower];
				break;
				
			case 4:
				set_status(13,"[flower] Distributing N.");
				action_lenght = 100 - ERC->level_n[flower];
				break;
				
			case 5:
				set_status(14,"[flower] Distributing K.");
				action_lenght = 100 - ERC->level_k[flower];
				break;				
				
			default: // (>5) Terminé
				ERC->plante_a_portee = flower = -1;
				action_state = 0;
				state = state_undock;
		}
		
		iC_DigitalOut(action_state);
	}
	else
		action_lenght--;
	
}

void state_undock()
{
	set_status(7,"Disengaging");
	undock_step++;
	if(undock_step<20) // TODO: 20cm avec l'odométrie
	{
		drive_direct(-100,-100);
	}
	else
	{
		drive_direct(100,-100);
	}
	
	if(undock_step>30) // TODO: 180° avec l'odométrie
	{
		drive_direct(0,0);
		undock_step=0;
		state = state_search;
	}
}


