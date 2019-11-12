/* ************************************************************************** */
/*                                                                            */
/*                                 affiche.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		quitte_graphique(principal *donnee)
/* BUT    : Quitte la fenetre ainsi que le jeu tout en demandant à l'user si  */
/*          il veut sauvegarder sa partie                                     */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si la sauvegarde échoue et 0 sinon                      */
{	
	MLV_clear_window(MLV_COLOR_WHITE);
	MLV_actualise_window();
	MLV_draw_text_box(0, 0, LARG_WIN + LARG_WIN / 6, HAUT_WIN, "Voulez-vous sauvegarder avant de quitter ?", 0, MLV_COLOR_WHITE, MLV_COLOR_PURPLE, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box((LARG_WIN + LARG_WIN / 6) / 2 - 150, (HAUT_WIN / 2) + 50, 50, 50, "Oui", 0, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(((LARG_WIN + LARG_WIN / 6) / 2) + 100, (HAUT_WIN / 2) + 50, 50, 50, "Non", 0, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_actualise_window();
	do{
		MLV_wait_mouse(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee1[1]));
		if (donnee->jeu.coordonnee1[0] >= ((LARG_WIN + LARG_WIN / 6) / 2) - 150 && donnee->jeu.coordonnee1[0] < ((LARG_WIN + LARG_WIN / 6) / 2) - 100 && donnee->jeu.coordonnee1[1] >= (HAUT_WIN / 2) + 50 && donnee->jeu.coordonnee1[1] < (HAUT_WIN / 2) + 100)
		{
			if (sauvegarde_tab(donnee))
				return (1);
			return (0);
		}
		else if (donnee->jeu.coordonnee1[0] >= ((LARG_WIN + LARG_WIN / 6) / 2) + 100 && donnee->jeu.coordonnee1[0] < ((LARG_WIN + LARG_WIN / 6) / 2) + 150 && donnee->jeu.coordonnee1[1] >= (HAUT_WIN / 2) + 50 && donnee->jeu.coordonnee1[1] < (HAUT_WIN / 2) + 100)
			return (0);
	}while (1);
}

void	affiche_graphique(principal *donnee)
/* BUT   : Affiche la grille dans une fenètre graphique                       */
/* PARAM : l'adresse de la structure principale                               */
{
	int		i;
	int		j;
	float	surfacel;
	float	surfaceh;
	char	*contenu;

	surfacel = LARG_WIN / donnee->jeu.taille;
	surfaceh = HAUT_WIN / donnee->jeu.taille;
	for (i = 0; i < donnee->jeu.taille; i++)
	{
		for (j = 0; j < donnee->jeu.taille; j++)
		{
			contenu = ft_itoa(donnee->jeu.grille[i][j]);
			MLV_draw_text_box(j * surfacel, i * surfaceh, surfacel, surfaceh, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, ((i + j) % 2 == 1) ? MLV_COLOR_GREY : MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
			free(contenu);
		}
	}
	MLV_actualise_window();
}

void	put_hud(principal *donnee)
/* BUT   : Affiche le HUD dans la fenetre graphique                           */
/* PARAM : l'adresse de la structure principale                               */
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
	MLV_draw_text_box(LARG_WIN, 0, LARG_WIN / 6, HAUT_WIN / 3, contenu, 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(LARG_WIN, HAUT_WIN / 3, LARG_WIN / 6, HAUT_WIN / 3, "Sauvegarder", 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_YELLOW, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(LARG_WIN, (2 * HAUT_WIN) / 3, LARG_WIN / 6, HAUT_WIN / 3, "Quitter", 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_actualise_window();
}

int		menu_graphique(principal *donnee)
/* BUT    : Affiche le menu, et récupère les actions de l'utilsateur dans la  */
/*          fenetre graphique                                                 */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si la sauvegarde échoue et si il y a une erreur dans la */
/*          fonction fin_de_jeu_graphique sinon 0                             */
{
	MLV_create_window("grille d'entier", "grient", LARG_WIN + (LARG_WIN / 6), HAUT_WIN);
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
				select_ligne(donnee);
			MLV_wait_seconds(1);
		}
		else if (LARG_WIN <= donnee->jeu.coordonnee1[0] && donnee->jeu.coordonnee1[0] < LARG_WIN + LARG_WIN / 6)
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
/* BUT   : Affiche dans le terminal la grille du jeu                          */
/* PARAM : L'adresse de la structure principale                               */
{
	int		i;
	int		j;

	printf("somme %d coups %d\n", donnee->jeu.somme, donnee->jeu.coups);
	printf(" \\ x\t");
	for (i = 0; i < donnee->jeu.taille; i++)
		printf("% d\t", i);
	printf("\ny \\\t");
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
/* BUT    : Affiche le menu dans le terminal et récupère le choix du user     */
/* PARAM  : L'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si la sauvegarde échoue ou si uen erreur est retournée  */
/*          par la fonction fin_de_jeu_ASCII sinon 0                          */
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
/* BUT    : Appelle le menu approprié à la demande de l'utilisateur           */
/* PARAM  : L'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si une erreur lors du déroulement des fonctions appelées*/
/*          sinon 0                                                           */
{
	if (donnee->entrer.flag & 1)
		if (menu_ASCII(donnee))
			return (1);
	if (donnee->entrer.flag & 8)
		if (menu_graphique(donnee))
			return (1);
	return (0);
}
