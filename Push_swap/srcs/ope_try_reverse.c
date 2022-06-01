/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_try_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:25:39 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 11:07:13 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_try_reverse_rotate_a(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next)
	{
		ope->rra = ft_new_op(&ope, 9);
		if (!(ope->rra))
			return (NULL);
		if (ft_reverse_rotate_a(a, b) < 0)
		{
			free(ope->rra);
			ope->rra = NULL;
			return (ope);
		}
		if (ope->rra && !ft_issort(*a, *b))
			return (ope->rra);
		(void)ft_rotate_a(a, b);
	}
	return (ope);
}

t_ope	*ft_try_reverse_rotate_b(t_ope *ope, t_list **a, t_list **b)
{
	if (*b && (*b)->next)
	{
		ope->rrb = ft_new_op(&ope, 10);
		if (!(ope->rrb))
			return (NULL);
		if (ft_reverse_rotate_b(a, b) < 0)
		{
			free(ope->rrb);
			ope->rrb = NULL;
			return (ope);
		}
		if (ope->rrb && !ft_issort(*a,*b))
			return (ope->rrb);
		(void)ft_rotate_b(a, b);
	}
	return (ope);
}

t_ope	*ft_try_reverse_rotate_r(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		ope->rrr = ft_new_op(&ope, 11);
		if (!(ope->rrr))
			return (NULL);
		if (ft_reverse_rotate_r(a, b) < 0)
		{
			free(ope->rrr);
			ope->rrr = NULL;
			return (ope);
		}
		if (ope->rrr && !ft_issort(*a, *b))
			return (ope->rrr);
		(void)ft_rotate_r(a, b);
	}
	return (ope);
}
