/* ************************************************************************** */
/*                                                                            */
/*                                   jouer.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		test_entrer_coord(principal *donnee)
{
	char	*contenu;
	float	surfaceh;
	float	surfacel;

	
	surfaceh = HAUT_WIN / donnee->jeu.taille;
	surfacel = LARG_WIN / donnee->jeu.taille;
	if ((donnee->jeu.coordonnee1[0] < 0 || donnee->jeu.coordonnee1[0] >= donnee->jeu.taille) ||
		(donnee->jeu.coordonnee1[1] < 0 || donnee->jeu.coordonnee1[1] >= donnee->jeu.taille) ||
		(donnee->jeu.coordonnee2[0] < 0 || donnee->jeu.coordonnee2[0] >= donnee->jeu.taille) ||
		(donnee->jeu.coordonnee2[1] < 0 || donnee->jeu.coordonnee2[1] >= donnee->jeu.taille))
	{
		if (donnee->entrer.flag & 1)
			printf("Les coordonnées saisies ne sont pas dans la grille !!\n");
		else if (donnee->entrer.flag & 8)
		{
			contenu = ft_itoa(donnee->jeu.grille[donnee->jeu.coordonnee1[1]][donnee->jeu.coordonnee1[0]]);
			MLV_draw_text_box(donnee->jeu.coordonnee1[0] * surfacel, donnee->jeu.coordonnee1[1] * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			contenu = ft_itoa(donnee->jeu.grille[donnee->jeu.coordonnee2[1]][donnee->jeu.coordonnee2[0]]);
			MLV_draw_text_box(donnee->jeu.coordonnee2[0] * surfacel, donnee->jeu.coordonnee2[1] * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			MLV_actualise_window();
		}
		return (1);
	}
	if (!(donnee->jeu.coordonnee1[0] == donnee->jeu.coordonnee2[0] ||
		donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[1] ||
		donnee->jeu.coordonnee1[0] - donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[0] - donnee->jeu.coordonnee2[1] ||
		donnee->jeu.coordonnee1[0] + donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[0] + donnee->jeu.coordonnee2[1]))
	{
		if (donnee->entrer.flag & 1)
			printf("Les coordonnées saisies ne donnent pas un segment valide !!\n");
		else if (donnee->entrer.flag & 8)
		{
			contenu = ft_itoa(donnee->jeu.grille[donnee->jeu.coordonnee1[1]][donnee->jeu.coordonnee1[0]]);
			MLV_draw_text_box(donnee->jeu.coordonnee1[0] * surfacel, donnee->jeu.coordonnee1[1] * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			contenu = ft_itoa(donnee->jeu.grille[donnee->jeu.coordonnee2[1]][donnee->jeu.coordonnee2[0]]);
			MLV_draw_text_box(donnee->jeu.coordonnee2[0] * surfacel, donnee->jeu.coordonnee2[1] * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			MLV_actualise_window();
		}
		return (1);
	}
	if (donnee->jeu.coordonnee1[0] == donnee->jeu.coordonnee2[0] &&
		donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[1])
	{
		if (donnee->entrer.flag & 1)
			printf("Les coordonnées saisies ne donnent pas un segment valide !!\n");
		else if (donnee->entrer.flag & 8)
		{
			contenu = ft_itoa(donnee->jeu.grille[donnee->jeu.coordonnee1[1]][donnee->jeu.coordonnee1[0]]);
			MLV_draw_text_box(donnee->jeu.coordonnee1[0] * surfacel, donnee->jeu.coordonnee1[1] * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			contenu = ft_itoa(donnee->jeu.grille[donnee->jeu.coordonnee2[1]][donnee->jeu.coordonnee2[0]]);
			MLV_draw_text_box(donnee->jeu.coordonnee2[0] * surfacel, donnee->jeu.coordonnee2[1] * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			MLV_actualise_window();
		}
		return (1);
	}
	return (0);
}

void	select_case(principal *donnee, int x, int y, int taille)
{
	float	surfacel;
	float	surfaceh;
	char	*contenu;

	surfacel = LARG_WIN / taille;
	surfaceh = HAUT_WIN / taille;
	contenu = ft_itoa(donnee->jeu.grille[y][x]);
	MLV_draw_text_box(x * surfacel, y * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLUE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	free(contenu);
	MLV_actualise_window();
}

void	select_ligne(principal *donnee)
{
	int		i;
	int		j;

	if (donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[1])
	{
		if (donnee->jeu.coordonnee1[0] > donnee->jeu.coordonnee2[0])
			echangeEntier(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee2[0]));
		i = donnee->jeu.coordonnee1[1];
		for (j = donnee->jeu.coordonnee1[0]; j <= donnee->jeu.coordonnee2[0]; j++)
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			if (donnee->entrer.flag & 8)
				select_case(donnee, j, i, donnee->jeu.taille);
			remake_tab(donnee, i, j);
		}
	}
	else if (donnee->jeu.coordonnee1[0] == donnee->jeu.coordonnee2[0])
	{
		if (donnee->jeu.coordonnee1[1] > donnee->jeu.coordonnee2[1])
			echangeEntier(&(donnee->jeu.coordonnee1[1]), &(donnee->jeu.coordonnee2[1]));
		j = donnee->jeu.coordonnee1[0];
		for (i = donnee->jeu.coordonnee1[1]; i <= donnee->jeu.coordonnee2[1]; i++)
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			if (donnee->entrer.flag & 8)
				select_case(donnee, j, i, donnee->jeu.taille);
			remake_tab(donnee, i, j);
		}
	}
	else if (donnee->jeu.coordonnee1[0] - donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[0] - donnee->jeu.coordonnee2[1])
	{
		i = donnee->jeu.coordonnee1[1];
		j = donnee->jeu.coordonnee1[0];
		while (i <= donnee->jeu.coordonnee2[1] && j <= donnee->jeu.coordonnee2[0])
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			if (donnee->entrer.flag & 8)
				select_case(donnee, j, i, donnee->jeu.taille);
			remake_tab(donnee, i, j);
			i++;
			j++;
		}
	}
	else if (donnee->jeu.coordonnee1[0] + donnee->jeu.coordonnee1[1] == donnee->jeu.coordonnee2[0] + donnee->jeu.coordonnee2[1])
	{
		if (donnee->jeu.coordonnee1[0] > donnee->jeu.coordonnee2[0])
			echangeEntier(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee2[0]));
		if (donnee->jeu.coordonnee1[1] < donnee->jeu.coordonnee2[1])
			echangeEntier(&(donnee->jeu.coordonnee1[1]), &(donnee->jeu.coordonnee2[1]));
		i = donnee->jeu.coordonnee1[1];
		j = donnee->jeu.coordonnee1[0];
		while (i >= donnee->jeu.coordonnee2[1] && j <= donnee->jeu.coordonnee2[0])
		{
			donnee->jeu.somme += donnee->jeu.grille[i][j];
			if (donnee->entrer.flag & 8)
				select_case(donnee, j, i, donnee->jeu.taille);
			remake_tab(donnee, i, j);
			i--;
			j++;
		}
	}
	donnee->jeu.coups++;
}

void	joue_ASCII(principal *donnee)
{
	do
	{
		printf("Saisir les coordonnées de la première cellule (x, y) : ");
		scanf("%d %d", &(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee1[1]));
		printf("Saisir les coordonnées de la seconde cellule (x, y) : ");
		scanf("%d %d", &(donnee->jeu.coordonnee2[0]), &(donnee->jeu.coordonnee2[1]));
	}while (test_entrer_coord(donnee));
	select_ligne(donnee);
}
