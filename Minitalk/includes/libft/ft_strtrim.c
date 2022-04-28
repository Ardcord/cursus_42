/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:50:53 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/05 10:08:32 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int *tabtemp)
{
	int	val;
	int	j;
	int	k;

	val = 0;
	j = tabtemp[0];
	k = tabtemp[1];
	while (j <= k)
	{
		j++;
		val++;
	}
	return (val);
}

static void	ft_check_back(char const *str, char const *set, int *tabtemp)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen((char *)str) - 1;
	while (set[j] != '\0')
	{	
		while (str[i] == set[j])
		{
			i--;
			j = 0;
		}
		if (str[i] != set[j])
			j++;
	}
	tabtemp[1] = i;
}

static void	ft_check_forward(char const *str, char const *set, int *tabtemp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		while (str[i] == set[j])
		{
			i++;
			j = 0;
		}
		if (str[i] != set[j])
			j++;
	}
		tabtemp[0] = i;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		tabtemp[2];
	int		i;
	int		f;
	int		g;

	i = 0;
	f = 0;
	g = 0;
	if (!s1)
		return ((char *)s1);
	tabtemp[0] = 0;
	tabtemp[1] = 0;
	ft_check_forward((char *)s1, (char *)set, tabtemp);
	ft_check_back((char *)s1, (char *)set, tabtemp);
	f = (ft_count(tabtemp));
	final = malloc(sizeof(char) * (f) + 1);
	i = tabtemp[0];
	if (!final)
		return (NULL);
	while (g <= f - 1)
		final[g++] = s1[i++];
	final[g] = '\0';
	return (final);
}
