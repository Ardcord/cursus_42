/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:09:02 by tvanbael          #+#    #+#             */
/*   Updated: 2022/05/01 18:42:04 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!(*lst) || !(*del))
		return ;
	if ((*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	if ((*lst)->content)
		del((*lst)->content);
	(*lst)->next = NULL;
	free(*lst);
	*lst = NULL;
}
