/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intstrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:37:26 by tvanbael          #+#    #+#             */
/*   Updated: 2022/04/27 11:25:19 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intstrcmp(int *tab1, int *tab2)
{
	int	count;

	count = 0;
	while (count <= 8 && tab1)
	{
		if (tab1[count] == tab2[count])
			count++;
		if (tab1[count] != tab2[count])
			return (1);
	}
	return (2);
}
