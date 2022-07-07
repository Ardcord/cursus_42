/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:52:03 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 19:30:29 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int keycode, void *param)
{
	t_strc	*q;

	q = (t_strc *)param;
	if (keycode == ESC)
	{
		free_map(q->tab);
		exit (0);
	}
	if (keycode == W)
		player_up(q);
	if (keycode == S)
		player_down(q);
	if (keycode == A)
		player_left(q);
	if (keycode == D)
		player_right(q);
	return (0);
}

void	player_up(t_strc *q)
{
	q->move = 1;
	if (!next_move(q))
		return ;
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.floor,
		q->pos_player_x * TILE_X, ((q->pos_player_y + 1) * TILE_Y));
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.player_up,
		q->pos_player_x * TILE_X, q->pos_player_y * TILE_Y);
	q->movement++;
	ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
	ft_putstr_fd("Movement: ", 1);
	ft_printf("%d", q->movement);
}

void	player_down(t_strc *q)
{
	q->move = 2;
	if (!next_move(q))
		return ;
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.floor,
		q->pos_player_x * TILE_X, ((q->pos_player_y - 1) * TILE_Y));
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.player_down,
		q->pos_player_x * TILE_X, q->pos_player_y * TILE_Y);
	q->movement++;
	ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
	ft_putstr_fd("Movement: ", 1);
	ft_printf("%d", q->movement);
}

void	player_left(t_strc *q)
{
	q->move = 3;
	if (!next_move(q))
		return ;
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.floor,
		((q->pos_player_x + 1) * TILE_X), q->pos_player_y * TILE_Y);
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.player_left,
		(q->pos_player_x) * TILE_X, q->pos_player_y * TILE_Y);
	q->movement++;
	ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
	ft_putstr_fd("Movement: ", 1);
	ft_printf("%d", q->movement);
}

void	player_right(t_strc *q)
{
	q->move = 4;
	if (!next_move(q))
		return ;
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.floor,
		((q->pos_player_x - 1) * TILE_X), q->pos_player_y * TILE_Y);
	mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.player_right,
		q->pos_player_x * TILE_X, q->pos_player_y * TILE_Y);
	q->movement++;
	ft_putstr_fd("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 1);
	ft_putstr_fd("Movement: ", 1);
	ft_printf("%d", q->movement);
}
