/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:11:04 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/20 17:03:41 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long int nb)
{
	int	i;

	i = 1;
	while ((nb >= 16) && i++)
		(nb /= 16);
	return (i + 2);
}

int	ft_ptr_hexa(unsigned long int list, int j, char *base)
{
	char				*res;

	j = ft_ptr_len(list);
	res = malloc(sizeof(char) * (j + 1));
	if (!res)
		return (0);
	res[0] = '0';
	res[1] = 'x';
	res[j] = '\0';
	while (2 <= --j)
	{
		res[j] = base[list % 16];
		list /= 16;
	}
	j = ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (j);
}
