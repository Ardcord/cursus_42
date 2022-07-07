/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:17:14 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/06 17:46:03 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlengnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchrgnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlengnl(s1) + ft_strlengnl(s2) + 1);
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_read(int fd, char *buff, char *result, int nbr)
{
	while (nbr > 0 && ft_strchrgnl(result, '\n'))
	{
		result = ft_strjoingnl(result, buff);
		nbr = read(fd, buff, 1);
		buff[nbr] = '\0';
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static int	nbr;
	static char	buff[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*result;

	result = NULL;
	if (nbr == 0)
	{
		nbr = read(fd, buff, 1);
		buff[nbr] = '\0';
	}
	if (nbr > 0 && buff[0] != '\0')
		result = ft_read(fd, buff, result, nbr);
	else
		return (NULL);
	return (result);
}
