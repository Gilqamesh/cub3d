/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelstdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:16:59 by edavid            #+#    #+#             */
/*   Updated: 2021/09/13 14:18:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Frees memory associated with 'node' that is of t_filelst* type.
*/
void	ft_filelstdel(void *node)
{
	if (node == NULL)
		return ;
	if (((t_filelst *)node)->filename)
		free(((t_filelst *)node)->filename);
	free(node);
}
