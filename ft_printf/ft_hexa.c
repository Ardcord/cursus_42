/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:43:26 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/20 15:57:40 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int nb, int i)
{
	while ((nb >= 16) && i++)
		(nb /= 16);
	return (i);
}

int	ft_hexa(unsigned int list, char *base)
{
	int		i;
	char	*str;

	i = ft_hexa_len(list, 1);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	if (list == 0)
	{
		free (str);
		write(1, "0", 1);
		return (1);
	}
	while (0 <= --i)
	{
		if (list > 0)
			str[i] = base[list % 16];
		list /= 16;
	}
	i = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (i);
}
