/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:31:02 by edavid            #+#    #+#             */
/*   Updated: 2021/06/25 20:31:02 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftgnl.h"

int	contains_newline(char *str, size_t n)
{
	size_t	index_of_newline;

	index_of_newline = 0;
	while (index_of_newline < n)
	{
		if (str[index_of_newline] == '\n')
			return ((int)index_of_newline);
		index_of_newline++;
	}
	return (index_of_newline);
}

char	*ft_strdup_v2(const char *s, int n)
{
	char	*new;
	char	*r;

	new = (char *)malloc(n + 1);
	if (!new)
		return ((char *)0);
	r = new;
	while (n--)
		*new++ = *s++;
	*new = '\0';
	return (r);
}
