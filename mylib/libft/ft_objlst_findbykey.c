/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_findbykey.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:32:55 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 17:40:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds the str 'key' in the list 'head' and returns the address to it.
** Returns NULL if no match was found.
** Match if: 'key' == 'head'->key
*/
t_obj_lst	*ft_objlst_findbykey(t_obj_lst *head, char *key)
{
	t_obj_lst	*cur;

	if (head == NULL)
		return (NULL);
	cur = head;
	while (cur)
	{
		if (!ft_strcmp(key, cur->key))
			break ;
		cur = cur->next;
	}
	return (cur);
}
