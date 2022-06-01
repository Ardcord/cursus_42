/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:34:45 by efunes            #+#    #+#             */
/*   Updated: 2022/05/22 11:52:58 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

short	ft_rotate_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void) b;
	if (!a || !(*a) || !((*a)->next))
		return (-1);
	tmp = (*a)->next;
	(*a)->next = NULL;
	(ft_lstlast(tmp))->next = *a;
	*a = tmp;
	return (6);
}

short	ft_rotate_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void) a;
	if (!b || !(*b) || !((*b)->next))
		return (-1);
	tmp = (*b)->next;
	(*b)->next = NULL;
	(ft_lstlast(tmp))->next = *b;
	*b = tmp;
	return (7);
}

short	ft_rotate_r(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next) || !b || !(*b) || !((*b)->next))
		return (-1);
	tmp = (*a)->next;
	(*a)->next = NULL;
	(ft_lstlast(tmp))->next = *a;
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(ft_lstlast(tmp))->next = *b;
	*b = tmp;
	return (8);
}
