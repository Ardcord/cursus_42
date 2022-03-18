/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:11:04 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/18 18:37:53 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hexa(long int list, int j)
{
	char		*res;
	char		*base;
	long int	adr;

	base = "0123456789abcdef";
	res = malloc(sizeof(char) * 12);
	if (!res)
		return ((int) NULL);
	res[0] = '0';
	res[1] = 'x';
	res[11] = '\0';
	adr = (long)list;
	j = 11;
	adr = (long)list;
	while (2 <= --j)
	{
		res[j] = base[adr % 16];
		adr /= 16;
	}
	j = ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (j);
}
