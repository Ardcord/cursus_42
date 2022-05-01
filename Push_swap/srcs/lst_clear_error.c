/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:37:10 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/01 20:38:26 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lst_clear_error(t_list **stack_a)
{
	void	(*ftc)(void *);

	ftc = &ft_void;
	ft_lstclear(stack_a, ftc);
	write(1, "lceError3\n", 10);
	exit (0);
}
