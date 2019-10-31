/* ************************************************************************** */
/*                                                                            */
/*                               initialisation.c                             */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

void	initialisation(principal *nw)
/* BUT    : Initialise la structure principal du programme                    */
/* PARAM  : L'adresse de la structure principal pour la pouvoir la modifier   */
/* RETOUR : Aucun retour car aucune erreur possible dans le déroulement de    */
/*          cette fonction et une modification par adresse                    */
{
	(nw->entrer).flag = 0;
	(nw->entrer).fichier = NULL;
	(nw->entrer).nb_flag = 0;
	(nw->jeu).max = 0;
	(nw->jeu).taille = 0;
	(nw->jeu).coups = 0;
	(nw->jeu).somme = 0;
	(nw->jeu).grille = NULL;
	nw->error = 0;
	nw->seed = srandom(time(NULL));
	nw->fichier = NULL;
}
