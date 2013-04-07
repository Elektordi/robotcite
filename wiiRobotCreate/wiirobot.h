// ======================================
//  Logique EnviRobotCité (Déclarations)
// ======================================

// *********************************
// * Guillaume Genty, Octobre 2008 *
// *     Projet  EnviRobotCité     *
// * Association  Planète Sciences *
// *********************************
// guillaume.genty@planete-sciences.org
//

#include "../iCreateLib/iCreateLib.h"
#include <cwiid.h>

#define bool char

int main();
void quit();
void usage(char *appname);

void wmconnect(char *bta);

void drive(int speed, int dir);
void drive_direct(short l, short r);

cwiid_wiimote_t *wiimote;	/* wiimote handle */
bdaddr_t bdaddr;	/* bluetooth device address */

bool debug = 0;

short lastl = 0;
short lastr = 0;
