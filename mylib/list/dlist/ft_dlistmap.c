/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:48:51 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:27:24 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"

t_dlist	*ft_dlistmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new_lst;
	t_dlist	*head;
	t_dlist	*tmp;

	head = (t_dlist *)0;
	new_lst = head;
	while (lst)
	{
		tmp = ft_dlistnew((*f)(lst->content));
		if (!tmp)
			ft_dlistclear(&new_lst, del, -1);
		if (!head)
		{
			head = tmp;
			new_lst = tmp;
		}
		else
		{
			head->next = tmp;
			head = head->next;
		}
		lst = lst->next;
	}
	return (new_lst);
}
