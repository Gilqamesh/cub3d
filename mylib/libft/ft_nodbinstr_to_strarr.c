/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinstr_to_strarr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:29:55 by edavid            #+#    #+#             */
/*   Updated: 2021/09/07 14:38:09 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	concatenateResult(char **result, t_node_binary *cur)
{
	int	i;

	i = -1;
	while (cur)
	{
		result[++i] = ft_strdup(cur->content);
		cur = cur->prev;
	}
}

// Allocates and returns a NULL terminated string array that is the
// concatenation of going through the list's str contents
char	**ft_nodbinstr_to_strarr(t_node_binary *list)
{
	int				len;
	t_node_binary	*cur;
	char			**result;

	if (list == NULL)
	{
		result = malloc(sizeof(*result));
		result[0] = NULL;
		return (result);
	}
	len = 0;
	cur = list;
	while (cur)
	{
		len++;
		if (cur->next)
			cur = cur->next;
		else
			break ;
	}
	result = malloc((len + 1) * sizeof(*result));
	result[len] = NULL;
	concatenateResult(result, cur);
	return (result);
}
