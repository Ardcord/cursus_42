/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:57:37 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/02 13:57:51 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	cpt;
	size_t	cpt2;

	cpt = 0;
	cpt2 = 0;
	i = (ft_strlen(dst));
	if (!dstsize)
		return (ft_strlen((char *)src) + dstsize);
	while (dst[cpt])
		cpt++;
	while (cpt < dstsize - 1 && src[cpt2])
		dst[cpt++] = src[cpt2++];
	dst[cpt] = '\0';
	if (dstsize >= i)
		return (i + (ft_strlen((char *)src)));
	else
		return (ft_strlen((char *)src) + dstsize);
}
