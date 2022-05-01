/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:41:59 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 18:53:02 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !b || !(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	b = a;
	*a = tmp;
	write(1, "pb\n", 3);
}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!b || !a || !(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	a = b;
	*b = tmp;
	write(1, "pa\n", 3);
}
