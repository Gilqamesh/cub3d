/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:22:00 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 14:46:47 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "ft_libftmath.h"

int	ft_abs_int(int a)
{
	if (a == INT_MIN)
		return (INT_MAX);
	if (a < 0)
		return (-a);
	return (a);
}
