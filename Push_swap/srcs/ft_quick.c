/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:29:20 by efunes            #+#    #+#             */
/*   Updated: 2022/05/30 19:25:23 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*ft_quick_d(t_ope *op, t_sort move, t_stack *sort)
{
	while (move.nb != *(int *)sort->b->content)
	{
		op->rb = ft_new_op(&op, 7);
		op = ft_retry_action(&sort->a, &sort->b, op, 7);
		op = op->rb;
	}
	while (move.ope_a--)
	{
		op->rra = ft_new_op(&op, 9);
		op = ft_retry_action(&sort->a, &sort->b, op, 9);
		op = op->rra;
	}
	return (op);
}

static t_ope	*ft_quick_c(t_ope *op, t_sort move, t_stack *sort)
{
	if (move.method > 3)
		return (ft_quick_d(op, move, sort));
	while (move.nb != *(int *)sort->b->content)
	{
		op->rrb = ft_new_op(&op, 10);
		op = ft_retry_action(&sort->a, &sort->b, op, 10);
		op = op->rrb;
	}
	while (move.ope_a--)
	{
		op->ra = ft_new_op(&op, 6);
		op = ft_retry_action(&sort->a, &sort->b, op, 6);
		op = op->ra;
	}
	return (op);
}

static t_ope	*ft_quick_b(t_ope *op, t_sort move, t_stack *sort)
{
	while (move.nb != *(int *)sort->b->content && move.ope_a && move.ope_b--)
	{
		op->rrr = ft_new_op(&op, 11);
		op = ft_retry_action(&sort->a, &sort->b, op, 11);
		op = op->rrr;
		move.ope_a--;
	}
	while (move.nb != *(int *)sort->b->content)
	{
		op->rrb = ft_new_op(&op, 10);
		op = ft_retry_action(&sort->a, &sort->b, op, 10);
		op = op->rrb;
	}
	while (move.ope_a--)
	{
		op->rra = ft_new_op(&op, 9);
		op = ft_retry_action(&sort->a, &sort->b, op, 9);
		op = op->rra;
	}
	return (op);
}

static t_ope	*ft_quick_a(t_ope *op, t_sort move, t_stack *sort)
{
	while (move.nb != *(int *)sort->b->content && move.ope_a && move.ope_b--)
	{
		op->rr = ft_new_op(&op, 8);
		op = ft_retry_action(&sort->a, &sort->b, op, 8);
		op = op->rr;
		move.ope_a--;
	}
	while (move.nb != *(int *)sort->b->content)
	{
		op->rb = ft_new_op(&op, 7);
		op = ft_retry_action(&sort->a, &sort->b, op, 7);
		op = op->rb;
	}
	while (move.ope_a--)
	{
		op->ra = ft_new_op(&op, 6);
		op = ft_retry_action(&sort->a, &sort->b, op, 6);
		op = op->ra;
	}
	return (op);
}

t_ope	*ft_quick_sort(t_ope *op, t_sort move, t_stack *sort)
{
	if (move.method < 1 || move.method > 4)
		return (NULL);
	if (move.method == 1)
		op = ft_quick_a(op, move, sort);
	else if (move.method == 2)
		op = ft_quick_b(op, move, sort);
	else if (move.method == 3)
		op = ft_quick_c(op, move, sort);
	else if (move.method == 4)
		op = ft_quick_d(op, move, sort);
	op->pa = ft_new_op(&op, 1);
	op = ft_retry_action(&sort->a, &sort->b, op, 1);
	op = op->pa;
	return (op);
}
