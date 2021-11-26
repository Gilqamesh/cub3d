/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printintarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:50:40 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 19:49:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"

void	ft_printintarr(int *arr, int n)
{
	int	i;

	if (arr == NULL || n == 0)
		return ;
	i = -1;
	while (++i < n)
	{
		ft_printf("%d", arr[i]);
		if (i < n - 1)
			ft_printf(" ");
	}
	ft_printf("\n");
}
