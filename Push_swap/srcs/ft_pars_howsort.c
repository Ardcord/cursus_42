/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_howsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:09:03 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/30 19:23:50 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_sort	pars1(t_sort a, t_sort b, t_sort c, t_sort d)
{
	if (a.ope_a > b.ope_a)
	{
		if (b.ope_a > c.ope_a + c.ope_b)
		{
			if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
				return (d);
			return (c);
		}
		else if (b.ope_a > d.ope_a + d.ope_b)
			return (d);
		return (b);
	}
	else if (a.ope_a > c.ope_a + c.ope_b)
	{
		if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
			return (d);
		return (c);
	}
	else if (a.ope_a > d.ope_a + d.ope_b)
		return (d);
	return (a);
}

static t_sort	pars2(t_sort a, t_sort b, t_sort c, t_sort d)
{
	if (a.ope_a > b.ope_b)
	{
		if (b.ope_b > c.ope_a + c.ope_b)
		{
			if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
				return (d);
			return (c);
		}
		else if (b.ope_b > d.ope_a + d.ope_b)
			return (d);
		return (b);
	}
	else if (a.ope_a > c.ope_a + c.ope_b)
	{
		if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
			return (d);
		return (c);
	}
	else if (a.ope_a > d.ope_a + d.ope_b)
		return (d);
	return (a);
}

static t_sort	pars3(t_sort a, t_sort b, t_sort c, t_sort d)
{
	if (a.ope_b > b.ope_a)
	{
		if (b.ope_a > c.ope_a + c.ope_b)
		{
			if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
				return (d);
			return (c);
		}
		else if (b.ope_a > d.ope_a + d.ope_b)
			return (d);
		return (b);
	}
	else if (a.ope_b > c.ope_a + c.ope_b)
	{
		if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
			return (d);
		return (c);
	}
	else if (a.ope_b > d.ope_a + d.ope_b)
		return (d);
	return (a);
}

static t_sort	pars4(t_sort a, t_sort b, t_sort c, t_sort d)
{
	if (a.ope_b > b.ope_b)
	{
		if (b.ope_b > c.ope_a + c.ope_b)
		{
			if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
				return (d);
			return (c);
		}
		else if (b.ope_b > d.ope_a + d.ope_b)
			return (d);
		return (b);
	}
	else if (a.ope_b > c.ope_a + d.ope_b)
	{
		if (c.ope_a + c.ope_b > d.ope_a + d.ope_b)
			return (d);
		return (c);
	}
	else if (a.ope_b > d.ope_a + d.ope_b)
		return (d);
	return (a);
}

t_sort	ft_how_to_sort(t_stack *sort)
{
	t_sort	a;
	t_sort	b;
	t_sort	c;
	t_sort	d;

	ft_method_a(sort, &a);
	ft_method_b(sort, &b);
	ft_method_c(sort, &c);
	ft_method_d(sort, &d);
	if (a.ope_a > a.ope_b)
	{
		if (b.ope_a > b.ope_b)
			return (pars1(a, b, c, d));
		return (pars2(a, b, c, d));
	}
	else
	{
		if (b.ope_a > b.ope_b)
			return (pars3(a, b, c, d));
		return (pars4(a, b, c, d));
	}
}
