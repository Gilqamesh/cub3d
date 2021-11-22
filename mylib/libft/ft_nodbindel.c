/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbindel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:32:15 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 19:24:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_nodbindel(void *node)
{
	if (node == NULL)
		return ;
	if (((t_node_binary *)node)->content)
		free(((t_node_binary *)node)->content);
	free(node);
}
