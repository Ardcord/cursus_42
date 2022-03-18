/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:26:52 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/15 09:49:21 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *line, char nl)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == nl)
			return (0);
		i++;
	}
	return (1);
}
