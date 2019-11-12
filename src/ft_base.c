/* ************************************************************************** */
/*                                                                            */
/*                                 ft_base.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		ft_strcmp(char *s1, char *s2)
/* BUT    : Détermine si les chaines de charactères sont identiques ou non    */
/* PARAM  : s1 => chaine de charactère à comparer                             */
/*          s2 => chaine de charactère à comparer                             */
/* RETOUR : Renvoi 0 si les chaines sont identiques sinon la diffèrence       */
{
	int		i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
	return (s1[i] - s2[i]);
}

int		ft_nbrlen(long n)
/* BUT    : Détermine la taille en charactère d'un long int                   */
/* PARAM  : Entier dont on veut connaitre la taille                           */
/* RETOUR : Taille d'entier                                                   */
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
/* BUT    : Cherche la première occurence de la chaine s2 dans la chaine s1   */
/* PARAM  : s1 => chaine de charactère botte de foin                          */
/*          s2 => chaine de charactère aiguille                               */
/* RETOUR : Renvoie l'adresse du premier charactère de l'occurence de s2 dans */
/*          s1 si il y a un occurence sinon renvoie NULL                      */
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
/* BUT    : Convertie un entier en chaine de charactère                       */
/* PARAM  : Entier à convertir                                                */
/* RETOUR : Renvoie l'entier convertie ou NULL si il y a une erreur de malloc */
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

void	scanborne(int *a, int min, int max)
/* BUT   : Demande à l'utilisateur un entier compris entre min et max         */
/* PARAM : a   => adresse de l'entier à saisir                                */
/*         min => entier minimum accepté                                      */
/*         max => entier maximum accepté                                      */
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
/* BUT    : Retire le dernier charactère de la chaine s                       */
/* PARAM  : Chaine de charactère que l'on veut modifier                       */
/* RETOUR : La nouvelle chaine de charactère s sans le dernier charactère     */
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
/* BUT    : Ajoute le charactère c à la fin de la chaine de charactère s      */
/* PARAM  : s => chaine de charactère à changer                               */
/*          c => charactère à ajouter                                         */
/* RETOUR : Renvoie la nouvelle chaine de charactère s avec le charactère c   */
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
/* BUT : Echange les valeurs de deux entiers                                  */
/* PARAM : a => l'adresse du premier entier à échanger                        */
/*         b => l'adresse du second entier à échanger                         */
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strjoin(char *s1, char *s2, int boo)
/* BUT    : Crée une nouvelle chaine contenant la concaténation de s1 et s2 et*/
/*          peut libèrer l'espace mémoire de s1 et s2 si possible             */
/* PARAM  : s1  => première chaine de charactère                              */
/*          s2  => seconde chaine de charactère                               */
/*          boo => 0 libère aucune chaine, 1 libère s1, 2 libère s2 et libère */
/*                 toute les chaines avec 3                                   */
/* RETOUR : Renvoie la nouvelle chaine de charactère ou NULL si il y a un     */
/*          problème d'allocation mémoire                                     */
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
