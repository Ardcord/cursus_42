/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:35:29 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/01 21:18:36 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 1)
	{
		write(1, "ceError1\n", 9);
		exit (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isset(argv[i][j], " +-0123456789") == 0)
			{
				write(1, "ceError2\n", 9);
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
	fprintf(stderr, "int a %d \n", *((int *)(*stack_a)->content));
	a = *stack_a;
	while (a->next)
	{
		write(1, "a->next\n", 8);
		tmp = a->next;
		while (tmp)
		{
			if (*((int *)a->content) == *((int *)tmp->content))
				lst_clear_error(stack_a);
			fprintf(stderr, "int a %d - int tmp %d\n", *((int *)a->content), *((int *)tmp->content));
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static t_list	*ft_ini(char **av, t_index *index, int *nb, t_list **a)
{
	t_list	*lst;

	nb = malloc(sizeof(int));
	if (!nb)
		lst_clear_error(a);
	*nb = ft_atoi((av[index->i]) + index->j);
	lst = ft_lstnew((void *)nb);
	if (!lst)
		lst_clear_error(a);
	return (lst);
}

static void	ft_lst_init(int ac, char **av, t_list **a)
{
	int		*nb;
	t_list	*lst;
	t_index	index;

	index.i = 1;
	index.j = 0;
	nb = NULL;
	lst = ft_ini(av, &index, nb, a);
	*a = lst;
	while (ac > index.i)
	{
		while (av[index.i][index.j] == ' ')
			(index.j)++;
		while (ft_isset(av[index.i][index.j], "+-0123456789"))
			(index.j)++;
		write(1, "sa passe\n", 9);
		lst->next = ft_ini(av, &index, nb, a);
		if (!av[index.i][index.j])
		{
			index.j = 0;
			index.i++;
		}
		lst = lst->next;
	}
}

void	ft_parser_init(int argc, char **argv, t_list **stack_a)
{
	void	(*ftc)(void *);

	ftc = &ft_void;
	check_error(argc, argv);
	write(1, "error1\n", 7);
	ft_lst_init(argc, argv, stack_a);
	if (!(*stack_a))
	{
		write(2, "error\n", 6);
		exit (0);
	}
	write(1, "error2\n", 7);
	check_repeat(stack_a);
	write(1, "error3\n", 7);
	ft_lstclear(stack_a, ftc);
	write(1, "error4\n", 7);
}

//				fprintf(stderr, "caractere |%c|\n", argv[i][j]);