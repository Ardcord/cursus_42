/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:55:50 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/09 10:36:26 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"

// # define OPE_ALL ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_rotate_r, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_r, a, b)

// # define OPE_PUSH ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_rotate_r, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_r, a, b)

// # define OPE_SWAP ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_rotate_r, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_r, a, b)

// # define OPE_RA ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_b, a, b)

// # define OPE_RB ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_a, a, b)

// # define OPE_RR ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_rotate_r, a, b)

// # define OPE_RRA ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_a, a, b)

// # define OPE_RRB ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_b, a, b)

// # define OPE_RRR ft_brut(head, &ft_push_a, a, b) \
// 					|| ft_brut(head, &ft_push_b, a, b) \
// 					|| ft_brut(head, &ft_swap_a, a, b) \
// 					|| ft_brut(head, &ft_swap_b, a, b) \
// 					|| ft_brut(head, &ft_swap_ss, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_a, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_b, a, b) \
// 					|| ft_brut(head, &ft_reverse_rotate_r, a, b)

# define OPE_ALL ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 6, a, b) \
					|| ft_brut(head, 7, a, b) \
					|| ft_brut(head, 8, a, b) \
					|| ft_brut(head, 9, a, b) \
					|| ft_brut(head, 10, a, b) \
					|| ft_brut(head, 11, a, b)

# define OPE_PUSH ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 6, a, b) \
					|| ft_brut(head, 7, a, b) \
					|| ft_brut(head, 8, a, b) \
					|| ft_brut(head, 9, a, b) \
					|| ft_brut(head, 10, a, b) \
					|| ft_brut(head, 11, a, b)

# define OPE_SWAP ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 6, a, b) \
					|| ft_brut(head, 7, a, b) \
					|| ft_brut(head, 8, a, b) \
					|| ft_brut(head, 9, a, b) \
					|| ft_brut(head, 10, a, b) \
					|| ft_brut(head, 11, a, b)

# define OPE_RA ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 6, a, b) \
					|| ft_brut(head, 10, a, b)

# define OPE_RB ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 7, a, b) \
					|| ft_brut(head, 9, a, b)

# define OPE_RR ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 6, a, b) \
					|| ft_brut(head, 7, a, b) \
					|| ft_brut(head, 8, a, b)

# define OPE_RRA ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 7, a, b) \
					|| ft_brut(head, 9, a, b)

# define OPE_RRB ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 6, a, b) \
					|| ft_brut(head, 10, a, b)

# define OPE_RRR ft_brut(head, 1, a, b) \
					|| ft_brut(head, 2, a, b) \
					|| ft_brut(head, 3, a, b) \
					|| ft_brut(head, 4, a, b) \
					|| ft_brut(head, 5, a, b) \
					|| ft_brut(head, 9, a, b) \
					|| ft_brut(head, 10, a, b) \
					|| ft_brut(head, 11, a, b)

typedef struct s_index
{
	int	i;
	int	j;
}				t_index;

typedef struct s_ope
{
	short			ope;
	struct s_ope	*prev;
	struct s_ope	*pa;
	struct s_ope	*pb;
	struct s_ope	*sa;
	struct s_ope	*sb;
	struct s_ope	*ss;
	struct s_ope	*ra;
	struct s_ope	*rb;
	struct s_ope	*rr;
	struct s_ope	*rra;
	struct s_ope	*rrb;
	struct s_ope	*rrr;
}				t_ope;

/*----------------------------------Launch-----------------------------------*/

void	ft_parser_init(int argc, char **argv, t_list **stack_a);

/*-----------------------------------Check-----------------------------------*/

int		ft_issort(t_list *a, t_list *b);
void	lst_clear_error(t_list **stack_a);

/*-----------------------------------Algo------------------------------------*/

void	ft_algo(t_list **stack_a, t_list **stack_b);
void	ft_sort_three(t_list **first);
void	ft_sort_four(t_list **a, t_list **b);
void	ft_sort_five(t_list **a, t_list **b);

/*---------------------------------Operations--------------------------------*/

// void	ft_push_a(t_list **a, t_list **b);
// void	ft_push_b(t_list **a, t_list **b);
// void	ft_swap_a(t_list **a);
// void	ft_swap_b(t_list **b);
// void	ft_swap_ss(t_list **a, t_list **b);
// void	ft_rotate_a(t_list **a);
// void	ft_rotate_b(t_list **b);
// void	ft_rotate_r(t_list **a, t_list **b);
// void	ft_reverse_rotate_a(t_list **a);
// void	ft_reverse_rotate_b(t_list **b);
// void	ft_reverse_rotate_r(t_list **a, t_list **b);

short	ft_all(t_list **a, t_list **b);
short	ft_push_a(t_list **a, t_list **b);
short	ft_push_b(t_list **a, t_list **b);
short	ft_swap_a(t_list **a, t_list **b);
short	ft_swap_b(t_list **a, t_list **b);
short	ft_swap_ss(t_list **a, t_list **b);
short	ft_rotate_a(t_list **a, t_list **b);
short	ft_rotate_b(t_list **a, t_list **b);
short	ft_rotate_r(t_list **a, t_list **b);
short	ft_reverse_rotate_a(t_list **a, t_list **b);
short	ft_reverse_rotate_b(t_list **a, t_list **b);
short	ft_reverse_rotate_r(t_list **a, t_list **b);

/*-------------------------------------BONUS---------------------------------*/

int		checker(int argc, char **argv);
void	ft_do_op(t_list **a, t_list **b, char *op);

/*------------------------------------Connerie-------------------------------*/

void	ft_free_ope(t_ope **head);
void	ft_print_ope(t_ope *head);
void	ft_force(t_list **a, t_list **b);

#endif