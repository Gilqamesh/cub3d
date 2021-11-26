/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:10:51 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 15:02:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftmemory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*r;

	r = b;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (r);
}
