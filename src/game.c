/* ************************************************************************** */
/*                                                                            */
/*                                   game.c                                   */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		creat_grille(principal *donnee)
{
	int		i;
	int		j;

	if ((donnee->jeu.grille = (int**)malloc(sizeof(int*) * donnee->jeu.taille)) == NULL)
		return (1);
	for (i = 0; i < donnee->jeu.taille; i++)
	{
		if ((donnee->jeu.grille[i] = (int*)malloc(sizeof(int) * donnee->jeu.taille)) == NULL)
			return (1);

		for (j = 0; j < donnee->jeu.taille; j++)
		{
			if (donnee->entrer.flag & 4)
				fscanf(donnee->fichier, "%d", &(donnee->jeu.grille[i][j]));
			if (donnee->entrer.flag & 2)
				donnee->jeu.grille[i][j] = initAlea(donnee->jeu.max);
		}
	}
	return (0);
}

int		read_grille(principal *donnee)
{
	if ((donnee->fichier = fopen(donnee->entrer.fichier, "r")) == NULL)
		return (1);
	fscanf(donnee->fichier, "%d", &(donnee->jeu.taille));
	fscanf(donnee->fichier, "%d %d %d", &(donnee->jeu.somme), &(donnee->jeu.coups), &(donnee->jeu.max));
	if (creat_grille(donnee))
		return (1);
	return (0);
}

int		not_read_grille(principal *donnee)
{
	printf("Entrer la taille du tableau\n");
	scanborne(&(donnee->jeu.taille), 0, 20);
	printf("Entrer la valeur max\n");
	scanborne(&(donnee->jeu.max), 0, VAL_MAX);
	if (creat_grille(donnee))
		return (1);
	return (0);
}

int		start_game(principal *donnee)
{
	if (donnee->entrer.flag & 2)
		if (not_read_grille(donnee))
			return (-1);
	if (donnee->entrer.flag & 4)
		if (read_grille(donnee))
			return (-2);
/*	donnee->fichier = fopen(donnee->entrer.fichier, "w+");*/
	affiche_menu(donnee);
	return (2);
}
