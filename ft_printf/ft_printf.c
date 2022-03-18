/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:29:04 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/18 18:46:00 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char_str(va_list list, int np)
{
	char	*argchar;
	char	c;

	if (np == 2)
	{
		c = va_arg(list, int);
		write(1, &c, 1);
		return (1);
	}
	if (np == 3)
	{
		argchar = va_arg(list, char *);
		if (argchar == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		write(1, argchar, ft_strlen(argchar));
		return (ft_strlen(argchar));
	}
	else
		write(1, "%", 1);
	return (1);
}

int	ft_putnbr_base(va_list list, int np)
{
	int		i;
	int		argint;
	char	*conv;

	i = 0;
	if (np == 1)
	{
		argint = va_arg(list, int);
		conv = ft_itoa(argint);
		i = ft_strlen(conv);
		write(1, conv, i);
		free(conv);
	}
	if (np == 2)
	{
		argint = va_arg(list, unsigned int);
		conv = ft_itoa_unsignd(argint);
		i = ft_strlen(conv);
		write(1, conv, i);
		free(conv);
	}
	return (i);
}

int	ft_parser(va_list list, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*str == 'c')
		i = ft_put_char_str(list, 2);
	else if (*str == 's')
		i = ft_put_char_str(list, 3);
	else if (*str == 'p')
		i = ft_ptr_hexa(va_arg(list, long int), j);
	else if (*str == 'd')
		i = ft_putnbr_base(list, 1);
	else if (*str == 'i')
		i = ft_putnbr_base(list, 1);
	else if (*str == 'u')
		i = ft_putnbr_base(list, 2);
	else if (*str == 'x')
		i = ft_hexa(va_arg(list, long long int), "0123456789abcdef");
	else if (*str == 'X')
		i = ft_hexa(va_arg(list, long long int), "0123456789ABCDEF");
	else if (*str == '%')
		i = ft_put_char_str(list, 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		k;
	va_list	list;

	i = 0;
	j = 0;
	k = 0;
	va_start(list, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
			j = ft_parser(list, (char *)&str[++i]);
		else
			j = write(1, &str[i], 1);
		i++;
		k = k + j;
	}
	va_end(list);
	return (k);
}

int	main(void)
{
//	int	i = -1;
//	char	*t = "cest de leau";
//	unsigned int	i = 4294967295;
//	int	i = 2147483646;
//	ft_printf("%u", i);
 //	ft_printf("---ft_printf = %p", i);
	printf("------printf = %p", -1);
//	ft_printf("%i", 424643631);
//	ft_printf("3216543164313");
	return (0);
}