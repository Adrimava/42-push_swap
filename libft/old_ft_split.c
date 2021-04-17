/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:59:15 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/11 12:30:36 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stdlib.h>

unsigned long int	ft_strlen(const char *str)
{
	unsigned long int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}*/

char	**ft_split(char	const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;
	int		len;
	int		strings;

	if (s == NULL)
		return (NULL);
	i = 0;
	strings = 0;
	while (s[i])
	{
		if (i > 0 && s[i] == c && s[i - 1] != c)
			strings++;
		i++;
		if (i > 0 && s[i] == 0 && s[i - 1] != c)
			strings++;
	}
	res = (char**)malloc(sizeof(char*) * (strings + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		len = i;
		while (s[len] != c)
			len++;
		res[j] = (char*)malloc(sizeof(char*) * (len - i + 2));
		if (res[j] == NULL)
			return (NULL);

		while (s[i] != c)
		{
			res[j][k] = s[i];
			k++;
			i++;
		}
		res[j][len] = 0;
		k = 0;
		if (i > 0 && (s[i] == c || s[i] == 0) && s[i - 1] != c)
			j++;
		i++;
	}
	res[j] = 0;
	return (res);
}

/*int		main(void)
{
	char const *s = "Hola    que pasa mundo      adios";
	char	**tab = ft_split(s, ' ');
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
