/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:36:17 by efunes            #+#    #+#             */
/*   Updated: 2022/05/28 19:10:08 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_move_path(t_ope *op, t_list **a, t_list **b, short path)
{
	if (path < 1 && op->pa)
		return (ft_retry_action(a, b, op->pa, 1));
	else if (path < 2 && op->pb)
		return (ft_retry_action(a, b, op->pb, 2));
	else if (path < 3 && op->sa)
		return (ft_retry_action(a, b, op->sa, 3));
	else if (path < 4 && op->sb)
		return (ft_retry_action(a, b, op->sb, 4));
	else if (path < 5 && op->ss)
		return (ft_retry_action(a, b, op->ss, 5));
	else if (path < 6 && op->ra)
		return (ft_retry_action(a, b, op->ra, 6));
	else if (path < 7 && op->rb)
		return (ft_retry_action(a, b, op->rb, 7));
	else if (path < 8 && op->rr)
		return (ft_retry_action(a, b, op->rr, 8));
	else if (path < 9 && op->rra)
		return (ft_retry_action(a, b, op->rra, 9));
	else if (path < 10 && op->rrb)
		return (ft_retry_action(a, b, op->rrb, 10));
	else if (path < 11 && op->rrr)
		return (ft_retry_action(a, b, op->rrr, 11));
	return (NULL);
}

t_ope	*ft_move_try(t_ope *op, t_stack **sort, int *len, int *current)
{
	t_ope	*tmp;

	tmp = NULL;
	if (op && op->prev && 0 < (*current)--)
	{
		ft_reverse_action(&((*sort)->a), &((*sort)->b), op->ope);
		tmp = ft_move_path(op->prev, &((*sort)->a), &((*sort)->b), op->ope);
		if (tmp && *current < *len)
			(*current)++;
	}
	if (!tmp && op->prev && op->ope)
		return (ft_move_try(op->prev, sort, len, current));
	else if (!tmp && !(op->prev))
		return (NULL);
	if (*len == 0)
		(*len)++;
	while (*current >= 0 && *current < *len)
	{
		op = tmp;
		tmp = ft_move_path(op, &((*sort)->a), &((*sort)->b), 0);
		if (!tmp)
			return (ft_move_try(op, sort, len, current));
		(*current)++;
	}
	return (tmp);
}

t_ope	*ft_new_operation(t_ope *op, t_list **a, t_list **b)
{
	t_ope	*tmp;

	tmp = NULL;
	if (op->ope == 0)
		op = ft_operation_ini(op, tmp, a, b);
	else if (op->ope == 1)
		op = ft_operation_push_a(op, tmp, a, b);
	else if (op->ope == 2)
		op = ft_operation_push_b(op, tmp, a, b);
	else if (op->ope == 3 || op->ope == 4 || op->ope == 5)
		op = ft_operation_swap(op, tmp, a, b);
	else if (op->ope == 6)
		op = ft_operation_rotate_a(op, tmp, a, b);
	else if (op->ope == 7)
		op = ft_operation_rotate_b(op, tmp, a, b);
	else if (op->ope == 8)
		op = ft_operation_rotate_r(op, tmp, a, b);
	else if (op->ope == 9)
		op = ft_operation_reverse_rotate_a(op, tmp, a, b);
	else if (op->ope == 10)
		op = ft_operation_reverse_rotate_b(op, tmp, a, b);
	else if (op->ope == 11)
		op = ft_operation_reverse_rotate_r(op, tmp, a, b);
	return (op);
}

t_ope	*ft_reini_list(t_ope *op, t_stack *sort, int len)
{
	while (op->prev)
		op = op->prev;
	return (ft_range(op, sort, len, 0));
}

t_ope	*ft_range(t_ope *begin, t_stack *sort, int len, int check)
{
	t_ope	*new;
	t_ope	*op;

	op = begin;
	new = NULL;
	while (ft_issort(sort->a, sort->b) && op && check <= len)
	{
		while (check < len && ++check)
		{
			new = ft_move_path(op, &(sort->a), &(sort->b), 0);
			while (!new && check--)
				new = ft_move_path(op->prev, &(sort->a), &(sort->b), op->ope);
			op = new;
		}
		new = ft_new_operation(op, &(sort->a), &(sort->b));
		if (!new)
			return (ft_error(&begin));
		if (op == new)
			new = ft_move_try(op, &sort, &len, &check);
		if (!new && op)
			return (ft_reini_list(op, sort, len + 1));
		op = new;
	}
	return (new);
}
