/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:44:56 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/20 15:55:56 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_hexa(unsigned int list, char *base);
char	*ft_itoa_unsignd(unsigned int n);
char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);
int		ft_ptr_hexa(unsigned long int list, int j, char *base);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);

#endif
