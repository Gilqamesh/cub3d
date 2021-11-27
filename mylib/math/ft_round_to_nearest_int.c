/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_to_nearest_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:08:16 by edavid            #+#    #+#             */
/*   Updated: 2021/11/27 11:08:28 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftmath.h"

int	ft_round_to_nearest_int(double a)
{
	if (ft_fabs(a - (int)a) < 0.5)
		return ((int)a);
	if (a < 0)
		return ((int)(a - 1));
	return ((int)(a + 1));
}
