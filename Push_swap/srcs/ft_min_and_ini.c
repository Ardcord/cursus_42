#include "../includes/push_swap.h"

void	ft_ini_sort(t_sort *how, short method, int nb, unsigned int ini)
{
	how->method = method;
	how->nb = nb;
	how->ope_a = ini;
	how->ope_b = ini;
}

void	ft_change_sort(t_sort *a, t_sort tmp)
{
	a->nb = tmp.nb;
	a->ope_a = tmp.ope_a;
	a->ope_b = tmp.ope_b;
}

unsigned int	ft_lstmin(t_list *a)
{
	unsigned int	i;
	unsigned int	save;
	int				min;
	t_list			*mv;

	i = 0;
	if (!a)
		return (i);
	min = *(int *)a->content;
	save = i;
	mv = a;
	while (mv && mv->next && ++i)
	{
		mv = mv->next;
		if (min > *(int *)mv->content)
		{
			save = i;
			min = *(int *)mv->content;
		}
	}
	return (save);
}

int	ft_lstminvalue(t_list *a)
{
	int				min;
	t_list			*mv;

	min = *(int *)a->content;
	mv = a;
	while (mv && mv->next)
	{
		mv = mv->next;
		if (min > *(int *)mv->content)
			min = *(int *)mv->content;
	}
	return (min);
}
