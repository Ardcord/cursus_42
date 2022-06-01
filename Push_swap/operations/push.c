/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:41:59 by efunes            #+#    #+#             */
/*   Updated: 2022/05/22 11:52:10 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

short	ft_push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!b || !a || !(*b))
		return (-1);
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

short	ft_push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !b || !(*a))
		return (-1);
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	return (2);
}

short	ft_all(t_list **a, t_list **b)
{
	(void) a;
	(void) b;
	return (0);
}
