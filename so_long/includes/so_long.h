/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:16:13 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 19:16:59 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "struct.h"
# include "define.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>

int		main(int argc, char **argv);
void	ft_init_strc(t_strc *q);
void	open_window(t_strc *q);
int		destroy_window(t_strc *q);
void	ft_launch(t_strc *q);
void	put_map(t_strc *q);
void	load_images(t_strc *q);
void	char_img(t_strc *q, char c);
void	char_img2(t_strc *q, char c);
int		deal_key(int keycode, void *param);
void	ft_map(int fd, t_strc *q);
void	maptab(t_strc *q);
void	put_map_in_tab(t_strc *q, int i);
void	strintab(char *tmp, char *tab);
int		ft_howmany(char *tmp, t_strc *q);
void	free_map(char **tab);
void	wall_map(t_strc *q);
void	check_map(t_strc *q);
void	ft_check_rect(t_strc *q);
void	is_pec(t_strc *q);
void	player_up(t_strc *q);
void	player_down(t_strc *q);
void	player_left(t_strc *q);
void	player_right(t_strc *q);
void	player_up(t_strc *q);
void	player_down(t_strc *q);
void	player_left(t_strc *q);
void	player_right(t_strc *q);
int		move_true_up(t_strc *q);
int		move_true_down(t_strc *q);
int		move_true_left(t_strc *q);
int		move_true_right(t_strc *q);
int		check_count(t_strc *q);
int		new_position(t_strc *q, int nb);
int		next_move(t_strc *q);
void	the_end(t_strc *q);

#endif