/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 10:57:32 by efunes            #+#    #+#             */
/*   Updated: 2022/05/28 19:13:30 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_issort(t_list *a, t_list *b)
{
	if (b)
		return (1);
	while (a && a->next)
	{
		if (*(int *)(a->content) > *(int *)(a->next->content))
			return (1);
		a = a->next;
	}
	return (0);
}
