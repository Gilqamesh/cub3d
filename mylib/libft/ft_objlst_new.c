/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:55:29 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:20:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates and returns a new element t_obj_lst *result;
** result->key = key;
** result->value = value;
** The variable 'next' is initialized to NULL.
*/
t_obj_lst	*ft_objlst_new(char *key, char *value)
{
	t_obj_lst	*new;

	new = ft_calloc(1, sizeof(*new));
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}
