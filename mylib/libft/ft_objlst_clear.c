/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:34:49 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:39:54 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the list using the function 'del' and free.
** Finally, the pointer to the list is set to NULL.
*/
void	ft_objlst_clear(t_obj_lst **lst, void (*del)(void *))
{
	t_obj_lst	*cur;
	t_obj_lst	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		ft_objlst_delone(tmp, del);
	}
	*lst = NULL;
}
