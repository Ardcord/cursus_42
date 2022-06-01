/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_only_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:43:30 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 13:17:06 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_try_only_swap(t_ope *ope, t_ope *tmp, t_list **a, t_list **b)
{
	if (*a && (*a)->next && (*a)->next->next
		&& *b && (*b)->next && (*b)->next->next
		&& !(*(int *)((*a)->content) < *(int *)((*a)->next->content)
		&& *(int *)((*a)->content) < *(int *)((*a)->next->next->content)
		&& *(int *)((*a)->next->content) < *(int *)((*a)->next->next->content))
		&& !(*(int *)((*b)->content) < *(int *)((*b)->next->content)
		&& *(int *)((*b)->content) < *(int *)((*b)->next->next->content)
		&& *(int *)((*b)->next->content) < *(int *)((*b)->next->next->content)))
	{
		tmp = ft_try_swap_ss(ope, a, b);
		if (tmp && tmp != ope)
			return (tmp);
	}
	else
		return (ft_try_a_b(ope, tmp, a, b));
	return (ope);
}

t_ope	*ft_try_a_b(t_ope *ope, t_ope *tmp, t_list **a, t_list **b)
{	
	if (*a && (*a)->next && (*a)->next->next
		&& !(*(int *)((*a)->content) < *(int *)((*a)->next->content)
		&& *(int *)((*a)->content) < *(int *)((*a)->next->next->content)
		&& *(int *)((*a)->next->content) < *(int *)((*a)->next->next->content)))
	{
		tmp = ft_try_swap_a(ope, a, b);
		if (tmp && tmp != ope)
			return (tmp);
	}
	else if (*b && (*b)->next && (*b)->next->next
		&& !(*(int *)((*b)->content) < *(int *)((*b)->next->content)
		&& *(int *)((*b)->content) < *(int *)((*b)->next->next->content)
		&& *(int *)((*b)->next->content) < *(int *)((*b)->next->next->content)))
	{
		tmp = ft_try_swap_b(ope, a, b);
		if (tmp && tmp != ope)
			return (tmp);
	}
	return (ope);
}
