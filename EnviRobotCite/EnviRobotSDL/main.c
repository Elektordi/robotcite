/* Note de l'auteur : Code écrit en 2008 par Yves Quemener 
** avec l'aide de Guillaume Genty, pour Planète Sciences 
** et le projet Robotcité. Les membres de Planète Science 
** peuvent l'utiliser et le modifier exactement comme ils 
** le souhaitent. Pour toute autre personne, la licence 
** applicable est la GPLv2.
** Bon courage si quelqu'un le réutilise. Mon email est 
** quemener.yves@free.fr pour toute demande de renseignement.
*/


// Pré-requis : SDL, SDL_Image et SDL_ttf

#define bool char
#define COULEUR_FOND 0x00778877

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_timer.h"
#include <math.h>
#include "../EnviRobotC/envirobot_shm.h"

SDL_Surface *screen;	//This pointer will reference the backbuffer
SDL_Surface *image[17];
TTF_Font * generalFont;
TTF_Font * miniFont;
Uint32 timerOeil, timerCligne, timerArrosoir;
Uint32 timerScanner=-1;
int cligneEtat=2;
	// 2 : regarde normalement (8 sec)
	// 3 : clignement, oeil demi fermé (40 ms)
	// 4 : clignement, oeil fermé (40 ms)

int arrosoirEtat=1;
	// 0 : invisible
	// 1 : droit (500 ms)
	// 2 : penché (500 ms)
int oeilDirection=1;
	// 0 : regarde en haut à droite de temps en temps
	// 1 : regarde en bas à droite de temps en temps
	// 2 : regarde tout droit tout le temps

int oeilEtat=2;

int fullscreen = SDL_FULLSCREEN; // Basculé à 0 si fenêtré

void init_graphics()
{
	//We must first initialize the SDL video component, and check for success
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		exit(0);
	}
	
	//When this program exits, SDL_Quit must be called
	atexit(SDL_Quit);
	
	if(fullscreen)
		screen = SDL_SetVideoMode(1024, 768, 32, SDL_DOUBLEBUF | fullscreen);
	else
		screen = SDL_SetVideoMode(1024, 768, 32, SDL_DOUBLEBUF);
	if (screen == NULL) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		exit(0);
	}
	image[0] = IMG_Load("images/oeil1.png");
	image[1] = IMG_Load("images/oeil2.png");
	image[2] = IMG_Load("images/oeil3.png");
	image[3] = IMG_Load("images/oeil4.png");
	image[4] = IMG_Load("images/oeil5.png");
	image[5] = IMG_Load("images/oeil6.png");
	image[6] = IMG_Load("images/bulles.png");
	image[7] = IMG_Load("images/eclair.png");
	image[8] = IMG_Load("images/arrosoir1.png");
	image[9] = IMG_Load("images/arrosoir2.png");
	image[10] = IMG_Load("images/engraisK.png");
	image[11] = IMG_Load("images/engraisN.png");
	image[12] = IMG_Load("images/engraisP.png");
	image[13] = IMG_Load("images/pile.png");
	image[14] = IMG_Load("images/plants.png");
	image[15] = IMG_Load("images/ledOff.png");
	image[16] = IMG_Load("images/ledOn.png");
	
	TTF_Init();
	generalFont=TTF_OpenFont("Times_New_Roman_Bold.ttf", 36);
	miniFont=TTF_OpenFont("Times_New_Roman_Bold.ttf", 12);
	if(!generalFont) printf("TTF_OpenFont: %s\n", TTF_GetError());
	if(!miniFont) printf("TTF_OpenFont: %s\n", TTF_GetError());
}

void scanner()
{
	int numleds=8;
	int i;
	float angle;
	SDL_Rect r;
	int centerx,centery,rayon;
	Uint32 now = SDL_GetTicks();
	SDL_Surface * texts;
	SDL_Rect dest;
	SDL_Color color={0,0,0}, bgcolor={0xff,0xff,0xff};
	
	centerx=450;
	centery=550;
	rayon=50;
	
	if(timerScanner==-1)
	{
		timerScanner=now;
	}
	
	
	
	for(i=0;i<numleds;i++)
	{
		angle = i *3.14159*2.0/numleds;
		r.x=centerx+cos(angle)*rayon;
		r.y=centery+sin(angle)*rayon;
		if((now-timerScanner)<3000)
		{
			//chenillard
			if(i==((int)(now/(1000.0/numleds)))%numleds)
				SDL_BlitSurface(image[16], 0, screen, &r);
			else
				SDL_BlitSurface(image[15], 0, screen, &r);
		}
		else if((now-timerScanner)<4000)
		{
			//Tous clignotent
			texts = TTF_RenderUTF8_Blended(generalFont, "OK", color);
			dest.x=centerx-texts->w/2;
			dest.y=centery-texts->h/2;
			SDL_BlitSurface(texts, 0, screen, &dest);

			if((now/200)%2==0)
				SDL_BlitSurface(image[16], 0, screen, &r);
			else
				SDL_BlitSurface(image[15], 0, screen, &r);
		}
	}
	
}
		
