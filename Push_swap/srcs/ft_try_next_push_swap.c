/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_next_push_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:53:37 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/16 16:43:59 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_operation_push_a(t_ope *ope, t_ope *tmp, t_list **a, t_list **b)
{
	tmp = ft_try_push_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_only_swap(ope, tmp, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_r(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_r(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	return (ope);
}

t_ope	*ft_operation_push_b(t_ope *ope, t_ope *tmp, t_list **a, t_list **b)
{
	tmp = ft_try_push_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_only_swap(ope, tmp, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_r(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_r(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	return (ope);
}

t_ope	*ft_operation_swap(t_ope *ope, t_ope *tmp, t_list **a, t_list **b)
{
	tmp = ft_try_push_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_push_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_r(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_r(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	return (ope);
}

t_ope	*ft_operation_ini(t_ope *ope, t_ope *tmp, t_list **a, t_list **b)
{
	tmp = ft_try_push_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	if (*a && (*a)->next && (*a)->next->next
		&& !(*(int *)((*a)->content) < *(int *)((*a)->next->content)
		&& *(int *)((*a)->content) < *(int *)((*a)->next->next->content)
		&& *(int *)((*a)->next->content) < *(int *)((*a)->next->next->content)))
	{
		tmp = ft_try_swap_a(ope, a, b);
		if (tmp && tmp != ope)
			return (tmp);
	}
	return (ope);
}
