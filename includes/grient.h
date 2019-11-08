/* ************************************************************************** */
/*                                 Header                                     */
/*                                                                            */
/*                           abourenn - chacelas                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIENT_H
# define GRIENT_H
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <MLV/MLV_all.h>
# define LARG_WIN 1440
# define HAUT_WIN 720
# define VAL_MAX 80
# define BUT 100
# define TAILLE_NOM 25

typedef struct	parsing
{
	int		nb_flag;
	int		flag;
	char	*fichier;
}				parse;

typedef struct	grille_s
{
	int		max;
	int		coups;
	int		taille;
	int		somme;
	int		type_coups;
	int		coordonnee1[2];
	int		coordonnee2[2];
	int		**grille;
}				grille;

typedef struct	principal
{
	parse			entrer;
	grille			jeu;
	FILE			*fichier;
	int				error;
}				principal;

char	*ft_itoa(int n);
char	*ft_stradd(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2, int boo);
char	*ft_strstr(char *s1, char *s2);
char	*ft_strsupp(char *s);

int		affiche_menu(principal *donnee);
int		fin_de_jeu_ASCII(principal *donnee);
int		fin_de_jeu_graphique(principal *donnee);
int		quitte_graphique(principal *donnee);
int		ft_puterror(int type_error);
int		ft_strchr(char *s1, char c);
int		ft_strlen(char *s);
int		initAlea(int max);
int		parsing_enter(char **av, int ac, principal *donnee);
int		sauvegarde_tab(principal *donnee);
int		start_game(principal *donnee);
int		test_entrer_coord(principal *donnee);

void	conv_position_win_tab(principal *donnee, int boo);
void	delete_struct(principal *donnee);
void	echangeEntier(int *a, int *b);
void	initialisation(principal *nw);
void	joue_ASCII(principal *donnee);
void	remake_tab(principal *donnee, int ligne, int colonne);
void	scanborne(int *a, int min, int max);
void	select_case(principal *donnee, int y, int x, int taille);
void	select_ligne(principal *donnee);

#endif
