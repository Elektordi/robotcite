 

#include "iCreateLib.h"
#include "serialLib.h"

//initialisation de la comunication avec l'iCreate
void initICreateCom(char* device)
{
  iCreateCom = initSerial(device, 57600, 8, 1, 0);
}

//primitive d'initialisation de la comunication avec l'iCreate
void iC_Start(void)
{
  sendSerial(iCreateCom,128);
}

void iC_Baud(uint8 baudCode)
{
  /*rajouter un test de validité de la valeur*/
  sendSerial(iCreateCom,129);
  sendSerial(iCreateCom,baudCode);
}


void iC_Safe(void)
{
  sendSerial(iCreateCom,131);
  flushRecieveBuffer(iCreateCom);
}

void iC_Full(void)
{
  sendSerial(iCreateCom,132);
  flushRecieveBuffer(iCreateCom);
}

void iC_Demo(uint8 demoID)
{
  sendSerial(iCreateCom,136);
  sendSerial(iCreateCom,demoID);
}

void iC_Drive(uint8 velocity_h, uint8 velocity_l, uint8 radius_h, uint8 radius_l)
{
  sendSerial(iCreateCom,137);
  sendSerial(iCreateCom,velocity_h);
  sendSerial(iCreateCom,velocity_l);
  sendSerial(iCreateCom,radius_h);
  sendSerial(iCreateCom,radius_l);
}

void iC_DriveDirect(uint8 rVelocity_h, uint8 rVelocity_l, uint8 lVelocity_h, uint8 lVelocity_l)
{
  sendSerial(iCreateCom,145);
  sendSerial(iCreateCom,rVelocity_h);
  sendSerial(iCreateCom,rVelocity_l);
  sendSerial(iCreateCom,lVelocity_h);
	sendSerial(iCreateCom,lVelocity_l);
}

void iC_LEDs(uint8 LEDBits, uint8 powerCol, uint8 powerInt)
{
  sendSerial(iCreateCom,139);
  sendSerial(iCreateCom,LEDBits);
  sendSerial(iCreateCom,powerCol);
  sendSerial(iCreateCom,powerInt);
}

void iC_DigitalOut(uint8 outBits)
{
  sendSerial(iCreateCom,147);
  sendSerial(iCreateCom,outBits);
}

void iC_PWMLowSide(uint8 LSD2Duty, uint8 LSD1Duty, uint8 LSD0Duty)
{
  sendSerial(iCreateCom,144);
  sendSerial(iCreateCom,LSD2Duty);
  sendSerial(iCreateCom,LSD1Duty);
  sendSerial(iCreateCom,LSD0Duty);
}

void iC_LowSideDrivers(uint8 driverBits)
{
  sendSerial(iCreateCom,138);
  sendSerial(iCreateCom,driverBits);
}

void iC_SendIR(uint8 byteValue)
{
  sendSerial(iCreateCom,151);
  sendSerial(iCreateCom,byteValue);
}


//---------------------------------------

void iC_Sensor(uint8 sensorId)
{
	sendSerial(iCreateCom,142);
  sendSerial(iCreateCom,sensorId);
}

//accesseur du capteur Bumper
uint8 iC_getBumper()
{
  iC_Sensor(7);
  return receiveSerial(iCreateCom);
}

//accesseur du capteur Wall
uint8 iC_getWall()
{
  iC_Sensor(8);
  return receiveSerial(iCreateCom);
}
