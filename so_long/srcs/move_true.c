/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_true.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:13:45 by tvanbael          #+#    #+#             */
/*   Updated: 2022/07/04 12:02:34 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_true_up(t_strc *q)
{
	if (q->tab[q->pos_player_y - 1][q->pos_player_x] == '1')
		return (0);
	else if (q->tab[q->pos_player_y - 1][q->pos_player_x] == '0')
		return (1);
	else if (q->tab[q->pos_player_y - 1][q->pos_player_x] == 'C')
	{
		q->nb_collect++;
		return (1);
	}
	else if (q->tab[q->pos_player_y - 1][q->pos_player_x] == 'E')
	{
		if (check_count(q))
			the_end(q);
		else
			return (0);
	}
	return (0);
}

int	move_true_down(t_strc *q)
{
	if (q->tab[q->pos_player_y + 1][q->pos_player_x] == '1')
		return (0);
	else if (q->tab[q->pos_player_y + 1][q->pos_player_x] == '0')
		return (1);
	else if (q->tab[q->pos_player_y + 1][q->pos_player_x] == 'C')
	{
		q->nb_collect++;
		return (1);
	}
	else if (q->tab[q->pos_player_y + 1][q->pos_player_x] == 'E')
	{
		if (check_count(q))
			the_end(q);
		else
			return (0);
	}
	return (0);
}

int	move_true_left(t_strc *q)
{
	if (q->tab[q->pos_player_y][q->pos_player_x - 1] == '1')
		return (0);
	else if (q->tab[q->pos_player_y][q->pos_player_x - 1] == '0')
		return (1);
	else if (q->tab[q->pos_player_y][q->pos_player_x - 1] == 'C')
	{
		q->nb_collect++;
		return (1);
	}
	else if (q->tab[q->pos_player_y][q->pos_player_x - 1] == 'E')
	{
		if (check_count(q))
			the_end(q);
		else
			return (0);
	}
	return (0);
}

int	move_true_right(t_strc *q)
{
	if (q->tab[q->pos_player_y][q->pos_player_x + 1] == '1')
		return (0);
	else if (q->tab[q->pos_player_y][q->pos_player_x + 1] == '0')
		return (1);
	else if (q->tab[q->pos_player_y][q->pos_player_x + 1] == 'C')
	{
		q->nb_collect++;
		return (1);
	}
	else if (q->tab[q->pos_player_y][q->pos_player_x + 1] == 'E')
	{
		if (check_count(q))
			the_end(q);
		else
			return (0);
	}
	return (0);
}

int	check_count(t_strc *q)
{
	if (q->nb_collect == q->nb_c)
		return (1);
	else
		return (0);
}
