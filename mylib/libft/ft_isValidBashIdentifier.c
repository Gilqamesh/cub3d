/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isValidBashIdentifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:53:29 by edavid            #+#    #+#             */
/*   Updated: 2021/09/08 16:53:59 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
