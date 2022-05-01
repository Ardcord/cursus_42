/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 10:25:29 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/01 19:53:25 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_void(void *a)
{
	int	*del;

	del = (int *)a;
	if (del)
		free(del);
}