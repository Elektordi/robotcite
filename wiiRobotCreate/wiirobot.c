// **********************************
// * Guillaume Genty, Novembre 2008 *
// *  Association Planète Sciences  *
// **********************************
// guillaume.genty@planete-sciences.org
//

#include <stdio.h>
#include <string.h>
#include <signal.h>

#include "wiirobot.h"


bool loop = 1;

int main( int argc, char* args[] )
{
	char* serialport = "/dev/ttyUSB0";
	char* bta = "";

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
					
				case 'b':
					if(arg+1<argc)
						bta = args[arg+1];
					arg+=2;
					break;
					
				case 'd':
					debug=1;
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
	
	printf("Connected... (Battery=%d)\n",iC_getBattCharge()); // La lecture sert à tester la connection avec le robot
	
	signal(SIGINT,quit);
  signal(SIGTERM,quit);
  signal(SIGQUIT,quit);

	wmconnect(bta);

	while(loop)
	{
		usleep(100000); // 100ms
			
		struct cwiid_state state;	/* wiimote state */
		cwiid_get_state(wiimote, &state);
		
		if(state.ext_type != CWIID_EXT_NUNCHUK)
		{
			printf("Nunchuk non connected!\n");
			break;
		}
		
		short X = state.ext.nunchuk.stick[CWIID_X];
		short Y = state.ext.nunchuk.stick[CWIID_Y];
		
		if(debug) printf("> X=%d Y=%d\n",X,Y);
		drive(Y-128, X-128);
	}
	
	cwiid_close(wiimote);

	iC_DriveDirect(0,0,0,0); // le quit() était une interruption, il ne peut pas lancer de commande car il y en a peut être déjà une en cours...
	closeICreateCom();
	printf("Terminated...\n");
}

void usage(char* appname)
{
	printf("*** wiiRobotCreate v1 ***\n");
	printf("Guillaume Genty - Planète Sciences\n");
	printf("<guillaume.genty@planete-sciences.org>\n");
	printf("\n");
	printf("Usage: %s\n",appname);
	printf("	-h | -V       Display this help & version\n");
	printf("	-s <device>   Select serial port (def: /dev/ttyUSB0)\n");
	printf("	-b <bt_addr>  Wiimote bluetooth address (def: ANY)\n");
	printf("	-d            Debug mode: Show in and out values (def: disabled)\n");
	printf("\n");
}

void quit()
{
	printf("*** Stopping current actions! ***\n");
	loop=0;
}

void wmconnect(char *bta)
{
	bdaddr = *BDADDR_ANY;
	str2ba(bta, &bdaddr);
	
	printf("Put Wiimote in discoverable mode now (press 1+2)...\n");


	if (!(wiimote = cwiid_open(&bdaddr,0))) {
		printf("Wiimote connect failed...\n");
		abort();
	}
	
	printf("Connected to Wiimote...\n");
	
	cwiid_set_rpt_mode(wiimote, CWIID_RPT_BTN | CWIID_RPT_ACC | CWIID_RPT_EXT);

}

void drive(int speed, int dir)
{
	int v = speed*5;
	if(v>-50 && v<50) v=0;
	
	int vl = v;
	int vr = v;
	
	v = dir;
	if(v>32)
	{
		vr = vr * (128-v)/128;
		vl = vl * (2-(128-v)/128);
		
		if(vl==0) vl=1000*(128-v)/128;
		if(vr==0) vr=-1000*(128-v)/128;
	}
	
	if(v<-32)
	{
		vl = vl * (128+v)/128;
		vr = vr * (2-(128+v)/128);
		
		if(vl==0) vl=-1000*(128+v)/128;
		if(vr==0) vr=1000*(128+v)/128;
	}

	if(debug) printf("< L=%d R=%d\n",vl,vr);
	drive_direct(vl,vr);
}

void drive_direct(short l, short r)
{
	if(l==lastl && r==lastr) return;
	iC_DriveDirect((r>>8)&0xFF, r&0xFF, (l>>8)&0xFF, l&0xFF);
	lastr=r; lastl=l;
}
