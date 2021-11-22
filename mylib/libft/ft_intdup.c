/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:50:15 by edavid            #+#    #+#             */
/*   Updated: 2021/07/31 11:51:57 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	*ft_intdup(int d)
{
	int	*result;

	result = malloc(sizeof(*result));
	if (result == NULL)
		return (NULL);
	*result = d;
	return (result);
}
