/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:50:15 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 15:01:03 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftmemory.h"

int	*ft_intdup(int d)
{
	int	*result;

	result = malloc(sizeof(*result));
	if (result == NULL)
		return (NULL);
	*result = d;
	return (result);
}
