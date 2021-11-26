/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_rem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:18:48 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:40:29 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftobjlist.h"

/*
** Find 'node' in t_obj_lst 'lst' and deletes it keeping the rest of the list
** intact.
*/
void	ft_objlst_rem(t_obj_lst **lst, t_obj_lst *node)
{
	t_obj_lst	*elem;
	t_obj_lst	*prev;

	if (lst == NULL)
		return ;
	elem = *lst;
	prev = NULL;
	if (elem == node && elem != NULL)
		*lst = elem->next;
	else
	{
		while (elem != NULL && elem != node)
		{
			prev = elem;
			elem = elem->next;
		}
		if (prev != NULL)
			prev->next = elem->next;
	}
	if (elem != NULL)
	{
		ft_objlst_del(elem);
		elem = NULL;
	}
}
