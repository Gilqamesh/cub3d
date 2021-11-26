/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isValidBashIdentifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:53:29 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 10:36:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftvalid.h"
#include "ft_libftctype.h"
#include <stdlib.h>

/*
** Returns true if 'str' is a valid Bash identifier, false otherwise.
*/
bool	ft_isValidBashIdentifier(char *str)
{
	if (str == NULL)
		return (false);
	if (ft_isalpha(*str) || *str == '_')
		str++;
	else
		return (false);
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (false);
		str++;
	}
	return (true);
}
