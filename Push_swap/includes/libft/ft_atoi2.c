/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:29:01 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/22 14:33:23 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	return (0);
}

int	ft_atoi2(const char *str)
{
	long long	neg;
	long long	res;

	neg = 1;
	res = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{	
		if (res > 214748365 || (neg == 1 && res == 214748364 && *str > '7')
			|| (neg == -1 && res == 214748364 && *str > '8'))
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		res = res * 10 + *str - '0';
		str++;
	}
	return (neg * res);
}
