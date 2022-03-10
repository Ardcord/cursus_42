/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:43:26 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/10 11:45:08 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlenreste(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
		i++;
	i++;
	j = 0;
	while (str[i + j] != '\0')
		j++;
	return (j);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_save_in_line(char *line, char *tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			line[i] = tmp[i];
			i++;
		}
	}
	return(line);
}
