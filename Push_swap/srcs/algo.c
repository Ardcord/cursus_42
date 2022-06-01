/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:30:23 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/30 19:31:50 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_force_a(t_ope *begin, t_stack *sort)
{
	t_sort	move;

	while (sort->a && sort->a->next && sort->a->next->next)
	{
		begin->pb = ft_new_op(&begin, 2);
		begin = ft_retry_action(&sort->a, &sort->b, begin, 2);
		begin = begin->pb;
	}
	while (sort->b)
	{
		move = ft_how_to_sort(sort);
		begin = ft_quick_sort(begin, move, sort);
	}
	if (ft_issort(sort->a, sort->b))
		return (ft_how_rotate(begin, sort));
	return (begin);
}

t_ope	*ft_algo(t_ope *begin, t_stack *sort)
{
	int	len;

	len = ft_lstsize(sort->a);
	if (!ft_issort(sort->a, sort->b))
		return (begin);
	if (1 < len && len < 7)
		return (ft_range(begin, sort, 0, 0));
	return (ft_force_a(begin, sort));
}
