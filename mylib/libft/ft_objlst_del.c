/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:18:48 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:46:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Frees node->content and node, where node is of type *t_obj_lst
*/
void	ft_objlst_del(void *node)
{
	if (node == NULL)
		return ;
	if (((t_obj_lst *)node)->key)
		free(((t_obj_lst *)node)->key);
	if (((t_obj_lst *)node)->value)
		free(((t_obj_lst *)node)->value);
	free(node);
}
