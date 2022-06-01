/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:55:50 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/31 11:07:05 by tvanbael         ###   ########.fr       */
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

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stack;

typedef struct s_sort
{
	short			method;
	int				nb;
	unsigned int	ope_a;
	unsigned int	ope_b;
}				t_sort;

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

void			ft_parser_init(int argc, char **argv, t_list **stack_a);

/*-----------------------------------Check-----------------------------------*/

int				ft_issort(t_list *a, t_list *b);

/*-----------------------------------Algo------------------------------------*/

t_ope			*ft_algo(t_ope *begin, t_stack *sort);
t_ope			*ft_force_a(t_ope *begin, t_stack *sort);
t_sort			ft_how_to_sort(t_stack *sort);
t_ope			*ft_quick_sort(t_ope *op, t_sort move, t_stack *sort);
void			ft_method_a(t_stack *sort, t_sort *a);
void			ft_method_b(t_stack *sort, t_sort *b);
void			ft_ini_sort(t_sort *how, short method,
					int nb, unsigned int ini);
void			ft_method_c(t_stack *sort, t_sort *c);
void			ft_method_d(t_stack *sort, t_sort *d);
void			ft_free_ope(t_ope **head);
void			ft_print_ope(t_ope *head);
t_ope			*ft_new_op(t_ope **head, short shot);
t_ope			*ft_error(t_ope **a);
t_ope			*ft_how_rotate(t_ope *op, t_stack *sort);
void			ft_change_sort(t_sort *a, t_sort tmp);
t_ope			*ft_force_a(t_ope *begin, t_stack *sort);
unsigned int	ft_lstmin(t_list *a);
int				ft_lstminvalue(t_list *a);

/*---------------------------------Operations--------------------------------*/

t_ope			*ft_try_push_a(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_push_b(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_swap_a(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_swap_b(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_swap_ss(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_rotate_a(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_rotate_b(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_rotate_r(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_reverse_rotate_a(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_reverse_rotate_b(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_reverse_rotate_r(t_ope *ope, t_list **a, t_list **b);
t_ope			*ft_try_a_b(t_ope *ope, t_ope *tmp, t_list **a, t_list **b);
t_ope			*ft_operation_ini(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_try_only_swap(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_swap(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_push_a(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_push_b(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_rotate_a(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_rotate_b(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_rotate_r(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_reverse_rotate_a(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_reverse_rotate_b(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);
t_ope			*ft_operation_reverse_rotate_r(t_ope *ope, t_ope *tmp,
					t_list **a, t_list **b);

void			ft_reverse_action(t_list **a, t_list **b, short path);
t_ope			*ft_retry_action(t_list **a, t_list **b,
					t_ope *ope, short path);
t_ope			*ft_move_path(t_ope *op, t_list **a, t_list **b, short path);
t_ope			*ft_move_try(t_ope *op, t_stack **sort, int *len, int *current);
t_ope			*ft_new_operation(t_ope *op, t_list **a, t_list **b);
t_ope			*ft_reini_list(t_ope *op, t_stack *sort, int len);
t_ope			*ft_range(t_ope *begin, t_stack *sort, int len, int check);

short			ft_all(t_list **a, t_list **b);
short			ft_push_a(t_list **a, t_list **b);
short			ft_push_b(t_list **a, t_list **b);
short			ft_swap_a(t_list **a, t_list **b);
short			ft_swap_b(t_list **a, t_list **b);
short			ft_swap_ss(t_list **a, t_list **b);
short			ft_rotate_a(t_list **a, t_list **b);
short			ft_rotate_b(t_list **a, t_list **b);
short			ft_rotate_r(t_list **a, t_list **b);
short			ft_reverse_rotate_a(t_list **a, t_list **b);
short			ft_reverse_rotate_b(t_list **a, t_list **b);
short			ft_reverse_rotate_r(t_list **a, t_list **b);

/*-------------------------------------BONUS---------------------------------*/

int				checker(int argc, char **argv);
void			lst_clear_error(t_list **stack_a);
void			ft_do_op(t_list **a, t_list **b, char *op);

#endif
