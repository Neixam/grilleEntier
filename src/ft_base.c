/* ************************************************************************** */
/*                                                                            */
/*                                 ft_base.c                                  */
/*                                                                            */
/* ************************************************************************** */

#include "grient.h"

int		ft_strlen(char *s)
{
	int		len;

	for (len = 0; s[len] != '\0'; len++);
	return (len);
}

char	*ft_strdup(char *s)
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

int		ft_strchr(char *s1, char c)
{
	int		i;

	for (i = 0; s1[i] != '\0'; i++)
		if (s1[i] == c)
			return (i);
	return (-1);
}
