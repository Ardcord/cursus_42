/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:47:07 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/16 16:57:26 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_new_op(t_ope **head, short shot)
{
	t_ope	*new;

	new = malloc(sizeof(t_ope));
	new->ope = shot;
	new->pa = NULL;
	new->pb = NULL;
	new->sa = NULL;
	new->sb = NULL;
	new->ss = NULL;
	new->ra = NULL;
	new->rb = NULL;
	new->rr = NULL;
	new->rra = NULL;
	new->rrb = NULL;
	new->rrr = NULL;
	if (*head)
		new->prev = *head;
	else
		new->prev = NULL;
	return (new);
}
