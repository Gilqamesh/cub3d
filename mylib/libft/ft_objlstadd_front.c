/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_add_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:53:19 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 17:54:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element 'new' at the beginning of the list.
*/
void	ft_objlstadd_front(t_obj_lst **lst, t_obj_lst *new)
{
	new->next = *lst;
	*lst = new;
}
