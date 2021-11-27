/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dliststr_to_strarr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:29:55 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:29:44 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"
#include "ft_libftstring.h"

static void	concatenateResult(char **result, t_dlist *cur)
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
char	**ft_dliststr_to_strarr(t_dlist *list)
{
	int				len;
	t_dlist			*cur;
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
