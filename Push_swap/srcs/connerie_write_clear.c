/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie_write_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:44:40 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/08 14:50:56 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_ope(t_ope **head)
{
	if ((*head)->pa)
		ft_free_ope(&((*head)->pa));
	if ((*head)->pb)
		ft_free_ope(&((*head)->pb));
	if ((*head)->sa)
		ft_free_ope(&((*head)->sa));
	if ((*head)->sb)
		ft_free_ope(&((*head)->sb));
	if ((*head)->ss)
		ft_free_ope(&((*head)->ss));
	if ((*head)->ra)
		ft_free_ope(&((*head)->ra));
	if ((*head)->rb)
		ft_free_ope(&((*head)->rb));
	if ((*head)->rr)
		ft_free_ope(&((*head)->rr));
	if ((*head)->rra)
		ft_free_ope(&((*head)->rra));
	if ((*head)->rrb)
		ft_free_ope(&((*head)->rrb));
	if ((*head)->rrr)
		ft_free_ope(&((*head)->rrr));
	if (*head)
		free(*head);
	head = NULL;
}

void	ft_print_ope(t_ope *head)
{
	if (head->prev)
		ft_print_ope(head->prev);
	if (head->ope == 1)
		write(1, "pa\n", 3);
	if (head->ope == 2)
		write(1, "pb\n", 3);
	if (head->ope == 3)
		write(1, "sa\n", 3);
	if (head->ope == 4)
		write(1, "sb\n", 3);
	if (head->ope == 5)
		write(1, "ss\n", 3);
	if (head->ope == 6)
		write(1, "ra\n", 3);
	if (head->ope == 7)
		write(1, "rb\n", 3);
	if (head->ope == 8)
		write(1, "rr\n", 3);
	if (head->ope == 9)
		write(1, "rra\n", 4);
	if (head->ope == 10)
		write(1, "rrb\n", 4);
	if (head->ope == 11)
		write(1, "rrr\n", 4);
}
