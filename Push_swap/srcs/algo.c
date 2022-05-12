/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:30:23 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/09 10:38:42 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	lowlst(t_list **a, t_list **b, int len)
// {
// 	t_list	*atmp;
// 	t_list	*tmp;

// 	atmp = *a;
// 	tmp = atmp->next;
// 	if (len == 2 && *((int *)(*a)->content) > *((int *)(*a)->next->content))
// 		ft_swap_a(a);
// 	if (len == 3)
// 		ft_sort_three(a);
// 	if (len == 4)
// 		ft_sort_four(a, b);
// 	if (len == 5)
// 		ft_sort_five(a, b);
// }

void	ft_algo(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (ft_issort(*stack_a, *stack_b))
		return ;
//	if (1 < len && len < 6)
//		lowlst(stack_a, stack_b, len);
	ft_force(stack_a, stack_b);	
//	else if (len > 5)
//		ft_;
	return ;
}
