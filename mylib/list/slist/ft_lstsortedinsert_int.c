/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortedinsert_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:03:47 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 15:28:54 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftslist.h"

void	ft_lstsortedinsert_int(t_list **lst, t_list *new)
{
	t_list	**tail;

	if (new == NULL || lst == NULL)
		return ;
	tail = lst;
	while (*tail && *(int *)new->content > *(int *)(*tail)->content)
		tail = &(*tail)->next;
	new->next = (*tail);
	(*tail) = new;
}
