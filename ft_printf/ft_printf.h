/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:44:56 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/18 19:00:08 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_index
{
	int		i;
	int		j;
	char	*save;
}			t_index;

char	*get_next_line(int fd);
int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);
int		ft_strreste(char *str);
char	*ft_save_in_line(char *line, char *tmp);

#endif
