/* ************************************************************************** */
/*                                                                            */
/*                                 ft_base.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		quitte_graphique(principal *donnee)
{
	return (0);
}

void	affiche_graphique(principal *donnee)
{
	int		i;
	int		j;
	int		surfacel;
	int		surfaceh;
	char	*contenu;

	surfacel = LARG_WIN / donnee->jeu.taille;
	surfaceh = HAUT_WIN / donnee->jeu.taille;
	contenu = NULL;
	for (i = 0; i < donnee->jeu.taille; i++)
	{
		for (j = 0; j < donnee->jeu.taille; j++)
		{
			if (contenu == NULL)
				contenu = ft_itoa(donnee->jeu.grille[i][j]);
			MLV_draw_text_box(j * surfacel, i * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, ((i + j) % 2 == 1) ? MLV_COLOR_GREY : MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
			contenu = NULL;
		}
	}
	MLV_actualise_window();
}

void	put_hud(principal *donnee)
{
	char	*contenu;
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(donnee->jeu.coups);
	contenu = ft_itoa(donnee->jeu.somme);
	tmp2 = ft_itoa(BUT);
	contenu = ft_strjoin("\nSomme obtenu : ", contenu, 2);
	tmp = ft_strjoin("\nCoups effectués : ", tmp, 2);
	tmp2 = ft_strjoin("Objectif : ", tmp2, 2);
	contenu = ft_strjoin(contenu, tmp, 3);
	contenu = ft_strjoin(tmp2, contenu, 3);
	MLV_draw_text_box(LARG_WIN, 0, 200, HAUT_WIN / 3, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(LARG_WIN, HAUT_WIN / 3, 200, HAUT_WIN / 3, "Sauvegarder", 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_YELLOW, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(LARG_WIN, (2 * HAUT_WIN) / 3, 200, HAUT_WIN / 3, "Quitter", 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_actualise_window();
}

int		menu_graphique(principal *donnee)
{
	MLV_create_window("grille d'entier", "grient", LARG_WIN + 200, HAUT_WIN);
	do
	{
		put_hud(donnee);
		affiche_graphique(donnee);
		MLV_wait_mouse(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee1[1]));
		if (donnee->jeu.coordonnee1[0] >= 0 && donnee->jeu.coordonnee1[0] < LARG_WIN && donnee->jeu.coordonnee1[1] < HAUT_WIN && donnee->jeu.coordonnee1[1] >= 0)
		{
			conv_position_win_tab(donnee, 0);
			select_case(donnee, donnee->jeu.coordonnee1[0], donnee->jeu.coordonnee1[1], donnee->jeu.taille);
			do{
				MLV_wait_mouse(&(donnee->jeu.coordonnee2[0]), &(donnee->jeu.coordonnee2[1]));
			}while (!(donnee->jeu.coordonnee2[0] >= 0 && donnee->jeu.coordonnee2[0] < LARG_WIN && donnee->jeu.coordonnee2[1] < HAUT_WIN && donnee->jeu.coordonnee2[1] >= 0));
			conv_position_win_tab(donnee, 1);
			select_case(donnee, donnee->jeu.coordonnee2[0], donnee->jeu.coordonnee2[1], donnee->jeu.taille);
			if (test_entrer_coord(donnee) == 0)
			{
				select_ligne(donnee);
				MLV_wait_seconds(2);
			}
		}
		else if (LARG_WIN <= donnee->jeu.coordonnee1[0] && donnee->jeu.coordonnee1[0] < LARG_WIN + 200)
		{
			if (donnee->jeu.coordonnee1[1] >= HAUT_WIN / 3 && donnee->jeu.coordonnee1[1] < (2 * HAUT_WIN) / 3)
			{
				if (sauvegarde_tab(donnee))
					return (1);
			}
			else if (donnee->jeu.coordonnee1[1] >= 2 * HAUT_WIN / 3 && donnee->jeu.coordonnee1[1] < HAUT_WIN)
				return (quitte_graphique(donnee));
		}
	}while (donnee->jeu.somme != BUT);
	return (fin_de_jeu_graphique(donnee));
}

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

int		menu_ASCII(principal *donnee)
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
			case 's' : if (sauvegarde_tab(donnee)){return (1);} break;
			case 'q' : break;
			default : printf("Saisi non valide\n");
		}
		if (donnee->jeu.somme == BUT)
			return (fin_de_jeu_ASCII(donnee));
	}while (choix != 'q');
	printf("Voulez-vous sauvegarder votre partie avant ? ");
	do{
		printf("(o/n) ");
		scanf(" %c", &choix);
		switch (choix)
 		{
			case 'o' : return (sauvegarde_tab(donnee));
			case 'n' : return (0);
			default : printf("Saisi non valide\n");
		}
	}while (1);
}

int		affiche_menu(principal *donnee)
{
	if (donnee->entrer.flag & 1)
		if (menu_ASCII(donnee))
			return (1);
	if (donnee->entrer.flag & 8)
		if (menu_graphique(donnee))
			return (1);

	return (0);
}
