/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:37:10 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/04 16:24:15 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lst_clear_error(t_list **stack_a)
{
	void	(*ftc)(void *);

	ftc = &ft_void;
	ft_lstclear(stack_a, ftc);
	write(2, "Error\n", 6);
	exit (0);
}