void eyes()
{
	SDL_Rect dest;
	Uint32 now = SDL_GetTicks();
	dest.x=100;
	dest.y=500;

	if (oeilEtat==5) //repos
	{
		SDL_BlitSurface(image[oeilEtat], 0, screen, &dest);
		return;
	}

	if((cligneEtat==2)&&(now-timerCligne>5000))
	{
		cligneEtat=3;
		timerCligne=now;
	}
	if((cligneEtat==3)&&(now-timerCligne>40))
	{
		cligneEtat=4;
		timerCligne=now;
	}
	if((cligneEtat==4)&&(now-timerCligne>40))
	{
		cligneEtat=2;
		timerCligne=now;
	}
	if((oeilEtat==2)&&(now-timerOeil>3000))
	{
		oeilEtat=oeilDirection;
		timerOeil=now;
	}
	if((oeilEtat!=2)&&(now-timerOeil>3000))
	{
		oeilEtat=2;
		timerOeil=now;
	}
	if (oeilEtat==2)
		SDL_BlitSurface(image[cligneEtat], 0, screen, &dest);
	else
		SDL_BlitSurface(image[oeilEtat], 0, screen, &dest);

}

void bulle(char * texte, char * texte2, char * texte3)
{
	SDL_Rect dest;
	//Bulles
	dest.x=250;
	dest.y=150;
	SDL_BlitSurface(image[6], 0, screen, &dest);
	SDL_Surface * texts;
	SDL_Color color={0,0,0}, bgcolor={0xff,0xff,0xff};
	texts = TTF_RenderUTF8_Shaded(generalFont, texte, color, bgcolor);
	dest.x=400;
	dest.y=200;
	SDL_BlitSurface(texts, 0, screen, &dest);
	
	if(texte2!=0)
	{
	texts = TTF_RenderUTF8_Shaded(generalFont, texte2, color, bgcolor);
	dest.x=350;
	dest.y=245;
	SDL_BlitSurface(texts, 0, screen, &dest);
	}
	if(texte3!=0)
	{
	texts = TTF_RenderUTF8_Shaded(generalFont, texte3, color, bgcolor);
	dest.x=350;
	dest.y=290;
	SDL_BlitSurface(texts, 0, screen, &dest);
	}	

}

void engraisK()
{
	SDL_Rect dest;
	dest.x=520;
	dest.y=460;
	SDL_BlitSurface(image[10], 0, screen, &dest);
}

void engraisN()
{
	SDL_Rect dest;
	dest.x=435;
	dest.y=460;
	SDL_BlitSurface(image[11], 0, screen, &dest);
}

void engraisP()
{
	SDL_Rect dest;
	dest.x=350;
	dest.y=460;
	SDL_BlitSurface(image[12], 0, screen, &dest);
}

void pile()
{
	int longueur = 40*(ERC->Battery-2000)/700.0;
	if(longueur<1) longueur=1;
	SDL_Rect dest;
	//Pile
	dest.x=300;
	dest.y=600;
	SDL_BlitSurface(image[13], 0, screen, &dest);
	dest.x=307;
	dest.y=655-longueur;
	dest.w=5;
	dest.h=longueur;
	SDL_FillRect(screen, &dest, 0x00FF0000);
}

void eclair()
{
	SDL_Rect dest;
	dest.x=314;
	dest.y=440;
	SDL_BlitSurface(image[7], 0, screen, &dest);
}

void arrosoir()
{
	int index;
	SDL_Rect dest;
	Uint32 now = SDL_GetTicks();

	if((arrosoirEtat==1)&&(now-timerArrosoir > 500))
	{
		arrosoirEtat=2;
		timerArrosoir=now;
	}
	if((arrosoirEtat==2)&&(now-timerArrosoir > 500))
	{
		arrosoirEtat=1;
		timerArrosoir=now;
	}
	
	if(arrosoirEtat==1)
	{
		SDL_Rect dest;
		dest.x=314;
		dest.y=460;
		SDL_BlitSurface(image[8], 0, screen, &dest);
	}
	if(arrosoirEtat==2)
	{
		SDL_Rect dest;
		dest.x=314;
		dest.y=440;
		SDL_BlitSurface(image[9], 0, screen, &dest);
	}
}


void iconePlante()
{
}

