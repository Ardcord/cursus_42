/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:57:18 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/09 10:39:47 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_list **first)
{
	t_list	*second;
	t_list	*third;

	second = (*first)->next;
	third = (*first)->next->next;
	if (*((int *)(*first)->content) > *((int *)second->content))
	{	
		if ((*((int *)third->content) > *((int *)(*first)->content))
			|| (*((int *)second->content) > *((int *)third->content)))
		{
			ft_swap_a(first);
			ft_sort_three(first);
		}
		else
			ft_rotate_a(first);
	}
	else
	{
		if (*((int *)third->content) > *((int *)second->content))
			return ;
		ft_reverse_rotate_a(first);
		ft_sort_three(first);
	}
}
