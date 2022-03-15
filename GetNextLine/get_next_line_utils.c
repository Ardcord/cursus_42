/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:43:26 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/15 09:47:53 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
		return (0);
}

int	ft_strreste(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
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
	line = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!line)
		return (NULL);
	while (tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	free(tmp);
	tmp = NULL;
	return (line);
}
