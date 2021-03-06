/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:55:51 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 13:28:28 by efunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_write_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*sort;
	t_ope	*begin;
	t_ope	*tmp;

	if (argc < 2)
		return (0);
	sort = malloc(sizeof(t_stack));
	if (!sort)
		return (ft_write_error());
	sort->a = NULL;
	ft_parser_init(argc, argv, &(sort->a));
	begin = ft_new_op(&begin, 0);
	sort->b = NULL;
	tmp = ft_algo(begin, sort);
	ft_lstclear(&(sort->a), &ft_void);
	ft_lstclear(&(sort->b), &ft_void);
	free(sort);
	if (!begin)
		return (0);
	if (tmp != begin)
		ft_print_ope(tmp);
	ft_free_ope(&begin);
	return (0);
}
