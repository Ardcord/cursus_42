/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connerie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:47:07 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/08 14:58:33 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ope	*ft_new_op(t_ope **head, short shot)
{
	t_ope	*new;

	new = malloc(sizeof(t_ope));
	new->ope = shot;
	new->pa = NULL;
	new->pb = NULL;
	new->sa = NULL;
	new->sb = NULL;
	new->ss = NULL;
	new->ra = NULL;
	new->rb = NULL;
	new->rr = NULL;
	new->rra = NULL;
	new->rrb = NULL;
	new->rrr = NULL;
	if (*head)
		new->prev = *head;
	else
		new->prev = NULL;
	return (new);
}

static void	ft_loc_ptr(t_ope **head, short ope)
{
	if (ope == 1)
		(*head)->pa = ft_new_op(head, ope);
	if (ope == 2)
		(*head)->pb = ft_new_op(head, ope);
	if (ope == 3)
		(*head)->sa = ft_new_op(head, ope);
	if (ope == 4)
		(*head)->sb = ft_new_op(head, ope);
	if (ope == 5)
		(*head)->ss = ft_new_op(head, ope);
	if (ope == 6)
		(*head)->ra = ft_new_op(head, ope);
	if (ope == 7)
		(*head)->rb = ft_new_op(head, ope);
	if (ope == 8)
		(*head)->rr = ft_new_op(head, ope);
	if (ope == 9)
		(*head)->rra = ft_new_op(head, ope);
	if (ope == 10)
		(*head)->rrb = ft_new_op(head, ope);
	if (ope == 11)
		(*head)->rrr = ft_new_op(head, ope);
}

// static short	ft_operation(t_list **a, t_list **b, short ope)
// {
// 	fprintf(stderr, "debut operation, ope == %d\n", ope);
// 	if (ope == 1)
// 	{
// 		fprintf(stderr, "apres 1ere operation, ope == %d\n", ope);
// 		return (ft_push_a(a, b));
// 	}
// 	if (ope == 2)
// 		return (ft_push_b(a, b));
// 	if (ope == 3)
// 		return (ft_swap_a(a, b));
// 	if (ope == 4)
// 		return (ft_swap_b(a, b));
// 	if (ope == 5)
// 		return (ft_swap_ss(a, b));
// 	if (ope == 6)
// 		return (ft_rotate_a(a, b));
// 	if (ope == 7)
// 		return (ft_rotate_b(a, b));
// 	if (ope == 8)
// 		return (ft_rotate_r(a, b));
// 	if (ope == 9)
// 		return (ft_reverse_rotate_a(a, b));
// 	if (ope == 10)
// 		return (ft_reverse_rotate_b(a, b));
// 	if (ope == 11)
// 		return (ft_reverse_rotate_r(a, b));
// 	else
// 		return (0);
// }

int i = 0;
int j = 0;

static int	ft_brut(t_ope **head, short ope,
				t_list **a, t_list **b)
{
	short	prev;
	(void) ope;

//	prev = ft_operation(a, b, ope);
	prev = ft_swap_a(a, b);
	fprintf(stderr, "a %d a->next %d\n", *((int*)(*a)->content), *((int*)(*a)->next->content));
	fprintf(stderr, "debut du brut, passage == %d\n", i);
	i++;
	ft_loc_ptr(head, prev);
	if (ft_issort(*a, *b))
	{
		fprintf(stderr, "issort == %d\n", j);
		j++;
		return (1);
	}
	if (prev == 0)
		return (OPE_ALL);
	else if (prev == 1 || prev == 2)
		return (OPE_PUSH);
	else if (prev == 3 || prev == 4 || prev == 5)
		return (OPE_SWAP);
	else if (prev == 6)
		return (OPE_RA);
	else if (prev == 7)
		return (OPE_RB);
	else if (prev == 8)
		return (OPE_RR);
	else if (prev == 9)
		return (OPE_RRA);
	else if (prev == 10)
		return (OPE_RRB);
	else
		return (OPE_RRR);
}

void	ft_force(t_list **a, t_list **b)
{
	t_ope	*head;

	head = NULL;
	fprintf(stderr, "debut du force\n");
	if (ft_brut(&head, 0, a, b))
		ft_print_ope(head);
	while (head->prev)
		head = head->prev;
	ft_free_ope(&head);
}
