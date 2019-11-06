/* ************************************************************************** */
/*                                                                            */
/*                               initialisation.c                             */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

void	delete_struct(principal *donnee)
{
	int		i;

	if (donnee->entrer.fichier != NULL)
		free(donnee->entrer.fichier);
	if (donnee->fichier != NULL)
		fclose(donnee->fichier);
	if (donnee->jeu.grille != NULL)
	{
		for (i = 0; i < donnee->jeu.taille; i++)
			free(donnee->jeu.grille[i]);
		free(donnee->jeu.grille);
	}
}

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
	(nw->jeu).type_coups = 0;
	(nw->jeu).somme = 0;
	(nw->jeu).grille = NULL;
	nw->error = 0;
	nw->fichier = NULL;
	srandom(time(NULL));
}
