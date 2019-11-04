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

void	menu_ASCII(principal *donnee)
{
	char	choix;

	do
	{
		affiche_ASCII(donnee);
		printf("Que voulez-vous faire : 'c' pour continuer, 's' pour sauvegarder et 'q' pour quitter\n");
		scanf(" %c", &choix);
		switch (choix)
		{
			case 'c' : joue_ASCII(donnee); break;
			case 's' : /*sauvegarde_tab(donnee)*/; break;
			case 'q' : break;
			default : printf("Saisi non valide\n");
		}
		/*if (donnee->jeu.somme == BUT)
			return (fin_de_jeu_ASCII(donnee));*/
	}while (choix != 'q');
	printf("Voulez-vous sauvegarder votre partie avant ?\n");
}

void	affiche_menu(principal *donnee)
{
	if (donnee->entrer.flag & 1)
		menu_ASCII(donnee);
/*	if (donnee->entrer.flag & 8)
		affiche_graphique(donnee);
*/
}
