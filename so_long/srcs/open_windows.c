/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@qdent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:17:38 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/31 10:41:36 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/struct.h"
#include "../includes/define.h"

int	destroy_window(t_strc *q)
{
	free_map(q->tab);
	mlx_destroy_window(q->mlx_ptr, q->mlx_win);
	exit(0);
}

void	open_window(t_strc *q)
{
	q->mlx_ptr = mlx_init();
	if (q->mlx_ptr == NULL)
		exit(-1);
	ft_map(open(q->path, O_RDONLY), q);
	q->mlx_win = mlx_new_window(q->mlx_ptr, (q->tab_x * (TILE_X)),
			(q->tab_y * (TILE_Y)), "so_long");
	if (q->mlx_win == NULL)
		exit(-1);
	if (q->tab_x >= 55 || q->tab_y >= 29)
	{
		ft_putstr_fd("Error\nMap too high", 2);
		destroy_window(q);
	}
	wall_map(q);
	is_pec(q);
	q->temp = 0;
	check_map(q);
	load_images(q);
	put_map(q);
	mlx_hook(q->mlx_win, 2, (1L << 0), deal_key, q);
	mlx_hook(q->mlx_win, 17, (1L << 2), destroy_window, q);
	mlx_loop(q->mlx_ptr);
}
