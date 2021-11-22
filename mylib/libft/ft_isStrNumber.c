/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isStrNumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:56:49 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 16:58:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns true if 'str' is a valid number.
** ex of valid strings: "-234", "+3432"
** ex of not valid strings: "--32", "234a"
*/
bool	ft_isStrNumber(char *str)
{
	if (str == NULL)
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
		if (ft_isdigit(*str++) == false)
			return (false);
	return (true);
}
