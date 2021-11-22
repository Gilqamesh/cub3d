/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlstinsert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:19:31 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 15:32:03 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Inserts the element 'new' to 'lst' by the alphabetical ordering of
** new->key.
*/
void	ft_objlstinsert(t_obj_lst **lst, t_obj_lst *new)
{
	if (lst == NULL || new == NULL)
		return ;
	while (*lst && ft_strcmp((*lst)->key, new->key) < 0)
		lst = &(*lst)->next;
	new->next = *lst;
	*lst = new;
}
