/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:44:56 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/10 18:48:10 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
