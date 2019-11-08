/* ************************************************************************** */
/*                                                                            */
/*                                 ft_base.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
	return (s1[i] - s2[i]);
}

int		ft_nbrlen(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while ((n /= 10) > 0)
		i++;
	return (i + 1);
}

char	*ft_strstr(char *s1, char *s2)
{
	int		i;
	int		j;

	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s1[i + j] == s2[j] && s2[j] != '\0' && s1[i + j] != '\0'; j++);
		if (s2[j] == '\0')
			return (&s1[i + 1]);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	tmp;
	int		i;
	int		sign;

	sign = 0;
	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		sign = 1;
	}
	i = ft_nbrlen(tmp) + sign;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

int		initAlea(int max)
{
	long int	tmp;

	tmp = random();
	if ((tmp = tmp % (max * 2)) >= max)
		return (tmp - max);
	return (-tmp);
}

void	scanborne(int *a, int min, int max)
{
	do
	{
		printf("Un entier compris entre %d et %d : ", min, max);
		scanf("%d", a);
	}while (*a >= max && *a <= min);
}

int		ft_strlen(char *s)
/* BUT    : Calcule la taille d'une chaîne de charactère                      */
/* PARAM  : s => chaîne de charactère dont on veut connaître la taille        */
/* RETOUR : retourne la taille trouvé lors du parcours                        */
{
	int		len;

	for (len = 0; s[len] != '\0'; len++);
	return (len);
}

char	*ft_strsupp(char *s)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(s) - 1;
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		ret[i] = s[i];
	ret[i] = '\0';
	free(s);
	return (ret);
}

char	*ft_stradd(char *s, int c)
{
	int		len;
	int		i;
	char	*ret;

	len = ft_strlen(s) + 1;
	if ((ret = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	for (i = 0; i < len - 1; i++)
		ret[i] = s[i];
	ret[i] = c;
	ret[i + 1] = '\0';
	free(s);
	return (ret);
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

void	echangeEntier(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strjoin(char *s1, char *s2, int boo)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		ret[i] = s1[i];
	j = i;
	for (i = 0; s2[i] != '\0'; i++)
	{
		ret[j] = s2[i];
		j++;
	}
	ret[j] = '\0';
	if (boo == 1 || boo == 3)
		free(s1);
	if (boo == 2 || boo == 3)
		free(s2);
	return (ret);
}
