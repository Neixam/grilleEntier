/* ************************************************************************** */
/*                                                                            */
/*                                 ft_base.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		ft_strlen(char *s)
/* BUT    : Calcule la taille d'une chaîne de charactère                      */
/* PARAM  : s => chaîne de charactère dont on veut connaître la taille        */
/* RETOUR : retourne la taille trouvé lors du parcours                        */
{
	int		len;

	for (len = 0; s[len] != '\0'; len++);
	return (len);
}

char	*ft_strdup(char *s)
/* BUT    : Alloue une nouvelle chaîne de charactère dont le contenue est s   */
/* PARAM  : s => chaîne de charactère dont on veut copier le contenue         */
/* RETOUR : retourne la nouvelle chaîne de charactère créée                   */
{
	int		len;
	int		i;
	char	*ret;

	len = ft_strlen(s);
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

int		ft_strchr(char *s, char c)
/* BUT    : Cherche un charactère précis dans une chaîne donnée               */
/* PARAM  : s => chaîne de charactère dont on veut trouvé un charactère       */
/*          c => charactère que l'on veut retrouvé dans la chaîne             */
/* RETOUR : retourne l'indice si il y a une occurence dans la chaîne sinon -1 */
{
	int		i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (i);
	return (-1);
}
