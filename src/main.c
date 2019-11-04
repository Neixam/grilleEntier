/* ************************************************************************** */
/*                                                                            */
/*                                 main.c                                     */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		main(int ac, char **av)
{
	principal	donnee;

	if (ac == 1)
		return (ft_puterror(1));
	initialisation(&donnee);
	if ((donnee.error = parsing_enter(av, ac, &donnee)) < 2)
		return (ft_puterror(donnee.error));
	if ((donnee.error = start_game(&donnee)) < 2)
		return (ft_puterror(donnee.error));
	return (0);
}
