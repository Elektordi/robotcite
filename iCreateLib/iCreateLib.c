/* */

#include "iCreateLib.h"
#include "serialLib.h"

//initialisation de la comunication avec l'iCreate
void initICreateCom(char* device)
{
  iCreateCom = initSerial(device, 57600, 8, 1, 0);
	if(iCreateCom==-1)
	{
		printf("*** Unable to open %s at 57600 bauds (8n1) [%s]\n",device,strerror(errno));
		abort();
	}
}

void closeICreateCom()
{
	closeSerial(iCreateCom);
}

//primitive d'initialisation de la comunication avec l'iCreate
void iC_Start(void)
{
  sendSerial(iCreateCom,128);
  flushRecieveBuffer(iCreateCom);
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
}

void iC_Full(void)
{
  sendSerial(iCreateCom,132);
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

void iC_Sensor(uint8 sensorId)
{
  sendSerial(iCreateCom,142);
  sendSerial(iCreateCom,sensorId);
}


//---------------------------------------

uint8 iC_getBumpsAndWDrops()
{
  iC_Sensor(7);
  return receiveSerial(iCreateCom);
}

uint8 iC_getWall()
{
  iC_Sensor(8);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffL()
{
  iC_Sensor(9);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffFL()
{
  iC_Sensor(10);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffFR()
{
  iC_Sensor(11);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffR()
{
  iC_Sensor(12);
  return receiveSerial(iCreateCom);
}

uint8 iC_getVirtualWall()
{
  iC_Sensor(13);
  return receiveSerial(iCreateCom);
}

uint8 iC_getOvercurrents()
{
  iC_Sensor(14);
  return receiveSerial(iCreateCom);
}

uint8 iC_getIRByte()
{
  iC_Sensor(17);
  return receiveSerial(iCreateCom);
}

uint8 iC_getButtons()
{
  iC_Sensor(18);
  return receiveSerial(iCreateCom);
}

int16 iC_getDistance()
{
  iC_Sensor(19);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}

int16 iC_getAngle()
{
  iC_Sensor(20);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}

uint8 iC_getChargeState()
{
  iC_Sensor(21);
  return receiveSerial(iCreateCom);
}

uint16 iC_getVoltage()
{
  iC_Sensor(22);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

int16 iC_getCurrent()
{
  iC_Sensor(23);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}

int8 iC_getBattTemp()
{
  iC_Sensor(24);
  return receiveSerial(iCreateCom) - SIGNED_OFFSET_8BITS;
}

uint16 iC_getBattCharge()
{
  iC_Sensor(25);
	return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint16 iC_getBattCap()
{
  iC_Sensor(26);
	return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint16 iC_getWallSig()
{
  iC_Sensor(27);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint16 iC_getCliffLSig()
{
  iC_Sensor(28);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint16 iC_getCliffFLSig()
{
  iC_Sensor(29);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint16 iC_getCliffFRSig()
{
  iC_Sensor(30);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint16 iC_getCliffRSig()
{
  iC_Sensor(31);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint8 iC_getDigitalIn()
{
  iC_Sensor(32);
  return receiveSerial(iCreateCom);
}

uint16 iC_getAnalogIn()
{
  iC_Sensor(33);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom);
}

uint8 iC_getChargeSrcAvailable()
{
  iC_Sensor(34);
  return receiveSerial(iCreateCom);
}

uint8 iC_getOIMode()
{
  iC_Sensor(35);
  return receiveSerial(iCreateCom);
}

uint8 iC_getSongNumber()
{
  iC_Sensor(36);
  return receiveSerial(iCreateCom);
}

uint8 iC_getSongPlaying()
{
  iC_Sensor(37);
  return receiveSerial(iCreateCom);
}

uint8 iC_getNStreamPackets()
{
  iC_Sensor(38);
  return receiveSerial(iCreateCom);
}

int16 iC_getVelocity()
{
  iC_Sensor(39);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}

int16 iC_getRadius()
{
  iC_Sensor(40);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}

int16 iC_getRVelocity()
{
  iC_Sensor(41);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}

int16 iC_getLVelocity()
{
  iC_Sensor(42);
  return (receiveSerial(iCreateCom)<<8) + receiveSerial(iCreateCom) - SIGNED_OFFSET_16BITS;
}
