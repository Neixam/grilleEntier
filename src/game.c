/* ************************************************************************** */
/*                                                                            */
/*                                   game.c                                   */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		sauvegarde_score(grille partie)
{
	FILE	*score;
	char	lettre;
	char	*nom;
	int 	i;

	if ((score = fopen("score.txt", "a+")) == NULL)
		return (1);
	nom = (char *)malloc(sizeof(char) * 1);
	nom[0] = '\0';
	printf("Entrer un nom : ");
	i = 0;
	do{
		scanf("%c", &lettre);
		if (lettre != '\n')
			nom = ft_stradd(nom, lettre);
	}while (lettre != '\n' || i++ < 1);
	fprintf(score,"%s a fait %d en seulement %d coups sur une map de taille %d avec comme valeur max %d\n", nom, partie.somme, partie.coups, partie.taille, partie.max);
	free(nom);
	fclose(score);
	return (0);
}

int		fin_de_jeu_graphique(principal *donnee)
{
	MLV_Keyboard_button		touche;
	int						unicode;
	MLV_Keyboard_modifier	mode;
	int						x;
	int						y;
	char					*nom;
	FILE					*score;

	MLV_clear_window(MLV_COLOR_WHITE);
	MLV_actualise_window();
	MLV_draw_text_box(0, 0, LARG_WIN + 200, HAUT_WIN ,"Féliciation ! Vous avez gagné !\nVoulez-vous enrgistrer votre score ?", 0, MLV_COLOR_WHITE, MLV_COLOR_PURPLE, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box((LARG_WIN + 200) / 2 - 100, (HAUT_WIN / 2) + 50, 50, 50,"Oui", 0, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(((LARG_WIN + 200) / 2), (HAUT_WIN / 2) + 50, 50, 50, "Non", 0, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_actualise_window();
	do{
		MLV_wait_mouse(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee1[1]));
		if (donnee->jeu.coordonnee1[0] >= ((LARG_WIN + 200) / 2) - 100 && donnee->jeu.coordonnee1[0] < ((LARG_WIN + 200) / 2) - 50 && donnee->jeu.coordonnee1[1] >= (HAUT_WIN / 2) + 50 && donnee->jeu.coordonnee1[1] < (HAUT_WIN / 2) + 100)
			break ;
		else if (donnee->jeu.coordonnee1[0] >= (LARG_WIN + 200) / 2 && donnee->jeu.coordonnee1[0] < ((LARG_WIN + 200) / 2) + 50 && donnee->jeu.coordonnee1[1] >= (HAUT_WIN / 2) + 50 && donnee->jeu.coordonnee1[1] < (HAUT_WIN / 2) + 100)
			return (0);
	}while (1);
	MLV_clear_window(MLV_COLOR_WHITE);
	MLV_draw_text_box(0, 0, LARG_WIN + 200, HAUT_WIN ,"Entrer votre pseudo", 0, MLV_COLOR_WHITE, MLV_COLOR_PURPLE, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_actualise_window();
	y = HAUT_WIN / 2;
	x = LARG_WIN / 2 - 50;
	if ((score = fopen("score.txt", "a+")) == NULL)
		return (1);
	nom = (char*)malloc(sizeof(char) * 1);
	nom[0] = '\0';
	do
	{
		MLV_wait_keyboard(&touche, &mode, &unicode);
		if (unicode >= ' ' && 127 != unicode)
			nom = ft_stradd(nom, unicode);
		if (touche == MLV_KEYBOARD_BACKSPACE && *nom != '\0')
			nom = ft_strsupp(nom);
		MLV_clear_window(MLV_COLOR_WHITE);
		MLV_draw_text_box(0, 0, LARG_WIN + 200, HAUT_WIN ,"Entrer votre pseudo", 0, MLV_COLOR_WHITE, MLV_COLOR_PURPLE, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
		MLV_draw_text(x, y, nom, MLV_COLOR_BLACK);
		MLV_actualise_window();
	}while (touche != MLV_KEYBOARD_RETURN);
	fprintf(score,"%s a fait %d en seulement %d coups sur une map de taille %d avec comme valeur max %d\n", nom, donnee->jeu.somme, donnee->jeu.coups, donnee->jeu.taille, donnee->jeu.max);
	free(nom);
	fclose(score);
	return (0);
}

int		fin_de_jeu_ASCII(principal *donnee)
{
	char	choix;

	printf("Félécitation vous avez atteint l'objectif !!\nVoulez-vous sauvegarder votre score ? ");
	do{
		printf("(o/n) ");
		scanf(" %c", &choix);
		switch (choix)
		{
			case 'o' : return (sauvegarde_score(donnee->jeu));
			case 'n' : return (0);
			default : printf("Saisi non valide\n");
		}
	}while (1);
}

int		sauvegarde_tab(principal *donnee)
{
	int		i;
	int 	j;

	if (donnee->fichier != NULL)
		fclose(donnee->fichier);
	if ((donnee->fichier = fopen(donnee->entrer.fichier, "w")) == NULL)
		return (1);
	fprintf(donnee->fichier, "%d\n%d %d %d\n", donnee->jeu.taille, donnee->jeu.somme, donnee->jeu.coups, donnee->jeu.max);
	printf("SAUVEGARDE EN COURS");
	for (i = 0; i < donnee->jeu.taille; i++)
	{
		for (j = 0; j < donnee->jeu.taille; j++)
		{
			fprintf(donnee->fichier, "%d", donnee->jeu.grille[i][j]);
			if (j != donnee->jeu.taille - 1)
				fprintf(donnee->fichier, " ");
		}
		fprintf(donnee->fichier, "\n");
	}
	printf("\nSAUVEGARDE EFFECTUER\n");
	fclose(donnee->fichier);
	donnee->fichier = NULL;
	return (0);
}

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
				donnee->jeu.grille[i][j] = MLV_get_random_integer(-(donnee->jeu.max), donnee->jeu.max);
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
	scanborne(&(donnee->jeu.taille), 1, 20);
	printf("Entrer la valeur max\n");
	scanborne(&(donnee->jeu.max), 1, VAL_MAX);
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
	if (affiche_menu(donnee))
		return (-2);
	return (2);
}
