/* ************************************************************************** */
/*																			  */
/*								   parsing.c								  */
/*																			  */
/* ************************************************************************** */

#include "grient.h"

void	flag_convertisseur(char c, principal *donnee)
{
	if (c == 'a')
		(donnee->entrer).flag = (donnee->entrer).flag  | 1;
	if (c == 'c')
		(donnee->entrer).flag = (donnee->entrer).flag  | 2;
	if (c == 'l')
		(donnee->entrer).flag = (donnee->entrer).flag  | 4;
	if (c == 'g')
		(donnee->entrer).flag = (donnee->entrer).flag  | 8;
}

int		flag_test(char *enter, principal *donnee)
{
	int		i;

	for (i = ft_strchr(enter, '-') + 1; enter[i] != '\0'; i++)
	{
		if (enter[i] != 'a' && enter[i] != 'c' && enter[i] != 'g' && enter[i] != 'l')
			return (0);
		else
			flag_convertisseur(enter[i], donnee);
	}
	return (1);
}

int		parsing_enter(char **av, int ac, principal *donnee)
{
	int		i;

	for (i = 1; i < ac; i++)
	{
		if (ft_strchr(av[i], '-') >= 0)
		{
			if (flag_test(av[i], donnee) == 0)
				return (0);
		}
		else
		{
			if (donnee->entrer.fichier == NULL)
				if ((donnee->entrer.fichier = ft_strdup(av[i])) == NULL)
					return (-1);
		}
	}
	return (1);
}
