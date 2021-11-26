/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isStrContainedInStrArr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:01:29 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 10:44:59 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftstring.h"

/*
** Returns true if 'str' is contained in the NULL terminated 'strArr'
*/
bool	ft_isStrContainedInStrArr(char *str, char **strArr)
{
	if (str == NULL || strArr == NULL)
		return (false);
	while (*strArr)
	{
		if (!ft_strcmp(str, *strArr))
			return (true);
		strArr++;
	}
	return (false);
}
