/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:56:05 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/06 16:52:02 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/struct.h"
#include "../includes/define.h"

int	main(int argc, char **argv)
{
	t_strc		q;

	if (argc != 2)
		ft_putstr_fd("ERROR, to few arguments\n", 2);
	else if ((argv[1][ft_strlen(argv[1]) - 1] == 'r')
		&& (argv[1][ft_strlen(argv[1]) - 2] == 'e')
		&& (argv[1][ft_strlen(argv[1]) - 3] == 'b')
		&& (argv[1][ft_strlen(argv[1]) - 4] == '.'))
	{
		ft_init_strc(&q);
		q.path = argv[1];
		open_window(&q);
	}
	ft_putstr_fd("Error\nMaps while be named xXxXx.ber", 2);
	return (0);
}

void	ft_init_strc(t_strc *q)
{
	q->tab_x = 0;
	q->tab_y = 0;
	q->fd = 0;
	q->pos_x = 0;
	q->pos_y = 0;
	q->error_1 = 0;
	q->error_2 = 0;
	q->error_3 = 0;
	q->nb_c = 0;
	q->nb_e = 0;
	q->nb_p = 0;
	q->temp = 0;
	q->path = NULL;
	q->gnl = NULL;
	q->move = 0;
	q->nm_pos_x = 0;
	q->nm_pos_y = 0;
	q->nb_collect = 0;
	q->movement = 0;
}

void	the_end(t_strc *q)
{
	q->movement++;
	ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
	ft_putstr_fd("hey you finished in ", 1);
	ft_printf("%d moves\n", q->movement);
	destroy_window(q);
}
