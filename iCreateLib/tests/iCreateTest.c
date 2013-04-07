#include <stdio.h>
#include "../iCreateLib.h"

#define iC_getBumper iC_getBumpsAndWDrops

int main(void)
{
	printf("Connexion...\n");
	
	initICreateCom("/dev/ttyUSB0");
	iC_Start();
	iC_Full();
	
	printf("Connecté...\n");
	
	while(1)
	{
	
		if(iC_getBumper())
		{
			iC_LEDs(0,255,255); // LED Power Rouge
			printf("Rouge !\n");
		}
		else
		{
			iC_LEDs(0,0,255); // LED Power Verte
			printf("Vert !\n");
		}
	}
	
	iC_LEDs(0,0,0); // LED Power éteinte
	printf("Fini...\n");
	closeICreateCom();
}
