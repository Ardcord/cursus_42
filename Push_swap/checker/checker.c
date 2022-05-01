/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:11:59 by efunes            #+#    #+#             */
/*   Updated: 2022/05/01 19:09:42 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checker(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*operation;

	if (argc < 2)
		return (0);
	a = ft_parser_init(argc, argv, &a);
	b = NULL;
	while (1)
	{
		operation = get_next_line(0);
		if (!operation || operation == EOF)
			break ;
		ft_do_op(&a, &b, operation);
		free(operation);
		operation = NULL;
	}
	if (ft_issort)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
