/* ************************************************************************** */
/*                                                                            */
/*                                degringole.c                                */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

void	conv_position_win_tab(principal *donnee, int boo)
{
	int		i;
	int		surfacel;
	int		surfaceh;

	surfaceh = HAUT_WIN / donnee->jeu.taille;
	surfacel = LARG_WIN / donnee->jeu.taille;
	if (boo == 0)
	{
		for (i = 0; (i + 1) * surfacel < donnee->jeu.coordonnee1[0]; i++);
		donnee->jeu.coordonnee1[0] = i;
		for (i = 0; (i + 1) * surfaceh < donnee->jeu.coordonnee1[1]; i++);
		donnee->jeu.coordonnee1[1] = i;
	}	
	if (boo == 1)
	{
		for (i = 0; (i + 1) * surfacel < donnee->jeu.coordonnee2[0]; i++);
		donnee->jeu.coordonnee2[0] = i;
		for (i = 0; (i + 1) * surfaceh < donnee->jeu.coordonnee2[1]; i++);
		donnee->jeu.coordonnee2[1] = i;
	}
}

void	remake_tab(principal *donnee, int ligne, int colonne)
{
	int		i;

	for (i = ligne; i > 0; i--)
		donnee->jeu.grille[i][colonne] = donnee->jeu.grille[i - 1][colonne];
	donnee->jeu.grille[i][colonne] = MLV_get_random_integer(-(donnee->jeu.max), donnee->jeu.max);
}
