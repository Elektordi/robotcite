#ifndef _serialLib
#define _serialLib

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

// A adapter à la plateforme
#define uint8 unsigned char
#define int8 signed char
#define uint16 unsigned short
#define int16 signed short

/*initialise le port série et renvoi le descripteur de fichier du port choisit*/
int initSerial(char* device, long baudrate, int nData, int nStop, int parity);

//ferme le port serie
void closeSerial(int fd);

/*envoi une octet*/
int sendSerial(int fd, uint8 data);

/*reception d'une octet*/
uint8 receiveSerial(int fd);

/*vidange du buffer de réception*/
void flushRecieveBuffer(int fd);


//---------------------------------
//fonctions et variables internes :

typedef struct {
  long PARITY_ON;
  long PARITY_ODD;
} ParityState;


long selectBaud(long baudrate);
long selectNDataBits(int nData);
long selectNStopBits(int nStop);
ParityState selectParity(int parity);



#endif
