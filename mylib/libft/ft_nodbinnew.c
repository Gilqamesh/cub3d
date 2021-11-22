/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:24:22 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 10:27:44 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node_binary	*ft_nodbinnew(void *content)
{
	t_node_binary	*new_el;

	new_el = malloc(sizeof(*new_el));
	if (new_el == NULL)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	new_el->prev = NULL;
	return (new_el);
}
