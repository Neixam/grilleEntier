/* ************************************************************************** */
/*                                                                            */
/*                                   jouer.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		test_entrer_coord(principal donnee)
{
	if ((donnee.jeu.coordonnee1[0] < 0 && donnee.jeu.coordonnee1[0] >= donnee.jeu.taille) ||
		(donnee.jeu.coordonnee1[1] < 0 && donnee.jeu.coordonnee1[1] >= donnee.jeu.taille) ||
		(donnee.jeu.coordonnee2[0] < 0 && donnee.jeu.coordonnee2[0] >= donnee.jeu.taille) ||
		(donnee.jeu.coordonnee2[1] < 0 && donnee.jeu.coordonnee2[1] >= donnee.jeu.taille))
	{
		printf("Les coordonnées saisies ne sont pas dans la grille !!\n");
		return (1);
	}
	if (!(donnee.jeu.coordonnee1[0] == donnee.jeu.coordonnee2[0] ||
		donnee.jeu.coordonnee1[1] == donnee.jeu.coordonnee2[1] ||
		donnee.jeu.coordonnee1[0] - donnee.jeu.coordonnee1[1] == donnee.jeu.coordonnee2[0] - donnee.jeu.coordonnee2[0] ||
		donnee.jeu.coordonnee1[0] + donnee.jeu.coordonnee1[1] == donnee.jeu.coordonnee2[0] + donnee.jeu.coordonnee2[1]))
	{
		printf("Les coordonnées saisies ne donnent pas un segment valide !!\n");
		return (1);
	}
	return (0);
}

void	select_ligne(principal *donnee)
{
	int		i;
	int		j;

	if (donnee->jeu.coordonnee1[0] == donnee->jeu.coordonnee2[0])
	{
		if (donnee->jeu.coordonnee1[1] > donnee->jeu.coordonnee2[1])
			echangeEntier(&(donnee->jeu.coordonnee1[1]), &(donnee->jeu.coordonnee2[1]));
		i = donnee->jeu.coordonnee1[0];
		for (j = donnee->jeu.coordonnee1[1]; j <= donnee->jeu.coordonnee2[1]; j++)
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			donnee->jeu.grille[i][j] = 0;
		}
	}
	else if (donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[1])
	{
		if (donnee->jeu.coordonnee1[0] > donnee->jeu.coordonnee2[0])
			echangeEntier(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee2[0]));
		j = donnee->jeu.coordonnee1[1];
		for (i = donnee->jeu.coordonnee1[0]; i <= donnee->jeu.coordonnee2[0]; i++)
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			donnee->jeu.grille[i][j] = 0;
		}
	}
	else if (donnee->jeu.coordonnee1[0] - donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[0] - donnee->jeu.coordonnee2[0])
	{
		i = donnee->jeu.coordonnee1[0];
		j = donnee->jeu.coordonnee1[1];
		while (i <= donnee->jeu.coordonnee2[0] && j <= donnee->jeu.coordonnee2[1])
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			donnee->jeu.grille[i][j] = 0;
			i++;
			j++;
		}
	}
	else
	{
		if (donnee->jeu.coordonnee1[0] > donnee->jeu.coordonnee2[0] ||
			donnee->jeu.coordonnee1[1] > donnee->jeu.coordonnee2[1])
		{
			echangeEntier(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee2[0]));
			echangeEntier(&(donnee->jeu.coordonnee1[1]), &(donnee->jeu.coordonnee2[1]));
		}
		i = donnee->jeu.coordonnee1[0];
		j = donnee->jeu.coordonnee1[1];
		while (i >= donnee->jeu.coordonnee2[0] && j <= donnee->jeu.coordonnee2[1])
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			donnee->jeu.grille[i][j] = 0;
			i--;
			j++;
		}
	}
}

void	joue_ASCII(principal *donnee)
{
	do
	{
		printf("Saisir les coordonnées de la première cellule : ");
		scanf("%d %d", &(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee1[1]));
		printf("Saisir les coordonnées de la seconde cellule : ");
		scanf("%d %d", &(donnee->jeu.coordonnee2[0]), &(donnee->jeu.coordonnee2[1]));
	}while (test_entrer_coord(*donnee));
	select_ligne(donnee);
}
