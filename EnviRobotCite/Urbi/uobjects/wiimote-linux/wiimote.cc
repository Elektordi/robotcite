#include <stdio.h>
#include <math.h>
#include <sstream>

#include <libport/thread.hh>

#include <cwiid.h>
#include <urbi/uobject.hh>

#include "wiimote.hh"

#define echo urbi::echo

/* Default device and calibration file paths. */

# define SEND_TO_CLIENT_ENGINE(Client, Msg)         \
  do {                                              \
    std::stringstream cmd;                          \
    cmd << Msg;                                     \
    Client->send(cmd.str().c_str());                \
  } while(0)


# define SEND_TO_ENGINE(Msg)   SEND_TO_CLIENT_ENGINE(this, Msg)

# define debug(msg)         												\
  do {                                              \
    std::stringstream cmd;                          \
    cmd << "+connection(\"all\") : echo(\"[Wiimote] ";        \
    cmd << msg;                                     \
    cmd << "\");";                                  \
    this->send(cmd.str().c_str());                \
  } while(0)

Wiimote::Wiimote(const std::string &name) :urbi::UObject(name)
{
	UBindVar(Wiimote,WiimoteOK);

	UBindVar(Wiimote,Btn2);
	UBindVar(Wiimote,Btn1);
	UBindVar(Wiimote,B);
	UBindVar(Wiimote,A);
	UBindVar(Wiimote,Minus);
	UBindVar(Wiimote,Home);
	UBindVar(Wiimote,Left);
	UBindVar(Wiimote,Right);
	UBindVar(Wiimote,Up);
	UBindVar(Wiimote,Down);
	UBindVar(Wiimote,Plus);
	
	UBindVar(Wiimote,Battery);
	UBindVar(Wiimote,AccX);
	UBindVar(Wiimote,AccY);
	UBindVar(Wiimote,AccZ);
	
	UBindVar(Wiimote,Acc);
	UBindVar(Wiimote,Roll);
	UBindVar(Wiimote,Pitch);	
	
	UBindVar(Wiimote,NunchukPresent);
	UBindVar(Wiimote,NunchukC);
	UBindVar(Wiimote,NunchukZ);
	UBindVar(Wiimote,NunchukStickX);
	UBindVar(Wiimote,NunchukStickY);
	UBindVar(Wiimote,NunchukAccX);
	UBindVar(Wiimote,NunchukAccY);
	UBindVar(Wiimote,NunchukAccZ); 
	
	UBindVar(Wiimote,ClassicPresent);
	UBindVar(Wiimote,ClassicLStickX);
	UBindVar(Wiimote,ClassicLStickY);
	UBindVar(Wiimote,ClassicRStickX);
	UBindVar(Wiimote,ClassicRStickY);
	UBindVar(Wiimote,ClassicL);
	UBindVar(Wiimote,ClassicR);
	UBindVar(Wiimote,ClassicButtons);
	
  UBindFunction(Wiimote, connect);
  UBindFunction(Wiimote, init);
  
  wiimote = NULL;
  
  WiimoteOK = 0;
}


int Wiimote::init()
{
	return connect("");
}

int Wiimote::connect(const std::string &bta)
{	
	str2ba(bta.c_str(), &bdaddr);
	
	debug("Put Wiimote in discoverable mode now (press 1+2)...");

	libport::startThread(this,&Wiimote::ConnectThread);
	return 0;
}

void Wiimote::ConnectThread()
{
	if (!(wiimote = cwiid_open(&bdaddr,CWIID_FLAG_NONBLOCK))) {
		debug("Wiimote connect failed...");
		return;// -1;
	}
	
	debug("Connected to Wiimote...");
	
	cwiid_set_rpt_mode(wiimote, CWIID_RPT_BTN | CWIID_RPT_ACC | CWIID_RPT_EXT);

  USetUpdate(25);
/*
	struct cwiid_state state;
	cwiid_get_state(wiimote, &state);
  return (int)(100.0 * state.battery / CWIID_BATTERY_MAX);
*/
  WiimoteOK = 1;
  //return 1;
}


int Wiimote::update()
{
	/*libport::startThread(this,&Wiimote::UpdateThread);
	return 0;
}

void Wiimote::UpdateThread()
{*/
	struct cwiid_state state;	/* wiimote state */
	cwiid_get_state(wiimote, &state);
	
	Btn2 = (state.buttons & CWIID_BTN_2)>0;
 	Btn1 = (state.buttons & CWIID_BTN_1)>0;
	B = (state.buttons &  CWIID_BTN_B)>0;
	A = (state.buttons &  CWIID_BTN_A)>0;
	Minus = (state.buttons &  CWIID_BTN_MINUS)>0;
	Home = (state.buttons &  CWIID_BTN_HOME)>0;
	Left = (state.buttons &  CWIID_BTN_LEFT)>0;
	Right = (state.buttons &  CWIID_BTN_RIGHT)>0;
	Down = (state.buttons &  CWIID_BTN_DOWN)>0;
	Up = (state.buttons &  CWIID_BTN_UP)>0;
	Plus = (state.buttons &  CWIID_BTN_PLUS)>0;
	
	Battery = (int)(100.0 * state.battery / CWIID_BATTERY_MAX);
	
	double _AccX, _AccY, _AccZ, _Acc, _Roll, _Pitch;
	_AccX = state.acc[CWIID_X];
	_AccY = state.acc[CWIID_Y];
	_AccZ = state.acc[CWIID_Z];

	_Acc = sqrt(pow(_AccX,2)+pow(_AccY,2)+pow(_AccZ,2));
	_Roll = atan(_AccX/_AccZ);
	if (_AccX <= 0.0) {
		_Roll += PI * ((_AccX > 0.0) ? 1 : -1);
	}
	_Roll *= -1;
	_Pitch = atan(_AccY/_AccZ*cos(_Roll));
	
	AccX = _AccX;
	AccY = _AccY;
	AccZ = _AccZ;
	Acc = _Acc;
	Roll = _Roll;
	Pitch = _Pitch;
	
	NunchukPresent = false;
	ClassicPresent = false;
	
	if(state.ext_type == CWIID_EXT_NUNCHUK)
	{
		NunchukPresent = true;
		NunchukC = (state.ext.nunchuk.buttons &  CWIID_NUNCHUK_BTN_C)>0;
		NunchukZ = (state.ext.nunchuk.buttons &  CWIID_NUNCHUK_BTN_Z)>0;;
		NunchukStickX = state.ext.nunchuk.stick[CWIID_X];
		NunchukStickY = state.ext.nunchuk.stick[CWIID_Y];
		NunchukAccX = state.ext.nunchuk.acc[CWIID_Y];
		NunchukAccY = state.ext.nunchuk.acc[CWIID_Y];
		NunchukAccZ = state.ext.nunchuk.acc[CWIID_Y]; 
	}
	else if(state.ext_type == CWIID_EXT_CLASSIC)
	{
		ClassicPresent = true;
		ClassicLStickX = state.ext.classic.l_stick[CWIID_X];
		ClassicLStickY = state.ext.classic.l_stick[CWIID_Y];
		ClassicRStickX = state.ext.classic.r_stick[CWIID_X];
		ClassicRStickY = state.ext.classic.r_stick[CWIID_Y];
		ClassicL = state.ext.classic.l;
		ClassicR = state.ext.classic.r;
		ClassicButtons = state.ext.classic.buttons;
	}
	
  return 0;
}



Wiimote::~Wiimote() {
	debug("Closing Wiimote...");
	if(wiimote) cwiid_close(wiimote);

}

UStart(Wiimote);
