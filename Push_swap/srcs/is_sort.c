/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 10:57:32 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 17:56:24 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_issort(t_list *a, t_list *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if ((int)(a->content) > (int)(a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}
