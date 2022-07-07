/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:47:58 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 19:40:39 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/struct.h"
#include "../includes/define.h"

void	free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] || (tab[i] != NULL))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	wall_map(t_strc *q)
{
	int	i;

	i = 0;
	while (q->tab[0][i] != 0 && q->tab[0][i] != '\n')
	{
		if (q->tab[0][i] != '1')
			q->error_2 = 1;
		i++;
	}
	i = 1;
	while (i < q->tab_y)
	{
		if (q->tab[i][0] != '1' || q->tab[i][q->tab_x - 1] != '1')
			q->error_2 = 1;
		i++;
	}
	i = 0;
	while (q->tab[q->tab_y - 1][i] != '\0' && q->tab[q->tab_y - 1][i] != '\n'
			&& i < q->tab_x)
	{
		if (q->tab[q->tab_y - 1][i] != '1')
			q->error_2 = 1;
		i++;
	}
}

void	is_pec(t_strc *q)
{
	int	i;
	int	j;

	i = 0;
	while (i < q->tab_y)
	{
		j = 0;
		while (q->tab[i][j])
		{
			if (q->tab[i][j] == 'P')
				q->nb_p++;
			if (q->tab[i][j] == 'E')
				q->nb_e++;
			if (q->tab[i][j] == 'C')
				q->nb_c++;
			j++;
		}
		i++;
	}
	if (q->nb_p != 1 || !q->nb_e || !q->nb_c)
		q->error_3 = 1;
}

void	check_map(t_strc *q)
{
	if (q->error_1)
	{
		ft_putstr_fd("ERROR\n", 2);
		ft_putstr_fd("Map configuration does not form a rectangle\n", 2);
		destroy_window(q);
	}
	if (q->error_2)
	{
		ft_putstr_fd("ERROR\n", 2);
		ft_putstr_fd("The wall is a cheese\n", 2);
		destroy_window(q);
	}
	if (q->error_3)
	{
		ft_putstr_fd("ERROR\n", 2);
		ft_putstr_fd("Map inccorect\n", 2);
		destroy_window(q);
	}
}
