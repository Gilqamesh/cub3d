/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_from_right_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:20:46 by edavid            #+#    #+#             */
/*   Updated: 2021/09/19 20:05:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the first index in 'str' that is not part of 'set'
*/
int	ft_trim_from_right_index(char *str, char *set)
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
	i = ft_strlen(str);
	while (--i >= 0)
		if (setChars[(unsigned char)str[i]] == false)
			return (i);
	return (0);
}
