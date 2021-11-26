/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelistdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:16:59 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:44:43 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftfilelist.h"

/*
** Frees memory associated with 'node' that is of t_filelist* type.
*/
void	ft_filelistdel(void *node)
{
	if (node == NULL)
		return ;
	if (((t_filelist *)node)->filename)
		free(((t_filelist *)node)->filename);
	free(node);
}
