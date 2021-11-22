/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortedinsert_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:03:47 by edavid            #+#    #+#             */
/*   Updated: 2021/07/31 11:40:00 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodbinsortedinsert_int(t_node_binary **lst, t_node_binary *new)
{
	t_node_binary	**tail;

	if (new == NULL || lst == NULL)
		return ;
	tail = lst;
	while (*tail && *(int *)new->content > *(int *)(*tail)->content)
		tail = &(*tail)->next;
	new->next = (*tail);
	new->prev = (*tail)->prev;
	(*tail) = new;
}
