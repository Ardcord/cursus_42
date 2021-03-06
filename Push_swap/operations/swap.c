/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:49:51 by efunes            #+#    #+#             */
/*   Updated: 2022/05/22 11:53:13 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

short	ft_swap_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void) b;
	if (!a || !(*a) || !((*a)->next) || !(*a)->next->next)
		return (-1);
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = *a;
	*a = tmp;
	return (3);
}

short	ft_swap_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void) a;
	if (!b || !(*b) || !((*b)->next) || !(*b)->next->next)
		return (-1);
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = *b;
	*b = tmp;
	return (4);
}

short	ft_swap_ss(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next) || !(*a)->next->next
		|| !b || !(*b) || !((*b)->next) || !(*b)->next->next)
		return (-1);
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = *a;
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = *b;
	*b = tmp;
	return (5);
}
