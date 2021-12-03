/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:18:48 by edavid            #+#    #+#             */
/*   Updated: 2021/12/03 13:42:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftslist.h"

void	ft_lstdel(void *node)
{
	if (node == NULL)
		return ;
	if (((t_list *)node)->content)
		free(((t_list *)node)->content);
	free(node);
}
