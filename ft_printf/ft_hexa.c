/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:43:26 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/18 19:02:43 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(long long int list, char *base)
{
	int							i;
	unsigned long long int		nb;
	char						*str;

	i = 1;
	nb = list;
	while (nb >= 15)
	{
		i++;
		(nb /= 16);
	}
	nb = list;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (-1 <= --i && list >= 0)
	{
		str[i] = base[nb % 16];
		nb /= 16;
	}
	i = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (i);
}
