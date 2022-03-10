/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:28:31 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/10 11:45:02 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_save(char *buffer, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	i += 1;
	tmp = malloc(sizeof(char) * (ft_strlenreste(buffer) + 1));
	while (buffer[i] != '\0')
	{
		tmp[j] = buffer[i];
		i++;
		j++;
	}
	printf("--------tmpsave1--------%s\n", tmp);
	tmp[j] = '\0';
	printf("--------tmpsave1--------%s\n", tmp);
	return (tmp);
}

char	*ft_strjoin(char *buffer, char *line, char *tmp)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!tmp)
	{
		tmp = malloc(ft_strlen(buffer) + ft_strlen(line) + 2);
		if (!tmp)
			return (NULL);
	}
//	line = malloc(sizeof(char) * (ft_strlen(line)));
	if (line && line[i] != '\0')
	{
		{	
			tmp[i] = line[i];
			i++;
	//		printf("-----------------%s\n", line);
		//	printf("+++++++++++++++++%s\n", tmp);
		//	printf("*****%d\n", i);
		}
//	if (line[i] == '\0')
//			tmp[i] = '\0';
	}
	//i++;
	while (buffer[j] != '\0' && buffer[j] != '\n')
	{
		tmp[i++] = buffer[j++];
	//	printf("-----------------%s\n", line);
	//	printf("-----------------%c\n", line[i]);
	}
	if (buffer[j] == '\n')
	{
		tmp[i] = buffer[j];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_check(char *buffer, char *line, int ret, int fd)
{
	static char	*tmp;
	int			i;
	int			j;

//	if (!ret && !buffer)
//		tmp = NULL;
//	if (ret || tmp)
	line = ft_save_in_line(line, tmp);
	printf("++++++++apres saveinline+++++%s\n", line);
	printf("--------tmpstart--------%s\n", tmp);
	while ((ft_strchr(buffer, '\n') == 0) && (ret > 0))
	{
		printf("+++++++++++++++++%s\n", buffer);
		tmp = ft_strjoin(buffer, line, tmp);
		if (line)
		{
			free(line);
			line = NULL;
		}
		ret = read(fd, buffer, 1);
		line = tmp;
		printf("++++++++898989+++++%s\n", line);
	}
	i = 0;
	j = 0;
	if (ret > 0)
	{
		line = malloc(sizeof(char) * (ft_strlen(buffer) + (ft_strlen(tmp))) + 2);
		while (tmp && tmp[i] != '\0')
		{
			line[i] = tmp[i];
			i++;
		}
		printf("++++++++898989+++++%s\n", line);
		while (buffer[j] != '\n' && buffer[j] != '\0')
		{
			line[i] = buffer[j];
			i++;
			j++;
		}
		if (buffer[j] == '\n')
		{
			line[i] = buffer[j];
			i++;
		}
		line[i] = '\0';
		free(tmp);
	}
//	printf("+++++++++++++++++%s\n", buffer);
	printf("++++++++898989+++++%s\n", line);
	tmp = (char *)ft_save(buffer, tmp);
	printf("--------tmpsaveavant sortie--------%s\n", tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	ret = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (ret == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
	//	printf("--------oo--------%d\n", ret);
	}
	if (ret > 0 && buffer[0] != '\0')
	{
	//	line = malloc(sizeof(char) * ft_strlen(buffer) + ft_strlen(line) + 1);
		line = ft_check(buffer, line, ret, fd);
	}
	return (line);
}

int	main(void)
{
	int			fd;
	const char	*str = "./FileTest1.txt";
	char		*result;

	fd = open(str, O_RDONLY);
	result = get_next_line(fd);
	printf("final main%s\n", result);
	result = get_next_line(fd);
	printf("second main%s\n", result);
	return (0);
}
