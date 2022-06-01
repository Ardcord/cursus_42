/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:46:57 by efunes            #+#    #+#             */
/*   Updated: 2022/05/30 19:28:50 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*ft_end_reverse(t_ope *op, t_stack *sort, int time)
{
	while (time--)
	{
		op->rra = ft_new_op(&op, 9);
		op = ft_retry_action(&sort->a, &sort->b, op, 9);
		op = op->rra;
	}
	return (op);
}

static t_ope	*ft_end_rotate(t_ope *op, t_stack *sort, int time)
{
	while (time--)
	{
		op->ra = ft_new_op(&op, 6);
		op = ft_retry_action(&sort->a, &sort->b, op, 6);
		op = op->ra;
	}
	return (op);
}

t_ope	*ft_how_rotate(t_ope *op, t_stack *sort)
{
	int		len;
	int		size;
	t_list	*a;

	a = sort->a;
	size = ft_lstsize(sort->a);
	len = 0;
	while (a && a->next && *(int *)a->content < *(int *)a->next->content)
	{
		a = a->next;
		len++;
	}
	if (a->next)
		len++;
	if (len > size - len)
		return (ft_end_reverse(op, sort, size - len));
	return (ft_end_rotate(op, sort, len));
}
