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
