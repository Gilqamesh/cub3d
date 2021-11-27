/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelistnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:27:45 by edavid            #+#    #+#             */
/*   Updated: 2021/11/27 19:27:46 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftfilelist.h"
#include "ft_libftmemory.h"

/*
** Allocates and returns a new element t_filelist *result;
** result->filename = filename;
** result->mode = mode;
** The variable 'next' is initialized to NULL.
*/
t_filelist	*ft_filelistnew(char *filename, enum e_redirection_mode mode)
{
	t_filelist	*new;

	new = ft_calloc(1, sizeof(*new));
	new->filename = filename;
	new->mode = mode;
	new->next = NULL;
	return (new);
}
