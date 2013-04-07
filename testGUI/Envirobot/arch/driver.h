//driver.h
#ifndef iCreateLib
#define iCreateLib


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
	void Demo(iRobotDemo demo);

/****************************************************/
	void Stop();
	void Drive(int velocity, int radius);
	void DriveStraight(int velocity);
	void DriveDirect(int right, int left);

/****************************************************/
/*	void LedPlay(bool on);
	void LedAdvance(bool on);
	void LedPower(byte intensity);
	void LedPowerC(byte intensity, byte color);
	void UpdateLeds();
*/

/****************************************************/
/*	void DigitalOut(byte num, bool state);
	void PWM(byte num, byte dutycycle);
*/
/****************************************************/
	void SendIR(byte data);

/****************************************************/
/*	void Forward(int distance_in_mm);
	void ForwardS(int distance_in_mm, int speed);

	void Backward(int distance_in_mm);
	void BackwardS(int distance_in_mm, int speed);

	void TurnLeft(int angle_in_degree); 
	void TurnLeftR(int angle_in_degree, int radius);
	void TurnLeftRS(int angle_in_degree, int radius, int speed);

	void TurnRight(int angle_in_degree);
	void TurnRightR(int angle_in_degree, int radius);
	void TurnRightRS(int angle_in_degree, int radius, int speed);*/

#endif
