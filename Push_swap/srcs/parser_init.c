/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:35:29 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 14:26:13 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isset(argv[i][j], " \n\t\r\v\f+-0123456789") == 0
				|| (j > 0 && ft_isset(argv[i][j - 1], "0123456789")
				&& ft_isset(argv[i][j], "+-")))
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

static void	check_repeat(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*a;

	if (!stack_a || !(*stack_a))
		return ;
	a = *stack_a;
	while (a->next)
	{
		tmp = a->next;
		while (tmp)
		{
			if (*((int *)a->content) == *((int *)tmp->content))
				lst_clear_error(stack_a);
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static t_list	*ft_ini(char **av, t_index *index, t_list **a)
{
	t_list	*lst;
	int		*nb;

	if (!(av[index->i][index->j]))
		return (NULL);
	nb = malloc(sizeof(int));
	if (!nb)
		lst_clear_error(a);
	*nb = ft_atoi2((av[index->i]) + index->j);
	lst = ft_lstnew((void *)nb);
	if (!lst)
		lst_clear_error(a);
	return (lst);
}

static void	ft_lst_init(int ac, char **av, t_list **a, t_index index)
{
	t_list	*lst;

	lst = ft_ini(av, &index, a);
	*a = lst;
	while (ac > index.i)
	{
		while (av[index.i][index.j] && av[index.i][index.j] == ' ')
			(index.j)++;
		while (av[index.i][index.j]
			&& ft_isset(av[index.i][index.j], "+-0123456789"))
			(index.j)++;
		if (!av[index.i][index.j])
		{
			index.j = 0;
			index.i++;
		}
		if (ac > index.i)
			lst->next = ft_ini(av, &index, a);
		if (lst->next)
			lst = lst->next;
	}
}

void	ft_parser_init(int argc, char **argv, t_list **stack_a)
{
	void	(*ftc)(void *);
	t_index	index;

	index.i = 1;
	index.j = 0;
	ftc = &ft_void;
	while (index.i < argc && !argv[index.i][index.j])
		index.i++;
	if (index.i == argc)
		exit (0);
	check_error(argc, argv);
	ft_lst_init(argc, argv, stack_a, index);
	if (!(*stack_a))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	check_repeat(stack_a);
}
