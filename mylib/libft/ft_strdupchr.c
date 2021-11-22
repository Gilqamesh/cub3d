/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:05:24 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:11:31 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Works like the function 'ft_strdup' but only copies the 'str' just before the
** first matching of char 'c' in 'str'.
*/
char	*ft_strdupchr(char *str, char c)
{
	char	*tmp;

	if (str == NULL)
		return (NULL);
	tmp = ft_strchr(str, c);
	if (tmp == NULL)
		return (ft_strdup(str));
	return (ft_substr(str, 0, tmp - str));
}
