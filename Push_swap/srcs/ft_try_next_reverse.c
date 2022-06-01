/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_next_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:47:41 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 12:22:16 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ope	*ft_operation_reverse_rotate_a(t_ope *ope, t_ope *tmp,
										t_list **a, t_list **b)
{
	tmp = ft_try_push_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_push_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_only_swap(ope, tmp, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	return (ope);
}

t_ope	*ft_operation_reverse_rotate_b(t_ope *ope, t_ope *tmp,
										t_list **a, t_list **b)
{
	tmp = ft_try_push_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_push_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_only_swap(ope, tmp, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_rotate_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_reverse_rotate_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	return (ope);
}

t_ope	*ft_operation_reverse_rotate_r(t_ope *ope, t_ope *tmp,
										t_list **a, t_list **b)
{
	tmp = ft_try_push_a(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_push_b(ope, a, b);
	if (tmp && tmp != ope)
		return (tmp);
	tmp = ft_try_only_swap(ope, tmp, a, b);
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
