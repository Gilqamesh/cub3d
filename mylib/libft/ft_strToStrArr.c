/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strToStrArr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:40:12 by edavid            #+#    #+#             */
/*   Updated: 2021/09/18 14:42:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a NULL terminated str array that has 'str' as its
** first element.
*/
char	**ft_strToStrArr(char *str)
{
	char	**strArr;

	if (str == NULL)
	{
		strArr = ft_calloc(1, sizeof(*strArr));
		return (strArr);
	}
	strArr = ft_calloc(2, sizeof(*strArr));
	strArr[0] = ft_strdup(str);
	return (strArr);
}
