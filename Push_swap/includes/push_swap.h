/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:55:50 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/01 20:40:42 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"

typedef struct s_index
{
	int	i;
	int	j;
}				t_index;

void	ft_parser_init(int argc, char **argv, t_list **stack_a);
int		ft_issort(t_list *a, t_list *b);
void	lst_clear_error(t_list **stack_a);

/*---------------------------------operations---------------------------------*/

void	ft_push_a(t_list **a, t_list **b);
void	ft_push_b(t_list **a, t_list **b);
void	ft_swap_a(t_list **a);
void	ft_swap_b(t_list **b);
void	ft_swap_ss(t_list **a, t_list **b);
void	ft_reverse_rotate_a(t_list **a);
void	ft_reverse_rotate_b(t_list **b);
void	ft_rotate_r(t_list **a, t_list **b);
void	ft_rotate_a(t_list **a);
void	ft_rotate_b(t_list **b);
void	ft_rotate_ab(t_list **a, t_list **b);

/*-------------------------------------BONUS---------------------------------*/

int		checker(int argc, char **argv);
void	ft_do_op(t_list **a, t_list **b, char *op);

#endif