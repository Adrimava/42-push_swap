/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:23:13 by amaza-va          #+#    #+#             */
/*   Updated: 2019/11/12 19:56:21 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	c_count(char const *s1, char const *set)
{
	unsigned long int i;
	unsigned long int j;
	unsigned long int count;
		
	count = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				count++;
			j++;
		}
		i++;
	}
	return (i - count);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;
	unsigned long int	k;
	unsigned long int	check;
	char				*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char*)s1);
	str = (char*)malloc(sizeof(char*) * (c_count(s1, set) + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	check = 0;
	while (s1[i])
	{
		j = 0;
		check = 0;
		while (set[j] && check == 0)
		{
			if (s1[i] == set[j] && (i == 0 || i == ft_strlen(s1) - 1))
				check = 1;
			j++;
		}
		if (check == 0)
		{
			str[k] = s1[i];
			k++;
		}
		i++;
	}
	str[k] = 0;
	i = 0;
	while (set[i])
	{
		if (str[0] == set[i] || str[k - 1] == set[i])
			str = ft_strtrim((char const*)str, set);
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char const *s1 = "hola, munhdo, que pasahh";
	char const *set = "ha";
	printf("%s\n", ft_strtrim(s1, set));
}*/
