/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isAlphaNumeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:04:51 by edavid            #+#    #+#             */
/*   Updated: 2021/09/08 16:07:19 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns true if 'str' only consists of alphanumeric characters.
*/
bool	ft_isStrAlphaNumeric(char *str)
{
	if (str == NULL)
		return (false);
	while (*str)
		if (!ft_isalnum(*str++))
			return (false);
	return (true);
}
