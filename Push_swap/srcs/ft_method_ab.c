/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:23:31 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/30 20:13:49 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_select_sort_a_b(t_sort *a, t_sort tmp)
{
	if (a->ope_a > a->ope_b)
	{
		if (tmp.ope_a >= tmp.ope_b && tmp.ope_a < a->ope_a)
			ft_change_sort(a, tmp);
		else if (tmp.ope_a < tmp.ope_b && tmp.ope_b < a->ope_a)
			ft_change_sort(a, tmp);
	}
	else
	{
		if (tmp.ope_a >= tmp.ope_b && tmp.ope_a < a->ope_b)
			ft_change_sort(a, tmp);
		else if (tmp.ope_a < tmp.ope_b && tmp.ope_b < a->ope_b)
			ft_change_sort(a, tmp);
	}
}

static void	ft_method_a_p2(t_stack *sort, t_sort *a, t_list *mv, t_list *mb)
{
	t_sort	tmp;

	ft_ini_sort(&tmp, 1, *(int *)mb->content, 0);
	while (mb && mb->next)
	{
		mb = mb->next;
		tmp.nb = *(int *)mb->content;
		tmp.ope_b++;
		tmp.ope_a = 0;
		mv = sort->a;
		while (mv && mv->next && !(tmp.nb > *(int *)mv->content
				&& tmp.nb < *(int *)mv->next->content) && ++(tmp.ope_a))
			mv = mv->next;
		if (mv && mv->next && ++(tmp.ope_a))
			mv = mv->next;
		if (*(int *)mv->content < tmp.nb || tmp.nb < ft_lstminvalue(sort->a))
		{
			tmp.ope_a = ft_lstmin(sort->a);
			if (tmp.nb < *(int *)sort->a->content
				&& tmp.nb > ft_lstminvalue(sort->a))
				tmp.ope_a = 0;
		}
		ft_select_sort_a_b(a, tmp);
	}
}

void	ft_method_a(t_stack *sort, t_sort *a)
{
	t_list	*mv;
	t_list	*mb;

	ft_ini_sort(a, 1, *(int *)sort->b->content, 0);
	mv = sort->a;
	mb = sort->b;
	while (mv && mv->next && !(a->nb > *(int *)mv->content
			&& a->nb < *(int *)mv->next->content) && ++(a->ope_a))
		mv = mv->next;
	if (mv && mv->next && ++(a->ope_a))
		mv = mv->next;
	if (*(int *)mv->content < a->nb || a->nb < ft_lstminvalue(sort->a))
	{
		a->ope_a = ft_lstmin(sort->a);
		if (a->nb < *(int *)sort->a->content && a->nb > ft_lstminvalue(sort->a))
			a->ope_a = 0;
	}
	ft_method_a_p2(sort, a, mv, mb);
}

static void	ft_method_b_p2(t_stack *sort, t_sort *b,
	t_list *mb, unsigned int asize)
{
	t_sort	tmp;
	t_list	*mv;

	ft_ini_sort(&tmp, 2, *(int *)mb->content, ft_lstsize(sort->b));
	while (mb && mb->next && tmp.ope_b--)
	{
		mb = mb->next;
		tmp.ope_a = asize;
		tmp.nb = *(int *)mb->content;
		mv = sort->a;
		while (mv && mv->next && !(tmp.nb > *(int *)mv->content
				&& tmp.nb < *(int *)mv->next->content) && tmp.ope_a--)
			mv = mv->next;
		if (mv && mv->next && (tmp.ope_a)--)
			mv = mv->next;
		if (*(int *)mv->content < tmp.nb || tmp.nb < ft_lstminvalue(sort->a))
		{
			tmp.ope_a = asize - ft_lstmin(sort->a);
			if (tmp.ope_a == asize || (*(int *)mv->content < tmp.nb
					&& tmp.nb < *(int *)sort->a->content
					&& tmp.nb > ft_lstminvalue(sort->a)))
				tmp.ope_a = 0;
		}
		ft_select_sort_a_b(b, tmp);
	}
}

void	ft_method_b(t_stack *sort, t_sort *b)
{
	t_list			*mv;
	t_list			*mb;
	unsigned int	asize;

	ft_ini_sort(b, 2, *(int *)sort->b->content, 0);
	asize = ft_lstsize(sort->a);
	b->ope_a = asize;
	mv = sort->a;
	mb = sort->b;
	while (mv && mv->next && !(b->nb > *(int *)mv->content
			&& b->nb < *(int *)mv->next->content) && (b->ope_a)--)
		mv = mv->next;
	if (mv && mv->next && (b->ope_a)--)
		mv = mv->next;
	if (*(int *)mv->content < b->nb || b->nb < ft_lstminvalue(sort->a))
	{
		b->ope_a = asize - ft_lstmin(sort->a);
		if (b->nb < *(int *)sort->a->content && b->nb > ft_lstminvalue(sort->a))
			b->ope_a = 0;
	}
	if (b->ope_a == asize)
		b->ope_a = 0;
	ft_method_b_p2(sort, b, mb, asize);
}
