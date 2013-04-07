// ====================================
//  GUI EnviRobotCité (Implémentation)
// ====================================

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

#include "envirobotgui.h"
#include "../EnviRobotC/envirobot_shm.h"

int main( int argc, char* args[] )
{
	gtk_init(&argc, &args);

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
					
				case 'k':
					if(arg+1<argc)
						shm_key = atoi(args[arg+1]);
					arg+=2;
					break;
					
				default:
					printf("Unknow argument -%c\nRun %s -h for help...\n",args[arg][1],args[0]);
					return;
			}
		}
	}
	
	signal(SIGINT,quit);
  signal(SIGTERM,quit);
  signal(SIGQUIT,quit);
	
	shm_slave();
	
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_title(GTK_WINDOW(MainWindow), "EnviRobotGUI");
	gtk_window_resize(GTK_WINDOW(MainWindow), 200, 200);
	gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER);

	Label1=gtk_label_new("Please wait...");
	gtk_label_set_use_markup(GTK_LABEL(Label1), TRUE);
	gtk_label_set_justify(GTK_LABEL(Label1), GTK_JUSTIFY_LEFT);
	gtk_container_add(GTK_CONTAINER(MainWindow), Label1);

	g_timeout_add(100, update, Label1);

  gtk_widget_show_all(MainWindow);
  gtk_main();
	
	gtk_exit(EXIT_SUCCESS);
	shm_leave();
}

gboolean update(gpointer data)
{
	if(!ERC->alive)
	{
		printf("*** MASTER PROCESS SHUTDOWN ***\n");
		gtk_main_quit();
		return;
	}
	
	char chaine[1024] = "";
	char *control;
	
	if(ERC->ManualControl)
		control="Manual";
	else
		control="A.I.";
	
	sprintf(chaine,"<u>EnviRobotCité GUI</u>\n\n<b>Battery</b>: %.2f v\n<b>Status</b>: %s\n<b>Control mode</b>: %s", (float)(ERC->Battery)/100, ERC->status, control);
	gtk_label_set_label(GTK_LABEL(Label1), chaine);
	
}

void quit()
{
	printf("*** Stopping current actions! ***\n");
	gtk_main_quit();
}

void usage(char* appname)
{
	printf("*** EnviRobotGUI v1 ***\n");
	printf("Guillaume Genty - Planète Sciences\n");
	printf("<guillaume.genty@planete-sciences.org>\n");
	printf("\n");
	printf("Usage: %s\n",appname);
	printf("	-h | -V       Display this help & version\n");
	printf("	-k <key>      Shared Memory Key (def: 1962)\n");
	printf("\n");
}

