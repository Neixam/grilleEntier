/* ************************************************************************** */
/*                                                                            */
/*                                 ft_base.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

void	affiche_graphique(principal *donnee);

void	affiche_ASCII(principal *donnee)
{
	int		i;
	int		j;

	printf("somme %d coups %d\n", donnee->jeu.somme, donnee->jeu.coups);
	printf("\t");
	for (i = 0; i < donnee->jeu.taille; i++)
		printf("% d\t", i);
	printf("\n\t");
	for (i = 0; i < donnee->jeu.taille; i++)
		printf("********");
	for (i = 0; i < donnee->jeu.taille; i++)
	{
		printf("\n%d   *\t", i);
		for (j = 0; j < donnee->jeu.taille; j++)
			printf("%d\t", donnee->jeu.grille[i][j]);
	}
	printf("\n");
}

void	affiche_menu(principal *donnee)
{
	if (donnee->entrer.flag & 1)
		affiche_ASCII(donnee);
/*	if (donnee->entrer.flag & 8)
		affiche_graphique(donnee);
*/
}
