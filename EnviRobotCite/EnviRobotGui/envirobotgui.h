// ==================================
//  GUI EnviRobotCité (Déclarations)
// ==================================

// *********************************
// * Guillaume Genty, Octobre 2008 *
// *     Projet  EnviRobotCité     *
// * Association  Planète Sciences *
// *********************************
// guillaume.genty@planete-sciences.org
//

#include <gtk/gtk.h>

int main();
void quit();
gboolean update(gpointer data);
void usage(char *appname);

GtkWidget * MainWindow = NULL;
GtkWidget* Label1 = NULL;

