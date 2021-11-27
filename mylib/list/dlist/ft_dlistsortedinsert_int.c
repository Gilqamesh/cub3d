/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistsortedinsert_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:03:47 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:29:00 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"

void	ft_dlistsortedinsert_int(t_dlist **lst, t_dlist *new)
{
	t_dlist	**tail;

	if (new == NULL || lst == NULL)
		return ;
	tail = lst;
	while (*tail && *(int *)new->content > *(int *)(*tail)->content)
		tail = &(*tail)->next;
	new->next = (*tail);
	new->prev = (*tail)->prev;
	(*tail) = new;
}
