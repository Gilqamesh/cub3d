/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelstclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:12:47 by edavid            #+#    #+#             */
/*   Updated: 2021/09/13 14:16:03 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the list using the function 'del'.
** Finally, the pointer to the list is set to NULL.
*/
void	ft_filelstclear(t_filelst **lst, void (*del)(void *))
{
	t_filelst	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_filelstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
