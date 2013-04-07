#ifndef _serialLib
#define _serialLib

#include <stdio.h>
#include <string.h>

#ifndef WIN32
	#include <unistd.h>
	#include <termios.h>
#endif

#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>

#define uint8 unsigned char

/*initialise le port série et renvoi le descripteur de fichier du port choisit*/
int initSerial(char* device, long baudrate, int nData, int nStop, int parity);

/*envoi une octet*/
int sendSerial(int fd, uint8 data);

/*reception d'une octet*/
uint8 receiveSerial(int fd);

/*vidange du buffer de réception*/
void flushRecieveBuffer(int fd);


//---------------------------------
//fonctions et variables internes :
#ifndef WIN32
	struct termios tty_saved_attributes;
#endif

typedef struct {
  long PARITY_ON;
  long PARITY_ODD;
} ParityState;


long selectBaud(long baudrate);
long selectNDataBits(int nData);
long selectNStopBits(int nStop);
ParityState selectParity(int parity);



#endif
