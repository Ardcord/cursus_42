/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:37:10 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/31 10:24:37 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lst_clear_error(t_list **stack_a)
{
	ft_lstclear(stack_a, free);
	write(2, "Error\n", 6);
	exit (0);
}
