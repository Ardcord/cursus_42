/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:34:45 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 19:57:35 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*n_last;

	if (!a || !((*a) || !(*a)->next))
		return ;
	tmp = ft_lstlast(*a);
	n_last = *a;
	while (n_last->next != tmp)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_list **b)
{
	t_list	*tmp;
	t_list	*n_last;

	if (!b || (!(*b) || !(*b)->next))
		return ;
	tmp = ft_lstlast(*b);
	n_last = *b;
	while (n_last->next != tmp)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_r(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*n_last;

	if (!a || !(*a) || !((*a)->next) || !b || !(*b) || !((*b)->next))
		return ;
	tmp = ft_lstlast(*a);
	n_last = *a;
	while (n_last->next != tmp)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	tmp = ft_lstlast(*b);
	n_last = *b;
	while (n_last->next != tmp)
		n_last = n_last->next;
	n_last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	write(1, "rrr\n", 4);
}
