/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_try_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:25:34 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 12:21:05 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_try_rotate_a(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next)
	{
		ope->ra = ft_new_op(&ope, 6);
		if (!(ope->ra))
			return (NULL);
		if (ft_rotate_a(a, b) < 0)
		{
			free(ope->ra);
			ope->ra = NULL;
			return (ope);
		}
		if (ope->ra && !ft_issort(*a, *b))
			return (ope->ra);
		(void)ft_reverse_rotate_a(a, b);
	}
	return (ope);
}

t_ope	*ft_try_rotate_b(t_ope *ope, t_list **a, t_list **b)
{
	if (*b && (*b)->next)
	{
		ope->rb = ft_new_op(&ope, 7);
		if (!(ope->rb))
			return (NULL);
		if (ft_rotate_b(a, b) < 0)
		{
			free(ope->rb);
			ope->rb = NULL;
			return (ope);
		}
		if (ope->rb && !ft_issort(*a, *b))
			return (ope->rb);
		(void)ft_reverse_rotate_b(a, b);
	}
	return (ope);
}

t_ope	*ft_try_rotate_r(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		ope->rr = ft_new_op(&ope, 8);
		if (!(ope->rr))
			return (NULL);
		if (ft_rotate_r(a, b) < 0)
		{
			free(ope->rr);
			ope->rr = NULL;
			return (ope);
		}
		if (ope->rr && !ft_issort(*a, *b))
			return (ope->rr);
		(void)ft_reverse_rotate_r(a, b);
	}
	return (ope);
}
