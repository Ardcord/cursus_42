/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:34:45 by efunes            #+#    #+#             */
/*   Updated: 2022/05/05 14:24:25 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

short	ft_rotate_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void) b;
	if (!a || !(*a) || !((*a)->next))
		return (0);
	tmp = (*a)->next;
	(*a)->next = NULL;
	(ft_lstlast(tmp))->next = *a;
//	ft_lstadd_back(&tmp, *a);
	*a = tmp;
	return (6);
}

short	ft_rotate_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void) a;
	if (!b || !(*b) || !((*b)->next))
		return (0);
	tmp = (*b)->next;
	(*b)->next = NULL;
	(ft_lstlast(tmp))->next = *b;
//	ft_lstadd_back(&tmp, b);
	*b = tmp;
	return (7);
}

short	ft_rotate_r(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next) || !b || !(*b) || !((*b)->next))
		return (0);
	tmp = (*a)->next;
	(*a)->next = NULL;
	(ft_lstlast(tmp))->next = *a;
//	ft_lstadd_back(&tmp, *a);
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(ft_lstlast(tmp))->next = *b;
//	ft_lstadd_back(&tmp, *b);
	*b = tmp;
	return (8);
}
