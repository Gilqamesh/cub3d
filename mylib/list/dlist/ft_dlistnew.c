/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:24:22 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:27:44 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"

t_dlist	*ft_dlistnew(void *content)
{
	t_dlist	*new_el;

	new_el = malloc(sizeof(*new_el));
	if (new_el == NULL)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	new_el->prev = NULL;
	return (new_el);
}
