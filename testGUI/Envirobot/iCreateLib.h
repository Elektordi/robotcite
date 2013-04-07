#ifndef _iCreateLib
#define _iCreateLib

#include "serialLib.h"

//todo : definition de uint8


//*******************************************************
//** Auteur : Sam
//**
//** Note : Pour des raison de cohesion, merci de 
//** ne pas toucher aux prototypes sans m'en avoir 
//** prealablement parlé, et de respecter les conventions
//** utilisés (indentation, parenthésage, ...)
//**
//** PS : SVN ne remplace ni le mail ni le telephone ;c)
//********************************************************/


#define BUMPER_R 1
#define BUMPER_L 2


//initialisation de la comunication avec l'iCreate
void initICreateCom(char* device);

int iCreateCom;

//--------------------------------------
//primitives Open Interface :uint8 iC_getWall();

void iC_Start(void);
void iC_Baud(uint8 baudCode);

void iC_Safe(void);
void iC_Full(void);

void iC_Demo(uint8 demoID);

void iC_Drive(uint8 velocity_h, uint8 velocity_l, uint8 radius_h, uint8 radius_l);
void iC_DriveDirect(uint8 rVelocity_h, uint8 rVelocity_l, uint8 lVelocity_h, uint8 lVelocity_l);
void iC_LEDs(uint8 LEDBits, uint8 powerCol, uint8 powerInt);
void iC_DigitalOut(uint8 outBits);
void iC_PWMLowSide(uint8 LSD2Duty, uint8 LSD1Duty, uint8 LSD0Duty);
void iC_LowSideDrivers(uint8 driverBits);

void iC_SendIR(uint8 byteValue);

/*fonctions song & Ci non implémentées, a faire si besoin*/

void iC_Sensor(uint8 packetID);
void iC_QueryList(uint8* packetList);
void iC_Stream(uint8* packetList);
void iC_StreamPause(uint8 streamState);

/*fonction de script non implémentés (wait y compris), a fair si besoin*/


//--------------------------------------
//acceseur des variable et capteur de l'iCreat :

uint8 iC_getWall();
uint8 iC_getBumper();


//--------------------------------------
//fonction 16bit :


//--------------------------------------
//utils :



#endif


