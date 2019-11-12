/* ************************************************************************** */
/*                                                                            */
/*                                   game.c                                   */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		sauvegarde_score_ASCII(grille partie)
/* BUT    : Sauvegarde le score de l'utilisateur dans un fichier score.txt    */
/* PARAM  : partie => la structure de la grille du jeu                        */
/* RETOUR : Renvoi 1 si le programme n'arrive pas à ouvrir le fichier         */
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
/* BUT    : Demande à l'utilisateur s'il veut enregistrer son score et        */
/*          l'enregistre si oui dans le fichier score.txt                     */
/* PARAM  : adresse de la structure principale                                */
/* RETOUR : Renvoie 1 si le fichier score.txt n'est pas accessible et 0 sinon */
{
	MLV_Keyboard_button		touche;
	MLV_Keyboard_modifier	mode;
	int						unicode;
	int						x;
	int						y;
	int						len;
	int						nb_accent;
	char					*nom;
	char					*tmp;
	FILE					*score;

	MLV_clear_window(MLV_COLOR_WHITE);
	MLV_actualise_window();
	MLV_draw_text_box(0, 0, LARG_WIN + LARG_WIN / 6, HAUT_WIN ,"Féliciation ! Vous avez gagné !\nVoulez-vous enrgistrer votre score ?", 0, MLV_COLOR_WHITE, MLV_COLOR_PURPLE, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box((LARG_WIN + LARG_WIN / 6) / 2 - 150, (HAUT_WIN / 2) + 50, 50, 50,"Oui", 0, MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_draw_text_box(((LARG_WIN + LARG_WIN / 6) / 2) + 100, (HAUT_WIN / 2) + 50, 50, 50, "Non", 0, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	MLV_actualise_window();
	do{
		MLV_wait_mouse(&(donnee->jeu.coordonnee1[0]), &(donnee->jeu.coordonnee1[1]));
		if (donnee->jeu.coordonnee1[0] >= ((LARG_WIN + LARG_WIN / 6) / 2) - 150 && donnee->jeu.coordonnee1[0] < ((LARG_WIN + LARG_WIN / 6) / 2) - 100 && donnee->jeu.coordonnee1[1] >= (HAUT_WIN / 2) + 50 && donnee->jeu.coordonnee1[1] < (HAUT_WIN / 2) + 100)
			break ;
		else if (donnee->jeu.coordonnee1[0] >= ((LARG_WIN + LARG_WIN / 6) / 2) + 100 && donnee->jeu.coordonnee1[0] < ((LARG_WIN + LARG_WIN / 6) / 2) + 150 && donnee->jeu.coordonnee1[1] >= (HAUT_WIN / 2) + 50 && donnee->jeu.coordonnee1[1] < (HAUT_WIN / 2) + 100)
			return (0);
	}while (1);
	y = HAUT_WIN / 2 + 50;
	x = LARG_WIN / 2 + 125;
	if ((score = fopen("score.txt", "a+")) == NULL)
		return (1);
	nom = (char*)malloc(sizeof(char) * 1);
	nom[0] = '\0';
	len = 0;
	nb_accent = 0;
	do
	{
		MLV_clear_window(MLV_COLOR_WHITE);
		MLV_draw_text_box(0, 0, LARG_WIN + LARG_WIN / 6, HAUT_WIN ,"Entrer votre pseudo", 0, MLV_COLOR_WHITE, MLV_COLOR_PURPLE, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
		MLV_draw_text(x - (7 * len), y, nom, MLV_COLOR_BLACK);
		MLV_actualise_window();
		MLV_wait_keyboard(&touche, &mode, &unicode);
		if (touche != MLV_KEYBOARD_BACKSPACE && unicode >= ' ' && 127 != unicode && len < 25)
		{
			tmp = MLV_convert_unicode_to_string(unicode);
			if (tmp != NULL && tmp[1] != '\0')
				nb_accent++;
			nom = ft_strjoin(nom, tmp, 3);
			len++;
		}
		if (touche == MLV_KEYBOARD_BACKSPACE && *nom != '\0')
		{
			nom = ft_strsupp(nom);
			len--;
			if (nom[len + nb_accent - 1] < 0)
			{ 
				nom = ft_strsupp(nom);
				nb_accent--;
			}
		}
	}while (touche != MLV_KEYBOARD_RETURN);
	fprintf(score,"%s a fait %d en seulement %d coups sur une map de taille %d avec comme valeur max %d\n", nom, donnee->jeu.somme, donnee->jeu.coups, donnee->jeu.taille, donnee->jeu.max);
	free(nom);
	fclose(score);
	return (0);
}

int		fin_de_jeu_ASCII(principal *donnee)
/* BUT    : Demande à l'utilisateur si il veut enregistrer son score          */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 0 ou 1 si la fonction sauvegarde_score_ASCII rencontre un */
/*          problème                                                          */
{
	char	choix;

	printf("Félécitation vous avez atteint l'objectif !!\nVoulez-vous sauvegarder votre score ? ");
	do{
		printf("(o/n) ");
		scanf(" %c", &choix);
		switch (choix)
		{
			case 'o' : return (sauvegarde_score_ASCII(donnee->jeu));
			case 'n' : return (0);
			default : printf("Saisi non valide\n");
		}
	}while (1);
}

int		sauvegarde_tab(principal *donnee)
/* BUT    : Sauvegarde la grille du jeu dans un fichier du dossier save       */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si l'ouverture/création d'un fichier est impossible et 0*/
/*          sinon                                                             */
{
	int		i;
	int 	j;
	char	*save_path;

	if (donnee->fichier != NULL)
		fclose(donnee->fichier);
	if ((donnee->fichier = fopen(donnee->entrer.fichier, "r")) == NULL)
	{
		save_path = change_path("save/", donnee->entrer.fichier);
		if ((donnee->fichier = fopen(save_path, "w")) == NULL)
			return (1);
		free(save_path);
	}
	else
	{
		fclose(donnee->fichier);
		if (ft_strstr(donnee->entrer.fichier, "save/") != NULL)
		{
			if ((donnee->fichier = fopen(donnee->entrer.fichier, "w")) == NULL)
				return (1);
		}
		else
		{
			save_path = change_path("save/", donnee->entrer.fichier);
			if ((donnee->fichier = fopen(save_path, "w")) == NULL)
				return (1);
			free(save_path);
		}
	}
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
/* BUT    : Crée la grille du jeu selon les options d'entrer                  */
/* PARAM  : l'adresse de la structure principale                              */
/* RETOUR : Renvoie 1 si l'accès à la mémoire n'est pas authorisé et 0 sinon  */
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
/* BUT    : Lis la grille dans le fichier donné en entrer du programme        */
/* PARAM  : adresse de la structure principale                                */
/* RETOUR : Renvoie 1 si l'ouverture est impossible et 0 sinon                */
{
	char	*path;

	if ((donnee->fichier = fopen(donnee->entrer.fichier, "r")) == NULL)
	{
		path = ft_strjoin("save/", donnee->entrer.fichier, 0);
		if ((donnee->fichier = fopen(path, "r")) == NULL)
		{
			free(path);
			path = ft_strjoin("map/", donnee->entrer.fichier, 0);
			if ((donnee->fichier = fopen(path, "r")) == NULL)
				return (1);
		}
		free(path);
	}
	fscanf(donnee->fichier, "%d", &(donnee->jeu.taille));
	fscanf(donnee->fichier, "%d %d %d", &(donnee->jeu.somme), &(donnee->jeu.coups), &(donnee->jeu.max));
	if (creat_grille(donnee))
		return (1);
	return (0);
}

int		not_read_grille(principal *donnee)
/* BUT    : Demande à l'utilisateur les valeurs max et la taille de la grille */
/*          de jeu et commence la création de la nouvelle grille en créant le */
/*          nouveau fichier dans le dossier map                               */
/* PARAM  : adresse de la structure principale                                */
/* RETOUR : Renvoie 1 si la création de fichier a échouée sinon 0             */
{
	char	*map_path;
	int		i;
	int		j;

	printf("Entrer la taille du tableau\n");
	scanborne(&(donnee->jeu.taille), 1, 20);
	printf("Entrer la valeur max\n");
	scanborne(&(donnee->jeu.max), 1, VAL_MAX);
	if (creat_grille(donnee))
		return (1);	
	map_path = ft_strjoin("map/", donnee->entrer.fichier, 0);
	if ((donnee->fichier = fopen(map_path, "w")) == NULL)
	{
		free(map_path);
		return (1);
	}
	free(map_path);
	fprintf(donnee->fichier, "%d\n%d %d %d\n", donnee->jeu.taille, donnee->jeu.somme, donnee->jeu.coups, donnee->jeu.max);
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
	fclose(donnee->fichier);
	donnee->fichier = NULL;
	return (0);
}

int		start_game(principal *donnee)
/* BUT    : Appelle les fonctions initialisants le jeu et le démarre si       */
/*          l'initialisation a réussi                                         */
/* PARAM  : adresse de la structure princiale                                 */
/* RETOUR : Renvoie le type d'erreur au programme principale pour informer    */
/*          l'utilisateur le type de problème rencontrer                      */
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
