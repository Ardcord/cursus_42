/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:05:39 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 11:54:25 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_move(t_strc *q)
{
	if (q->move == 1)
	{
		if (move_true_up(q))
			return (new_position(q, 1));
	}
	else if (q->move == 2)
	{
		if (move_true_down(q))
			return (new_position(q, 2));
	}
	else if (q->move == 3)
	{
		if (move_true_left(q))
			return (new_position(q, 3));
	}
	else if (q->move == 4)
	{
		if (move_true_right(q))
			return (new_position(q, 4));
	}
	return (0);
}

int	new_position(t_strc *q, int nb)
{
	if (nb == 1)
	{
		q->pos_player_y = q->pos_player_y - 1;
		q->tab[q->pos_player_y][q->pos_player_x] = 'P';
		q->tab[q->pos_player_y + 1][q->pos_player_x] = '0';
	}
	if (nb == 2)
	{
		q->pos_player_y = q->pos_player_y + 1;
		q->tab[q->pos_player_y][q->pos_player_x] = 'P';
		q->tab[q->pos_player_y - 1][q->pos_player_x] = '0';
	}
	if (nb == 3)
	{
		q->pos_player_x = q->pos_player_x - 1;
		q->tab[q->pos_player_y][q->pos_player_x] = 'P';
		q->tab[q->pos_player_y][q->pos_player_x + 1] = '0';
	}
	if (nb == 4)
	{
		q->pos_player_x = q->pos_player_x + 1;
		q->tab[q->pos_player_y][q->pos_player_x] = 'P';
		q->tab[q->pos_player_y][q->pos_player_x - 1] = '0';
	}
	return (1);
}
