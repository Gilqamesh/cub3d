/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:19:41 by edavid            #+#    #+#             */
/*   Updated: 2021/09/13 14:21:30 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates and returns a new element t_filelst *result;
** result->filename = filename;
** result->mode = mode;
** The variable 'next' is initialized to NULL.
*/
t_filelst	*ft_filelstnew(char *filename, int mode)
{
	t_filelst	*new;

	new = ft_calloc(1, sizeof(*new));
	new->filename = filename;
	new->mode = mode;
	new->next = NULL;
	return (new);
}