void plantsStats()
{
	int i, selectionnee;
	selectionnee = ERC->plante_a_portee;

	SDL_Surface * texts;
	for(i=0;i<4;i++)
	{
		SDL_Rect r;
		if(i==selectionnee)
		{
			// Si c'est la plante selectionnee, on fait un cadre
			r.h=50;
			r.x=800;
			r.y=385+i*40;
			r.w=205;
			SDL_FillRect(screen, &r, 0x00FF0000);
			r.x++;r.y++;r.h-=2;r.w-=2;
			SDL_FillRect(screen, &r, COULEUR_FOND);
		}
			
		// Nom de la plante
		char s[128];
		sprintf(s,"Plante n°%d",i+1);
		SDL_Color color={0,0,0}, bgcolor={0xff,0xff,0xff};
		texts = TTF_RenderUTF8_Blended(miniFont, s, color);
		r.h=4;
		r.y=400+i*40;
		r.x=820;
		SDL_BlitSurface(texts, 0, screen, &r);

		
		// Eau
		r.h=4;
		r.x=900;
		r.y=400+i*40;
		r.w=(int)(ERC->level_w[i])+1;
		SDL_FillRect(screen, &r, 0x000000FF);
		
		// Engrais
		r.h=4;
		r.x=900;
		r.y=404+i*40;
		r.w=(int)(ERC->level_p[i])+1;
		SDL_FillRect(screen, &r, 0x00007700);
		r.h=4;
		r.x=900;
		r.y=408+i*40;
		r.w=(int)(ERC->level_n[i])+1;
		SDL_FillRect(screen, &r, 0x0000AA00);
		r.h=4;
		r.x=900;
		r.y=412+i*40;
		r.w=(int)(ERC->level_k[i])+1;
		SDL_FillRect(screen, &r, 0x0000FF00);
	}
}


void display()
{
	char s[128];

	SDL_FillRect(screen, 0, COULEUR_FOND);
	plantsStats();
	eyes();
	pile();

	oeilDirection = 0;
	switch(ERC->id_status)
	{
		case 0:
			bulle("J'obéis à la","télécommande","");
			break;
		case 1:
			bulle("","Je cherche une plante","");
			iconePlante();
			break;
		case 2:
			bulle("Batterie faible !","Je cherche","ma base");
			oeilDirection = 1;
			break;
		case 3:
			bulle("Je suis coincé !","Peut être qu'en","reculant...");
			break;
		case 4:
			bulle("Et hop !","Je me branche","");
			break;
		case 5:
			bulle("Zzzzz","","(chut, je me recharge)");
			oeilEtat=5;
			break;
		case 6:
			bulle("","Fleur repérée","");
			break;
		case 7:
			bulle("","Et c'est reparti !","");
			oeilEtat =2;
			timerScanner=-1;
			break;
		case 10:
			bulle("","J'analyse le sol","");
			scanner();
			break;
		case 11:
			bulle("Je verse","la quantité exacte d'eau","");
			arrosoir();
			break;
		case 12:
			bulle("","Un peu de phosophore,","point trop n'en faut");
			engraisP();
			break;
		case 13:
			bulle("","Un peu de nitrate,","mais juste ce qu'il faut !");
			engraisN();
			break;
		case 14:
			bulle("","Un peu de potassium","ni trop, ni trop peu");
			engraisK();
			break;
	}
	
	//bulle("Engrais KNP, ","le petit déjeuner", "des champions :)");
	
	/*engraisK();
	engraisN();
	engraisP();
	
	arrosoir(arrosoirEtat);
	eclair();*/

	SDL_Flip(screen);
}

void usage(char* appname)
{
	printf("*** EnviRobotSDL v1 ***\n");
	printf("Yves Quemener - Planète Sciences\n");
	printf("<quemener.yves@free.fr>\n");
	printf("\n");
	printf("Usage: %s\n",appname);
	printf("	-h | -V       Display this help & version\n");
	printf("	-k <key>      Shared Memory Key (def: 1962)\n");
	printf("	-w            Windowed mode (def: Fullscreen)\n");
	printf("\n");
}

int main(int argc, char *args[])
{
	if(argc>1)
	{
		int arg=1;

		while(arg<argc)
		{		
			if(args[arg][0]!='-' || strlen(args[arg])!=2) // "-x" = 2 chars
			{
				printf("Bad argument: %s\nRun %s -h for help...\n",args[arg],args[0]);
				return;
			}
		
			switch(args[arg][1])
			{
				case 'h':
				case 'V':
					usage(args[0]);
					return;
	
				case 'k':
					if(arg+1<argc)
						shm_key = atoi(args[arg+1]);
					arg+=2;
					break;
					
				case 'w':
					fullscreen = 0;
					arg++;
					break;
					
				default:
					printf("Unknow argument -%c\nRun %s -h for help...\n",args[arg][1],args[0]);
					return;
			}
		}
	}

	SDL_Event event;
	int running=1;
	int d=0;
	
	shm_slave();
	
	timerCligne = SDL_GetTicks();
	timerOeil = SDL_GetTicks();
	timerArrosoir = SDL_GetTicks();
	
	init_graphics();
	while((running)&&(ERC->alive))
	{
		display();
		while(SDL_PollEvent(&event)) {
			switch(event.type){
				case SDL_KEYDOWN:
				case SDL_KEYUP:
					if((event.key.keysym.sym==SDLK_q)||(event.key.keysym.sym==SDLK_ESCAPE))
						running=0;
					break;
				case SDL_QUIT:
					running = 0;
					break;
			}
		}
	}
	
	SDL_Quit();
	shm_leave();
}
