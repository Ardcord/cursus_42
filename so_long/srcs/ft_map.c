/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:46:20 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/06 17:03:50 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/struct.h"
#include "../includes/define.h"

void	ft_map(int fd, t_strc *q)
{
	if (fd == -1)
	{
		ft_putstr_fd("There was a problem to open the file.\n", 2);
		exit (-1);
	}
	maptab(q);
	if (close(fd) == -1)
	{
		ft_putstr_fd("There was a problem to close the file.\n", 2);
		exit(-1);
	}
}

void	maptab(t_strc *q)
{
	int		i;

	i = 0;
	q->fd = open(q->path, O_RDONLY);
	if (q->fd == -1)
	{
		ft_putstr_fd("Can't open the map file\n", 2);
		exit(-1);
	}
	q->tab = malloc(sizeof(*(q->tab)) * 10000);
	put_map_in_tab(q, i);
}

void	put_map_in_tab(t_strc *q, int i)
{
	while (1)
	{
		q->gnl = get_next_line(q->fd);
		if (!q->gnl || q->gnl == NULL)
			break ;
		q->tab_y++;
		q->tab_x = ft_howmany(q->gnl, q);
		q->tab[i] = malloc(sizeof(*(q->tab[i])) * q->tab_x);
		q->tab[q->tab_x] = NULL;
		if (!q->tab[i])
			return (free(q->tab));
		strintab(q->gnl, q->tab[i]);
		free(q->gnl);
		i++;
	}
	q->tab[i++] = NULL;
	if (close(q->fd) == -1)
	{
		free_map(q->tab);
		ft_putstr_fd("Can't closed the map file\n", 2);
		exit(-1);
	}
}

void	strintab(char *tmp, char *tab)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (tmp && tmp[i] && tmp[i] != '\n')
	{	
		while (tmp[i] && ft_isset(tmp[i], "01CEP"))
		{
			tab[k] = tmp[i];
			i++;
			k++;
		}
		if (tmp[i] && !ft_isset(tmp[i], "01CEP\n"))
		{
			ft_putstr_fd("Error, incorrect character in map file", 2);
			exit(-1);
		}
	}
}

int	ft_howmany(char *tmp, t_strc *q)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i] != '\0' && tmp[i] != '\n')
		{
			while (ft_isset(tmp[i], "01CEP"))
				i++;
			if (tmp[i] && !ft_isset(tmp[i], "01CEP\n"))
			{
				ft_putstr_fd("Error, incorrect character in map file", 2);
				exit(-1);
			}
		}
	}
	if ((q->temp != 0) && (q->temp != i))
		q->error_1 = 1;
	q->temp = i;
	return (i);
}
