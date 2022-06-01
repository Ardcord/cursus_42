/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:09:09 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/30 20:13:30 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_select_sort_c_d(t_sort *a, t_sort tmp)
{
	if (a->ope_a + a->ope_b > tmp.ope_a + tmp.ope_b)
		ft_change_sort(a, tmp);
}

static void	ft_method_c_p2(t_stack *sort, t_sort *c, t_list *mv, t_list *mb)
{
	t_sort	tmp;

	ft_ini_sort(&tmp, 3, *(int *)mb->content, ft_lstsize(sort->b));
	while (mb && mb->next)
	{
		mb = mb->next;
		tmp.nb = *(int *)mb->content;
		tmp.ope_b--;
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
		ft_select_sort_c_d(c, tmp);
	}
}

void	ft_method_c(t_stack *sort, t_sort *c)
{
	t_list	*mv;
	t_list	*mb;

	ft_ini_sort(c, 3, *(int *)sort->b->content, 0);
	mv = sort->a;
	mb = sort->b;
	while (mv && mv->next && !(c->nb > *(int *)mv->content
			&& c->nb < *(int *)mv->next->content) && ++(c->ope_a))
		mv = mv->next;
	if (mv && mv->next && ++(c->ope_a))
		mv = mv->next;
	if (*(int *)mv->content < c->nb || c->nb < ft_lstminvalue(sort->a))
	{
		c->ope_a = ft_lstmin(sort->a);
		if (c->nb < *(int *)sort->a->content && c->nb > ft_lstminvalue(sort->a))
			c->ope_a = 0;
	}
	ft_method_c_p2(sort, c, mv, mb);
}

static void	ft_method_d_p2(t_stack *sort, t_sort *d,
	t_list *mb, unsigned int asize)
{
	t_list	*mv;
	t_sort	tmp;

	ft_ini_sort(&tmp, 4, *(int *)mb->content, 0);
	while (mb && mb->next)
	{
		mb = mb->next;
		tmp.nb = *(int *)mb->content;
		tmp.ope_b++;
		tmp.ope_a = asize;
		mv = sort->a;
		while (mv && mv->next && !(tmp.nb > *(int *)mv->content
				&& tmp.nb < *(int *)mv->next->content) && (tmp.ope_a)--)
			mv = mv->next;
		if (mv && mv->next && (tmp.ope_a)--)
			mv = mv->next;
		if (*(int *)mv->content < tmp.nb || tmp.nb < ft_lstminvalue(sort->a))
			tmp.ope_a = asize - ft_lstmin(sort->a);
		if ((*(int *)mv->content < tmp.nb && tmp.nb < *(int *)sort->a->content
				&& tmp.nb > ft_lstminvalue(sort->a)) || tmp.ope_a == asize)
			tmp.ope_a = 0;
		ft_select_sort_c_d(d, tmp);
	}
}

void	ft_method_d(t_stack *sort, t_sort *d)
{
	t_list			*mv;
	t_list			*mb;
	unsigned int	asize;

	ft_ini_sort(d, 4, *(int *)sort->b->content, 0);
	asize = ft_lstsize(sort->a);
	d->ope_a = asize;
	mv = sort->a;
	mb = sort->b;
	while (mv && mv->next && !(d->nb > *(int *)mv->content
			&& d->nb < *(int *)mv->next->content) && (d->ope_a)--)
		mv = mv->next;
	if (mv && mv->next && (d->ope_a)--)
		mv = mv->next;
	if (*(int *)mv->content < d->nb || d->nb < ft_lstminvalue(sort->a))
	{
		d->ope_a = asize - ft_lstmin(sort->a);
		if (d->nb < *(int *)sort->a->content && d->nb > ft_lstminvalue(sort->a))
			d->ope_a = 0;
	}
	if (d->ope_a == asize)
		d->ope_a = 0;
	ft_method_d_p2(sort, d, mb, asize);
}
