/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:34:45 by efunes            #+#    #+#             */
/*   Updated: 2022/05/22 11:52:39 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

short	ft_reverse_rotate_a(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*n_last;

	(void) b;
	if (!(a && *a && (*a)->next))
		return (-1);
	tmp = ft_lstlast(*a);
	n_last = *a;
	while (n_last->next && n_last->next->next)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	return (9);
}

short	ft_reverse_rotate_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*n_last;

	(void) a;
	if (!b || (!(*b) || !(*b)->next))
		return (-1);
	tmp = ft_lstlast(*b);
	n_last = *b;
	while (n_last->next && n_last->next->next)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	return (10);
}

short	ft_reverse_rotate_r(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*n_last;

	if (!a || !(*a) || !((*a)->next) || !b || !(*b) || !((*b)->next))
		return (-1);
	tmp = ft_lstlast(*a);
	n_last = *a;
	while (n_last->next && n_last->next->next)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	tmp = ft_lstlast(*b);
	n_last = *b;
	while (n_last->next && n_last->next->next)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	return (11);
}
