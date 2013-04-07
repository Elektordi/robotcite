#ifndef WIIMOTE_HH_
# define WIIMOTE_HH_

class Wiimote: public urbi::UObject
{
public:
  Wiimote(const std::string &name);
  ~Wiimote();
  int connect(const std::string &name);
  int init();
  
  urbi::UVar WiimoteOK;
  
	urbi::UVar Btn2;
	urbi::UVar Btn1;
	urbi::UVar B;
	urbi::UVar A;
	urbi::UVar Minus;
	urbi::UVar Home;
	urbi::UVar Left;
	urbi::UVar Right;
	urbi::UVar Down;
	urbi::UVar Up;
	urbi::UVar Plus;
	
	urbi::UVar Battery;
	urbi::UVar AccX;
	urbi::UVar AccY;
	urbi::UVar AccZ;
	
	urbi::UVar Acc;
	urbi::UVar Roll;
	urbi::UVar Pitch;
	
	urbi::UVar NunchukPresent;
	urbi::UVar NunchukC;
	urbi::UVar NunchukZ;
	urbi::UVar NunchukStickX;
	urbi::UVar NunchukStickY;
	urbi::UVar NunchukAccX;
	urbi::UVar NunchukAccY;
	urbi::UVar NunchukAccZ; 
	
	urbi::UVar ClassicPresent;
	urbi::UVar ClassicLStickX;
	urbi::UVar ClassicLStickY;
	urbi::UVar ClassicRStickX;
	urbi::UVar ClassicRStickY;
	urbi::UVar ClassicL;
	urbi::UVar ClassicR;
	//TODO: Classic buttons
	urbi::UVar ClassicButtons;
  
private:
	cwiid_wiimote_t *wiimote;	/* wiimote handle */
	bdaddr_t bdaddr;	/* bluetooth device address */
  int update();
  void ConnectThread();
	//void UpdateThread();

};


#endif /* !WIIMOTE_HH_ */
