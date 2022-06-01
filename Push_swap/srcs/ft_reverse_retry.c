/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_retry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:54:45 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 12:20:27 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_action(t_list **a, t_list **b, short path)
{
	if (path == 1)
		(void) ft_push_b(a, b);
	else if (path == 2)
		(void) ft_push_a(a, b);
	else if (path == 3)
		(void) ft_swap_a(a, b);
	else if (path == 4)
		(void) ft_swap_b(a, b);
	else if (path == 5)
		(void) ft_swap_ss(a, b);
	else if (path == 6)
		(void) ft_reverse_rotate_a(a, b);
	else if (path == 7)
		(void) ft_reverse_rotate_b(a, b);
	else if (path == 8)
		(void) ft_reverse_rotate_r(a, b);
	else if (path == 9)
		(void) ft_rotate_a(a, b);
	else if (path == 10)
		(void) ft_rotate_b(a, b);
	else if (path == 11)
		(void) ft_rotate_r(a, b);
}

t_ope	*ft_retry_action(t_list **a, t_list **b, t_ope *ope, short path)
{
	if (path == 1)
		(void) ft_push_a(a, b);
	else if (path == 2)
		(void) ft_push_b(a, b);
	else if (path == 3)
		(void) ft_swap_a(a, b);
	else if (path == 4)
		(void) ft_swap_b(a, b);
	else if (path == 5)
		(void) ft_swap_ss(a, b);
	else if (path == 6)
		(void) ft_rotate_a(a, b);
	else if (path == 7)
		(void) ft_rotate_b(a, b);
	else if (path == 8)
		(void) ft_rotate_r(a, b);
	else if (path == 9)
		(void) ft_reverse_rotate_a(a, b);
	else if (path == 10)
		(void) ft_reverse_rotate_b(a, b);
	else if (path == 11)
		(void) ft_reverse_rotate_r(a, b);
	return (ope);
}
