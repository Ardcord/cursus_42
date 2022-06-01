/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_try_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:25:16 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 11:57:29 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_try_swap_a(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next && (*a)->next->next)
	{
		ope->sa = ft_new_op(&ope, 3);
		if (!(ope->sa))
			return (NULL);
		if (ft_swap_a(a, b) < 0)
		{
			free(ope->sa);
			ope->sa = NULL;
			return (ope);
		}
		if (ope->sa && !ft_issort(*a, *b))
			return (ope->sa);
		(void)ft_swap_a(a, b);
	}
	return (ope);
}

t_ope	*ft_try_swap_b(t_ope *ope, t_list **a, t_list **b)
{
	if (*b && (*b)->next && (*b)->next->next)
	{
		ope->sb = ft_new_op(&ope, 4);
		if (!(ope->sb))
			return (NULL);
		if (ft_swap_b(a, b) < 0)
		{
			free(ope->sb);
			ope->sb = NULL;
			return (ope);
		}
		if (ope->sb && !ft_issort(*a, *b))
			return (ope->sb);
		(void)ft_swap_b(a, b);
	}
	return (ope);
}

t_ope	*ft_try_swap_ss(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next && (*a)->next->next
		&& *b && (*b)->next && (*b)->next->next)
	{
		ope->ss = ft_new_op(&ope, 5);
		if (!(ope->ss))
			return (NULL);
		if (ft_swap_ss(a, b) < 0)
		{
			free(ope->ss);
			ope->ss = NULL;
			return (ope);
		}
		if (ope->ss && !ft_issort(*a, *b))
			return (ope->ss);
		(void)ft_swap_ss(a, b);
	}
	return (ope);
}
