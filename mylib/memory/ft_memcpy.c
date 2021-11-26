/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:02:09 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 15:01:45 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftmemory.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*r;

	if (!dst && !src)
		return (dst);
	r = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (r);
}
