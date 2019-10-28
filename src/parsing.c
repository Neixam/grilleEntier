/* ************************************************************************** */
/*                                                                            */
/*                                 parsing.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

void	flag_convertisseur(char c, principal *donnee)
/* BUT   : Converti les options données en argument en masquage de bit        */
/* PARAM : c      => charactère à tester et à convertir                       */
/*         donnee => adresse de la structure principale à modifier            */
{
	if (c == 'a')
	{
		if ((donnee->entrer).flag & 8)
			(donnee->entrer).flag = (donnee->entrer).flag  - 8;
		donnee->entrer.nb_flag = donnee->entrer.nb_flag | 1;
		(donnee->entrer).flag = (donnee->entrer).flag  | 1;
	}
	if (c == 'c')
	{
		if ((donnee->entrer).flag & 4)
			(donnee->entrer).flag = (donnee->entrer).flag - 4;
		donnee->entrer.nb_flag = donnee->entrer.nb_flag | 2;
		(donnee->entrer).flag = (donnee->entrer).flag  | 2;
	}
	if (c == 'l')
	{
		if ((donnee->entrer).flag & 2)
			(donnee->entrer).flag = (donnee->entrer).flag  - 2;
		donnee->entrer.nb_flag = donnee->entrer.nb_flag | 2;
		(donnee->entrer).flag = (donnee->entrer).flag  | 4;
	}
	if (c == 'g')
	{
		if ((donnee->entrer).flag & 1)
			(donnee->entrer).flag = (donnee->entrer).flag  - 1;
		donnee->entrer.nb_flag = donnee->entrer.nb_flag | 1;
		(donnee->entrer).flag = (donnee->entrer).flag  | 8;
	}
}

int		flag_test(char *enter, principal *donnee) 
/* BUT   : Parcours l'argument donné pour le tester si il est valide ou non   */
/* PARAM : enter  => chaîne de charactère qui représente l'argument donné     */
/*                   au programme                                             */
/*         donnee => adresse de la structure principale                       */
{
	int		i;

	if ((i = ft_strchr(enter, '-')) != 0)
		return (0);
	for (i += 1; enter[i] != '\0'; i++)
	{
		if (enter[i] != 'a' && enter[i] != 'c' && enter[i] != 'g' && enter[i] != 'l')
			return (0);
		else
			flag_convertisseur(enter[i], donnee);
	}
	return (1);
}

int		parsing_enter(char **av, int ac, principal *donnee)
/* BUT    : Informe la fonction main si les arguments reçus sont justes et    */
/*          sinon le type d'erreur trouvé                                     */
/* PARAM  : av     => tableau de chaîne de charactère contenant les arguments */
/*                    du programme                                            */
/*          ac     => taille du tableau av et nombre d'argument + 1           */
/*          donnee => adresse de la structure principale                      */
/* RETOUR : retourne 0 s'il y a une mauvaise option 1 s'il manque un argument */
/*          et -1 si l'allocation mémoire à échouer                           */
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
	if (donnee->entrer.nb_flag != 3 || donnee->entrer.fichier == NULL)
		return (1);
	return (2);
}
