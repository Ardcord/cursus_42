/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:11:46 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 19:39:01 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_parse_swap(t_list **a, t_list **b, char *op,
		void (*del)(void *))
{
	if (op[1] == 'a')
		ft_swap_a(a);
	else if (op[1] == 'b')
		ft_swap_b(b);
	else if (op[1] == 's')
		ft_swap_ss(a, b);
	else
	{
		ft_lstclear(b, del);
		lst_clear_error(a);
	}
}

static void	ft_parse_push(t_list **a, t_list **b, char *op,
		void (*del)(void *))
{
	if (op[1] == 'a')
		ft_push_a(a, b);
	else if (op[1] == 'b')
		ft_push_b(a, b);
	else
	{
		ft_lstclear(b, del);
		lst_clear_error(a);
	}
}

static void	ft_parse_rotate(t_list **a, t_list **b, char *op,
		void (*del)(void *))
{
	if (op[1] == 'a')
		ft_rotate_a(a);
	else if (op[1] == 'b')
		ft_rotate_b(b);
	else if (op[1] == 'r')
		ft_rotate_r(a, b);
	else
	{
		ft_lstclear(b, del);
		lst_clear_error(a);
	}
}

static void	ft_parse_reverse_rotate(t_list **a, t_list **b, char *op,
		void (*del)(void *))
{
	if (op[2] == 'a')
		ft_reverse_rotate_a(a);
	else if (op[2] == 'b')
		ft_reverse_rotate_b(b);
	else if (op[2] == 'r')
		ft_reverse_rotate_r(a, b);
	else
	{
		ft_lstclear(b, del);
		lst_clear_error(a);
	}
}

void	ft_do_op(t_list **a, t_list **b, char *op)
{
	void	(*ftc)(void *);

	ftc = &ft_void;
	if ((op[0] == 's') && !(op[2]))
		ft_parse_push(a, b, op, ftc);
	else if (op[0] == 'p' && !(op[2]))
		ft_parse_swap(a, b, op, ftc);
	else if (op[0] == 'r' && !(op[2]))
		ft_parse_rotate(a, b, op, ftc);
	else if (op[0] == 'r' && op[1] == 'r' && !(op[3]))
		ft_parse_rotate(a, b, op, ftc);
	else
	{
		ft_lstclear(b, ftc);
		lst_clear_error(a);
	}
}
