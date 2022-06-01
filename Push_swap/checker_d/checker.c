/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 12:11:59 by efunes            #+#    #+#             */
/*   Updated: 2022/06/01 15:47:51 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	operation[4];
	int		ret;

	if (argc < 2)
		return (0);
	ft_parser_init(argc, argv, &a);
	b = NULL;
	ret = 1;
	while (ret)
	{
		ret = read(0, operation, 3);
		operation[ret] = 0;
		if (ret)
			ft_do_op(&a, &b, operation);
	}
	if (!ft_issort(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
