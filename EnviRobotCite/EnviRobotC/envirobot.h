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

#define bool char

int main();
void quit();
void usage(char *appname);

typedef void (*voidfunction) (void);
voidfunction state = NULL;

void state_search();
void state_search_base();
void state_docking();
void state_action();
void state_demo_dock();
void state_charge();
void state_undock();
void state_back();

void set_status(int id, const char* status);
char robot_status[128] = "Starting";
char robot_laststatus[128] = "Starting";

void drive_direct(int l, int r);
bool search_around();

bool loop = 1;

int low_charge = 2200; // Calculé pour 5min de charge
int high_charge = 2500; // Même remarque...
bool base_is_flower = 0;


bool bumperL = 0;
bool bumperR = 0;
int wallsignal = 0;

int lastl = 0;
int lastr = 0;

char lastrot = 1; // lastrot = 1 (gauche) ou -1 (droite)
int backstep = 0;
int demo_dock_timeout = 0;
int gobase_found = 0;
int undock_step = 0;

char action_state = 0;
int action_lenght = 0;

int sub_delay = 0;
short flower = -1;

