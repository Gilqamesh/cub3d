/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinstrjoin_from_back.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:13:50 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 16:17:57 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	concatenateResult(char *result, t_node_binary *cur)
{
	int	result_index;
	int	curcontent_index;

	result_index = -1;
	while (cur)
	{
		curcontent_index = -1;
		while (((char *)cur->content)[++curcontent_index])
			result[++result_index] = ((char *)cur->content)[curcontent_index];
		cur = cur->prev;
	}
}

// Allocates and returns a string that is the concatenation of going through
// the list's str contents
char	*ft_nodbinstrjoin_from_back(t_node_binary *list)
{
	int				len;
	t_node_binary	*cur;
	char			*result;

	if (!list)
		return (ft_strdup(""));
	len = 0;
	cur = list;
	while (cur)
	{
		len += ft_strlen((char *)cur->content);
		if (cur->next)
			cur = cur->next;
		else
			break ;
	}
	result = malloc(len + 1);
	result[len] = '\0';
	concatenateResult(result, cur);
	return (result);
}
