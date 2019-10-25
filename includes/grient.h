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
# include <MLV/MLV_all.h>

typedef struct	parsing
{
	int		flag;
	char	*fichier;
}				parse;

typedef struct	grille_s
{
	
}				grille;

typedef struct	principal
{
	parse	entrer;
	grille	jeu;
	FILE	*fichier;
	int		error;
}				principal;

char	*ft_strdup(char *s);

int		ft_puterror(int type_error);
int		ft_strchr(char *s1, char c);
int		ft_strlen(char *s);
int		parsing_enter(char **av, int ac, principal *donnee);

void	initialisation(principal *nw);

#endif
