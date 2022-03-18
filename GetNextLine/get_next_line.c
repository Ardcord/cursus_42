/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:09:02 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/15 10:04:31 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	ret = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!ret)
		return (NULL);
	if (line)
	{
		while (line[i])
		{
			ret[i] = line[i];
			i++;
		}
	}
	j = 0;
	while (buffer[j])
		ret[i++] = buffer[j++];
	ret[i] = '\0';
	free(line);
	return (ret);
}

char	*ft_check(int fd, char *buffer, char *line, int ret)
{
	while (ret > 0 && ft_strchr(line, '\n'))
	{
		line = ft_strjoin(line, buffer);
		ret = read(fd, buffer, 1);
		buffer[ret] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static int	ret;
	static char	buffer[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (ret == 0)
	{
		ret = read(fd, buffer, 1);
		buffer[ret] = '\0';
	}
	if (ret > 0 && buffer[0] != '\0')
		line = ft_check(fd, buffer, line, ret);
	else
		return (NULL);
	return (line);
}
