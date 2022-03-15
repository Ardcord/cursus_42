/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:28:31 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/14 17:30:02 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_mlc(char *buffer, char *tmp)
{
	char	*save;

	save = NULL;
	if (!tmp || !ft_strchr(tmp, '\n'))
	{
		if (ft_strreste(buffer))
			save = malloc(sizeof(char) * (ft_strreste(buffer) + 1));
		if (!save)
			return (NULL);
		return (save);
	}
	else if (ft_strreste(tmp))
		save = malloc(sizeof(char) * (ft_strreste(tmp) + 1));
	if (!save)
		return (NULL);
	return (save);
}

char	*ft_save(char *buffer, char **tmp, int i, int j)
{
	char	*save;

	save = (ft_mlc(buffer, *tmp));
	if (!save)
		return (NULL);
	if (!ft_strchr(*tmp, '\n'))
	{
		while (buffer[i] && buffer[i] != '\n')
			i++;
		i += 1;
		while (buffer[i] != '\0')
			save[j++] = buffer[i++];
	}
	else
	{
		while ((*tmp)[i] && (*tmp)[i] != '\n')
			i++;
		i++;
		while ((*tmp)[i])
			save[j++] = (*tmp)[i++];
	}
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	save[j] = '\0';
	return (save);
}

char	*ft_strjoin(char *buffer, char **tmp)
{
	t_index	i;

	i.i = 0;
	i.j = 0;
//	printf(" == %d == %d == %d == %d ==", ft_strlen(buffer), ft_strreste(buffer), ft_strlen(tmp), ft_strreste(tmp));
	i.save = malloc(sizeof(char) * (ft_strlen(buffer)
				+ ft_strlen(*tmp) - ft_strreste(*tmp) + 2));
	if (!i.save)
		return (NULL);
	while (i.save && *tmp && (*tmp)[i.i])
	{
		i.save[i.i] = (*tmp)[i.i];
		i.i++;
		if ((*tmp)[i.i] && (*tmp)[i.i] == '\n')
		{
			i.save[i.i++] = '\n';
			i.save[i.i] = '\0';
			return (i.save);
		}
	}
	if (*tmp && (*tmp)[0])
	{
		free(*tmp);
		*tmp = NULL;
	}
	while (buffer[i.j] != '\0' && buffer[i.j] != '\n')
		i.save[i.i++] = buffer[i.j++];
	if (buffer[i.j] && buffer[i.j] == '\n')
		i.save[i.i++] = buffer[i.j++];
	i.save[i.i] = '\0';
	return (i.save);
}

char	*ft_check(char *buffer, char *line, int *ret, int fd)
{
	static char	*tmp;

//	if (tmp)
//		tmp = ft_save_in_line(line, tmp);
	// if (!ret && !buffer[0])
	// {
	// 	if (tmp)
	// 		free(tmp);
	// 	tmp = NULL;
	// }
//	printf("%d, %d, %d\n%s", ft_strlen(buffer), ft_strreste(buffer), ft_strlen(tmp), tmp);
	while ((buffer[0] && !ft_strchr(buffer, '\n') && *ret > 0)
		|| (tmp && !ft_strchr(tmp, '\n') && *ret > 0))
	{
		tmp = ft_strjoin(buffer, &tmp);
//		printf("\ntmp after join buffer %s\n", tmp);
	//	if (ft_strchr(line, '\n'))
	//		return (line);
		line = tmp;
		*ret = read(fd, buffer, 1);
		buffer[*ret] = '\0';
//		write(1, "passe in---\n", 12);
	//	printf("boucle infini");
	}
//	write(1, "passe out", 9);
	printf("====> tmp before ret line %s\n", tmp);
	if (buffer[0] || tmp)
		line = ft_strjoin(buffer, &tmp);
	tmp = (char *)ft_save(buffer, &tmp, 0, 0);
	buffer[0] = 0;
	if (*ret == 0 && tmp)
	{
		free(tmp);
		tmp = NULL;
		*ret = -1;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	static int		ret = 0;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (ret == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret == 0)
			return (NULL);
	}
	if (ret < 0)
		return (NULL);
	line = ft_check(buffer, line, &ret, fd);
//	printf("\n");
	return (line);
}

//int	main(int ac, char **av)
int main ()
{
	int			fd;
	const char	*str = "./FileTest1.txt";
	char		*result;

//	fd = open(av[1], O_RDONLY);
	fd = open(str, O_RDONLY);
//	(void)ac;
	result = get_next_line(fd);
	printf("----1 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("2 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("3 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("4 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("5 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("6 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("7 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("8 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("9 main----%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("10 main---%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("11 main---%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("12 main---%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("13 main---%s----\n", result);
	if (result)
		free(result);
	result = get_next_line(fd);
	printf("14 main---%s----\n", result);
	if (result)
		free(result);
	return (0);
}
