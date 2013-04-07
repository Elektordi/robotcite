// ========================================
//  Logique EnviRobotCité (Interprocessus)
// ========================================

// *********************************
// * Guillaume Genty, Octobre 2008 *
// *     Projet  EnviRobotCité     *
// * Association  Planète Sciences *
// *********************************
// guillaume.genty@planete-sciences.org
//

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#ifndef __bool_true_false_are_defined
#define bool char
#endif

#define NB_PLANTES 5

int shm_key = 1962; // Création de Planète Sciences :)

typedef struct {
	bool alive; // 1 si le master tourne, 0 sinon 
	char status[128]; // Chaine qui contient en texte l'êtat du robot
	char id_status; // Identificateur d'êtat. ( Cf. envirobot.c, chercher "set_status(" )
	short Battery; // Batterie en 100èmes de volts
	bool ManualControl; // Contrôle manuel oui/non
	short vl,vr; // Vitesse des roues en controle manuel
	short level_w[NB_PLANTES]; // Contenu en eau des fleurs (0-100)
	short level_p[NB_PLANTES]; // Contenu en P des fleurs (0-100)
	short level_n[NB_PLANTES]; // Contenu en N des fleurs (0-100)
	short level_k[NB_PLANTES]; // Contenu en K des fleurs (0-100)
	char plante_a_portee; // ID de la plante à portée
} erc_shared;

erc_shared *ERC;

void init_erc_shared()
{
	ERC->alive = 0; // Passé à 1 quand le process maitre est prêt
	strcpy(ERC->status,"");
	ERC->id_status = -1;
	ERC->Battery = 0;
	ERC->ManualControl = 0;
	ERC->vl = 0;
	ERC->vr = 0;
	ERC->plante_a_portee = -1;
	
	int i;
	for(i=0;i<NB_PLANTES;i++)
	{
		ERC->level_w[i]=100;
		ERC->level_p[i]=100;
		ERC->level_n[i]=100;
		ERC->level_k[i]=100;
	}
	
}

void shm_master()
{
	int mem_ID; // identificateur du segment de mémoire partagée
	void* ptr_mem_partagee; // pointeur sur l'adresse d'attachement du segment de mémoire partagée
	
	if ((mem_ID = shmget(shm_key, sizeof(ERC), 0666 | IPC_CREAT)) < 0) // je crée un nouveau segment mémoire de taille "taille de ma structure data" octets, avec des droits d'écriture et de lecture
	{
		// et je m'assure que l'espace mémoire a été correctement créé
		printf("Shared memory create failed!\n");
		abort();
	}

	if ((ptr_mem_partagee = shmat(mem_ID, NULL, 0)) == (void*) -1) // J'attache le segment de mémoire partagée identifié par mem_ID au segment de données du processus dans une zone libre déterminée par le Système d'exploitation
	{
		// et je m'assure que le segment de mémoire a été correctement attaché à mon processus
		printf("Shared memory attach failed!\n");
		abort();
	}
	
	ERC = ptr_mem_partagee;
}

void shm_slave()
{
	int mem_ID; // identificateur du segment de mémoire partagée
	void* ptr_mem_partagee; // pointeur sur l'adresse d'attachement du segment de mémoire partagée
	
	if ((mem_ID = shmget(shm_key, sizeof(ERC), 0666)) < 0) // Je cherche le segment mémoire associé et je récupère l'identificateur de ce segment mémoire... J'attribue des droits de lecture uniquement
	{
		// et je m'assure que l'espace mémoire a été trouvé
		printf("Shared memory get failed!\n");
		abort();
	}

	if ((ptr_mem_partagee = shmat(mem_ID, NULL, 0)) == (void*) -1) // J'attache le segment de mémoire partagée identifié par mem_ID au segment de données du processus dans une zone libre déterminée par le Système d'exploitation
	{
		// et je m'assure que le segment de mémoire a été correctement attaché à mon processus
		printf("Shared memory attach failed!\n");
		abort();
	}
	
	ERC = ptr_mem_partagee;
}

void shm_leave()
{
	shmdt(ERC);
}
