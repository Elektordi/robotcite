//driver.c
#include "driver.h"


//Todo : 
// - changer les nom des fichier
// - Revoir les fonctions de controles des leds

/****************************************************
* Driver pour la base iRobot(R) Create              *
* (Base mobile utilisée pour robotcité 2008)        *
*                                                   *
* Auteurs : Sam                                     *
* Pour : Planete Sciences                           *
* notes :                                           *
* Portage du C# en C du driver de Guillaume Genty   *
*****************************************************/



/****************************************************/




/****************************************************/



	void Demo(iRobotDemo demo)
	{
		SendByte(136);
		SendByte((byte)demo);
	}
	
	void Stop()
	{
		DriveDirect(0,0);
	}
	
	void Drive( int velocity,  int radius)
	{
		SendByte(137);
		SendInt16((Int16)velocity);
		SendInt16((Int16)radius); 
	}
	
	void DriveStraight( int velocity)
	{
		Drive(velocity,Int16.MaxValue);
	}
	
	void DriveDirect( int right,  int left)
	{
		SendByte(145);
		SendInt16((Int16)right);
		SendInt16((Int16)left);
	}
/*	
	void LedPlay(bool on)
	{
		if(on) LedBits = (byte)( LedBits | 1 );
		else LedBits = (byte)( LedBits & (255-1) );
		UpdateLeds();
	}
	
	void LedAdvance(bool on)
	{
		if(on) LedBits = (byte)( LedBits | 3 );
		else LedBits = (byte)( LedBits & (255-3) );
		UpdateLeds();
	}
	
	void LedPower(byte intensity)
	{
		PowerIntensity = intensity;
		UpdateLeds();
	}
	
	void LedPowerC(byte intensity, byte color)
	{
		PowerColor = color;
		PowerIntensity = intensity;
		UpdateLeds();
	}
	
	void UpdateLeds()
	{
		SendByte(139);
		SendByte(LedBits);
		SendByte(PowerColor);
		SendByte(PowerIntensity);
	}
*/	
/*
	void DigitalOut(byte num, bool state)
	{
		if(num>2 || num<0) throw new InvalidOperationException("Invalid Digital Output ID ("+num.ToString()+")");
		if(state) DigitalOutBits = (byte)( DigitalOutBits | num );
		else DigitalOutBits = (byte)( DigitalOutBits & (255-num) );            
		
		SendByte(147);
		SendByte(DigitalOutBits);
	}
	
	void PWM(byte num, byte dutycycle)
	{
		if(num>2 || num<0) throw new InvalidOperationException("Invalid PWM ID ("+num.ToString()+")");
		pwm[num] = (byte)(dutycycle/2);
		
		SendByte(144);
		SendByte(pwm[2]);
		SendByte(pwm[1]);
		SendByte(pwm[0]);
	}
*/	
	void SendIR(byte data)
	{
		SendByte(151);
		SendByte(data);
	}
/*	
	void Forward( int distance_in_mm)
	{
		Forward(distance_in_mm, Int16.MaxValue);
	}
	void ForwardS( int distance_in_mm,  int speed)
	{
		Distance = 0;
		DriveStraight(speed);
		while(Distance<distance_in_mm) Thread.Sleep(15);
		Stop();
	}
	
	void Backward( int distance_in_mm)
	{
		ForwardS(distance_in_mm,  int.MinValue);
	}
	void BackwardS( int distance_in_mm,  int speed)
	{
		ForwardS(distance_in_mm, ( int)(-speed));
	}
	
	void TurnLeft( int angle_in_degree) // Sur place...
	{
		TurnLeftRS(angle_in_degree,  int.MinValue, Int16.MaxValue);
	}
	void TurnLeft( int angle_in_degree,  int radius)
	{
		TurnLeftRS(angle_in_degree, radius, Int16.MaxValue);
	}
	void TurnLeftRS( int angle_in_degree,  int radius,  int speed)
	{
		Angle = 0;
		Drive(speed, radius);
		while(-Angle<angle_in_degree) Thread.Sleep(15);
		Stop();
	}
	
	void TurnRight( int angle_in_degree)  // Sur place...
	{
		TurnRightRS(angle_in_degree, Int16.MaxValue, Int16.MaxValue);
	}
	void TurnRight( int angle_in_degree,  int radius)
	{
		TurnRightRS(angle_in_degree, radius, Int16.MaxValue);
	}
	void TurnRightRS( int angle_in_degree,  int radius,  int speed)
	{
		Angle = 0;
		Drive(speed, radius);
		while(Angle<angle_in_degree) Thread.Sleep(15);
		Stop();
	}

*/
