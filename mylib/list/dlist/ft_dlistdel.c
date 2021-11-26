/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbindel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:32:15 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 11:10:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"

void	ft_nodbindel(void *node)
{
	if (node == NULL)
		return ;
	if (((t_dlist *)node)->content)
		free(((t_dlist *)node)->content);
	free(node);
}
