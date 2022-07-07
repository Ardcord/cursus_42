/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:28:17 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 19:15:13 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*walls;
	void	*floor;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*collect;
	void	*exitmap;
	int		width;
	int		height;
}				t_images;

typedef struct s_strc
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			*path;
	char			*gnl;
	int				fd;
	int				keycode;
	char			**tab;
	int				tab_x;
	int				tab_y;
	int				pos_x;
	int				pos_y;
	int				pos_player_x;
	int				pos_player_y;
	int				move;
	int				nm_pos_x;
	int				nm_pos_y;
	int				error_1;
	int				error_2;
	int				error_3;
	int				nb_p;
	int				nb_e;
	int				nb_c;
	int				nb_collect;
	int				movement;
	int				temp;
	t_images		images;
}					t_strc;

#endif