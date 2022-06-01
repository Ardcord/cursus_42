/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_try_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efunes <efunes@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:17:34 by efunes            #+#    #+#             */
/*   Updated: 2022/05/22 13:18:02 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_try_push_a(t_ope *ope, t_list **a, t_list **b)
{
	if (*b)
	{
		ope->pa = ft_new_op(&ope, 1);
		if (!(ope->pa))
			return (NULL);
		if (ft_push_a(a, b) < 0)
		{
			free(ope->pa);
			ope->pa = NULL;
			return (ope);
		}
		if (ope->pa && !ft_issort(*a, *b))
			return (ope->pa);
		(void)ft_push_b(a, b);
	}
	return (ope);
}

t_ope	*ft_try_push_b(t_ope *ope, t_list **a, t_list **b)
{
	if (*a && (*a)->next)
	{
		ope->pb = ft_new_op(&ope, 2);
		if (!(ope->pb))
			return (NULL);
		if (ft_push_b(a, b) < 0)
		{
			free(ope->pb);
			ope->pb = NULL;
			return (ope);
		}
		if (ope->pb && !ft_issort(*a, *b))
			return (ope->pb);
		(void)ft_push_a(a, b);
	}
	return (ope);
}
