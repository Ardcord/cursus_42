/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:29:06 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/18 18:15:14 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *str);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_unsignd(unsigned int n);
int		ft_hexa(long long int list, char *base);
int		ft_ptr_hexa(long int list, int j);

#endif
