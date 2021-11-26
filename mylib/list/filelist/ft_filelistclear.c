/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelistclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:12:47 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:43:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftfilelist.h"

/*
** Frees the list using the function 'del'.
** Finally, the pointer to the list is set to NULL.
*/
void	ft_filelistclear(t_filelist **lst, void (*del)(void *))
{
	t_filelist	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_filelistdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
