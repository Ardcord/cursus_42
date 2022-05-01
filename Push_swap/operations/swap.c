/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:49:51 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 19:56:03 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_list **a)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = *a;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **b)
{
	t_list	*tmp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = *b;
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !(*a) || !((*a)->next) || !b || !(*b) || !((*b)->next))
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = *a;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = *b;
	write(1, "ss\n", 3);
}
