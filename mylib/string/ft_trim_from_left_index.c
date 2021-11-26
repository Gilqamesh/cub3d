/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_from_left_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:55:40 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 10:55:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftstring.h"

/*
** Returns the first index in 'str' that is not part of 'set'
*/
int	ft_trim_from_left_index(char *str, char *set)
{
	bool	setChars[256];
	int		i;
	int		ret;

	if (str == NULL || set == NULL)
		return (0);
	i = -1;
	while (++i < 256)
		setChars[i] = false;
	i = -1;
	while (set[++i])
		setChars[(unsigned char)set[i]] = true;
	ret = 0;
	while (*str)
	{
		if (setChars[(unsigned char)*str] == false)
			return (ret);
		ret++;
		str++;
	}
	return (ret);
}
