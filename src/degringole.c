/* ************************************************************************** */
/*                                                                            */
/*                                degringole.c                                */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

void	conv_position_win_tab(principal *donnee, int boo)
/* BUT   : Converti la position du clique à une coordonnée de la grille du jeu*/
/* PARAM : donnee => adresse de la structure principale                       */
/*         boo    => entier étant soit 1 déterminant un conversion des        */
/*                   coordonnées de la première case et 0 pour la deuxième    */
{
	int		i;
	float	surfacel;
	float	surfaceh;

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

char	*change_path(char *dossier, char *path)
/* BUT    : Crée un nouveau path pour le fichier en rajoutant dossier juste   */
/*          avant le dernier le fichier du path                               */
/* PARAM  : dossier => la chainne de charactère contenant le nom du dossier   */
/*          path    => la chainne de charactère contenant le path du fichier  */
/* RETOUR : Renvoie la nouvelle chainne de charactère contenant le path du    */
/*          fichier                                                           */
{
	int		len;
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (ft_strstr(path, "/") == NULL)
		return (ft_strjoin(dossier, path, 0));
	for (tmp = ft_strstr(path, "/"); ft_strstr(tmp, "/") != NULL; tmp = ft_strstr(tmp, "/"));
	len = ft_strlen(dossier) + ft_strlen(tmp);
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	for (j = 0; dossier[j] != '\0'; j++)
		ret[j] = dossier[j];
	for (i = 0; i + j < len; i++)
		ret[i + j] = tmp[i];
	ret[i + j] = '\0';
	return (ret);
}

void	remake_tab(principal *donnee, int ligne, int colonne)
/* BUT   : Descend d'un indice toute les valeurs de la colonne et le premier  */
/*         devient un entier aléatoire compris entre -max et max              */
/* PARAM : donnee  => adresse de la structure principale                      */
/*         ligne   => position de la ligne où débuter                         */
/*         colonne => position de la colonne qu'il faut modifier              */
{
	int		i;

	for (i = ligne; i > 0; i--)
		donnee->jeu.grille[i][colonne] = donnee->jeu.grille[i - 1][colonne];
	donnee->jeu.grille[i][colonne] = MLV_get_random_integer(-(donnee->jeu.max), donnee->jeu.max);
}
