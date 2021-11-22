/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isStrContainedInStrArr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:01:29 by edavid            #+#    #+#             */
/*   Updated: 2021/09/09 18:03:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
