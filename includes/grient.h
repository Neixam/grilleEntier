/* ************************************************************************** */
/*                                 Header                                     */
/*                                                                            */
/*                           Abourenn -                                       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIENT_H
# define GRIENT_H
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <MLV/MLV_all.h>
# define VAL_MAX 80

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
	int		**grille;
}				grille;

typedef struct	principal
{
	unsigned int	seed;
	parse			entrer;
	grille			jeu;
	FILE			*fichier;
	int				error;
}				principal;

char	*ft_strdup(char *s);

int		ft_puterror(int type_error);
int		ft_strchr(char *s1, char c);
int		ft_strlen(char *s);
int		parsing_enter(char **av, int ac, principal *donnee);
int		start_game(principal *donnee);

void	affiche_menu(principal *donnee);
void	initAlea(int *a, int max);
void	initialisation(principal *nw);
void	scanborne(int *a, int min, int max);

#endif
