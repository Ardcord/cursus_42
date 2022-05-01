/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:34:45 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 19:59:30 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_list **a)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->next;
	(*a)->next = NULL;
	(ft_lstlast(tmp))->next = *a;
//	ft_lstadd_back(&tmp, *a);
	*a = tmp;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **b)
{
	t_list	*tmp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->next;
	(*b)->next = NULL;
	(ft_lstlast(tmp))->next = *b;
//	ft_lstadd_back(&tmp, b);
	*b = tmp;
	write(1, "rb\n", 3);
}

void	ft_rotate_r(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next) || !b || !(*b) || !((*b)->next))
		return ;
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
	write(1, "rr\n", 3);
}
