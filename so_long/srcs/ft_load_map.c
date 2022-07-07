/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:24:00 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 14:34:08 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/struct.h"
#include "../includes/define.h"

void	load_images(t_strc *q)
{
	q->images.player_up = mlx_xpm_file_to_image(q->mlx_ptr, PERSO_UP,
			&q->images.width, &q->images.height);
	q->images.player_down = mlx_xpm_file_to_image(q->mlx_ptr, PERSO_DOWN,
			&q->images.width, &q->images.height);
	q->images.player_left = mlx_xpm_file_to_image(q->mlx_ptr, PERSO_LEFT,
			&q->images.width, &q->images.height);
	q->images.player_right = mlx_xpm_file_to_image(q->mlx_ptr, PERSO_RIGHT,
			&q->images.width, &q->images.height);
	q->images.collect = mlx_xpm_file_to_image(q->mlx_ptr, COLLECT,
			&q->images.width, &q->images.height);
	q->images.floor = mlx_xpm_file_to_image(q->mlx_ptr, FLOOR,
			&q->images.width, &q->images.height);
	q->images.walls = mlx_xpm_file_to_image(q->mlx_ptr, WALL,
			&q->images.width, &q->images.height);
	q->images.exitmap = mlx_xpm_file_to_image(q->mlx_ptr, EXITMAP,
			&q->images.width, &q->images.height);
}

void	put_map(t_strc *q)
{
	int	i;
	int	j;

	i = 0;
	while (i < q->tab_y)
	{
		j = 0;
		while (j <= q->tab_x)
		{
			q->pos_x = j;
			q->pos_y = i;
			if (q->tab[i][j] == '0' || q->tab[i][j] == '1' ||
				q->tab[i][j] == 'C' || q->tab[i][j] == 'E' ||
				q->tab[i][j] == 'P')
				char_img(q, q->tab[i][j]);
			j++;
		}
		i++;
	}
}

void	char_img(t_strc *q, char c)
{
	if (c == '0')
		mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.floor,
			q->pos_x * TILE_X, q->pos_y * TILE_Y);
	else if (c == '1')
		mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.walls,
			(q->pos_x * TILE_X), (q->pos_y * TILE_Y));
	else if (c == 'P')
	{
		q->pos_player_x = q->pos_x;
		q->pos_player_y = q->pos_y;
		mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.player_up,
			q->pos_x * TILE_X, q->pos_y * TILE_Y);
	}
	else if (c == 'E')
		mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.exitmap,
			q->pos_x * TILE_X, q->pos_y * TILE_Y);
	else if (c == 'C')
		mlx_put_image_to_window(q->mlx_ptr, q->mlx_win, q->images.collect,
			q->pos_x * TILE_X, q->pos_y * TILE_Y);
}
