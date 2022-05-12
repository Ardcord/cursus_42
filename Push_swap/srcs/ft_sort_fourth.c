/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_fourth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:13:27 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/09 10:38:53 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	i_need_place(t_list **a, t_list **b)
{
	ft_push_b(a, b);
	ft_push_b(a, b);
	ft_swap_ss(a, b);
	ft_push_a(a, b);
	ft_push_a(a, b);
}

static void	ft_magic_move(t_list **a, t_list **b, t_list *third, t_list *fourth)
{
	t_list	*first;
	t_list	*second;

	first = (*a);
	second = (*a)->next;
	if (first->content < third->content)
	{
		if (third->content > fourth->content
			&& first->content < fourth->content)
			i_need_place(a, b);
		else
			ft_swap_a(a);
	}
	else
	{
		if (second->content > fourth->content)
			ft_swap_a(a);
		else if (first->content < fourth->content)
			ft_reverse_rotate_a(a);
		else
			ft_rotate_a(a);
	}
}

void	ft_sort_four(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;

	first = (*a);
	second = (*a)->next;
	third = (*a)->next->next;
	fourth = (*a)->next->next->next;
	if (first->content < second->content)
	{
		if (second->content < fourth->content)
			ft_reverse_rotate_a(a);
		else if (first->content > fourth->content
			|| second->content < fourth->content)
			ft_rotate_a(a);
		else
			ft_swap_a(a);
	}
	else
		ft_magic_move(a, b, third, fourth);
	if (!ft_issort(a, b))
		ft_sort_four(a, b);
}
