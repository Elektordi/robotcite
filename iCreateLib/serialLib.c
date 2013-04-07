#include "serialLib.h"

#define SEND_WAIT_US 10000
#define RECEIVE_TIMEOUT CLOCKS_PER_SEC // 1s

/*initialise le port série*/
int initSerial(char* device, long baudrate, int nData, int nStop, int parity)
{
  struct termios new_attributes;
  
  int tty_fd= open(device,O_RDWR | O_NOCTTY | O_NONBLOCK);
  if (tty_fd<0) {
    return -1;
  } else {
  
    fcntl(tty_fd, F_SETFL, 0);
  
    tcgetattr(tty_fd,&new_attributes);
    
    long BAUD = selectBaud(baudrate);
    long DATABITS = selectNDataBits(nData);
    long STOPBITS = selectNStopBits(nStop);
    ParityState par = selectParity(parity);
    
    // c_cflag
    /*new_attributes.c_cflag &= ~CRTSCTS;
    new_attributes.c_cflag &= ~PARENB;
    
    new_attributes.c_cflag |= CS8;
    new_attributes.c_cflag |= CSTOPB;
    new_attributes.c_cflag |= CLOCAL;
    
    new_attributes.c_cflag |= CREAD;
    new_attributes.c_cflag |= BAUD;
    new_attributes.c_cflag |= DATABITS;
    new_attributes.c_cflag |= STOPBITS;
    new_attributes.c_cflag |= par.PARITY_ON;
    new_attributes.c_cflag |= par.PARITY_ODD;*/
    
    new_attributes.c_cflag &= ~(PARENB| CBAUD |CSIZE | CRTSCTS);
    new_attributes.c_cflag |= (CS8 | CSTOPB | CREAD | CLOCAL);

	  cfsetospeed(&new_attributes, BAUD);
    cfsetispeed(&new_attributes, BAUD);
    
    // c_iflag
    new_attributes.c_iflag |= IGNPAR;     // Ignore framing errors and parity errors.
    new_attributes.c_iflag |= IGNBRK;
    
    // c_lflag
    /*
    new_attributes.c_lflag &= ~(ICANON);
    new_attributes.c_lflag &= ~(ECHO);
    new_attributes.c_lflag &= ~(ECHOE);
    new_attributes.c_lflag &= ~(ISIG);
    */
    new_attributes.c_lflag = 0;
    
    new_attributes.c_oflag = 0;
    
    
    new_attributes.c_cc[VMIN]=0; //1;
    new_attributes.c_cc[VTIME]=0;
    
    /*
    printf("tty_fd=%d\n",tty_fd);
    printf("c_cflag=%x\n",new_attributes.c_cflag);
    printf("c_iflag=%x\n",new_attributes.c_iflag);
    printf("c_lflag=%x\n",new_attributes.c_lflag);
    printf("c_oflag=%x\n",new_attributes.c_oflag);
    */
    
    if(tcsetattr(tty_fd, TCSANOW, &new_attributes)<0)
    {
    	printf("tcsetattr failed\n");
			return -1;
		}
    
    return tty_fd;
  }
}

void closeSerial(int fd)
{
	if(close(fd)<0)
		printf("close failed... ignored!\n");
}

/*envoi une octet*/
int sendSerial(int fd, uint8 data)
{
  write(fd,&data,1);
  //printf("OUT: %x\n",data);
#if SEND_WAIT_US > 0
	usleep(SEND_WAIT_US); // Attente en microsecondes
#endif
}

/*reception d'une octet*/
uint8 receiveSerial(int fd)
{
	clock_t timeout;
	timeout = clock()+RECEIVE_TIMEOUT;
  uint8 data;
  while(!read(fd,&data,1))
  {
  	usleep(1);
  	
  	if(clock() > timeout)
		{
			printf("receive timed out!\n");
			abort();
		}
  }
  //printf("IN: %x\n",data);
  return data;
}

/*vidange du buffer de réception*/
void flushRecieveBuffer(int fd)
{
	uint8 data;
	while(read(fd,&data,1)>0);
}


long selectBaud(long baudrate)
{
  long BAUD;

  switch (baudrate)
  {
      case 230400:
        BAUD  = B230400;
        break;
      case 115200:
        BAUD  = B115200;
        break;
      case 57600:
        BAUD  = B57600;
        break;
      case 38400:
        BAUD = B38400;
        break;
      case 19200:
        BAUD  = B19200;
        break;
      case 9600:
      default :
        BAUD  = B9600;
        break;
      case 4800:
        BAUD  = B4800;
        break;
      case 2400:
        BAUD  = B2400;
        break;
      case 1800:
        BAUD  = B1800;
        break;
      case 1200:
        BAUD  = B1200;
        break;
      case 600:
        BAUD  = B600;
        break;
      case 300:
        BAUD  = B300;
        break;
      case 200:
        BAUD  = B200;
        break;
      case 150:
        BAUD  = B150;
        break;
      case 134:
        BAUD  = B134;
        break;
      case 110:
        BAUD  = B110;
        break;
      case 75:
        BAUD  = B75;
        break;
      case 50:
        BAUD  = B50;
        break;
      case 0:
        BAUD  = B0;
        break;
  }  //end of switch baud_rate
  
  return BAUD;
}

long selectNDataBits(int nData)
{
  long DATABITS;

  switch (nData)
  {
      case 8:
      default:
        DATABITS = CS8;
        break;
      case 7:
        DATABITS = CS7;
        break;
      case 6:
        DATABITS = CS6;
        break;
      case 5:
        DATABITS = CS5;
        break;
  }  //end of switch data_bits

  return DATABITS;
}

long selectNStopBits(int nStop)
{
  long STOPBITS;

  switch (nStop)
  {
      case 1:
      default:
        STOPBITS = 0;
        break;
      case 2:
        STOPBITS = CSTOPB;
        break;
  }  //end of switch stop bits

  return STOPBITS;
}

ParityState selectParity(int parity)
{
  ParityState par;
  
  switch (parity)
  {
      case 0:
      default:                       //none
        par.PARITY_ON = 0;
        par.PARITY_ODD = 0;
        break;
      case 1:                        //odd
        par.PARITY_ON = PARENB;
        par.PARITY_ODD = PARODD;
        break;
      case 2:                        //even
        par.PARITY_ON = PARENB;
        par.PARITY_ODD = 0;
        break;
  }  //end of switch parity

  return par;
}





