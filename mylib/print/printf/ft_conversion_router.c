/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_router.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:24:57 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 19:47:07 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"

void	ft_conversion_router(char conversion, t_printf *mystruct, va_list ap, int fd)
{
	if (conversion == 'c')
		print_character(mystruct, (unsigned char)va_arg(ap, int), fd);
	else if (conversion == 's')
		print_string(mystruct, va_arg(ap, char *), fd);
	else if (conversion == 'p')
		print_pointer(mystruct, (unsigned long)va_arg(ap, void *), fd);
	else if (conversion == 'd' || conversion == 'i')
		print_integer(mystruct, va_arg(ap, int), fd);
	else if (conversion == 'u')
		print_unsigned(mystruct, va_arg(ap, unsigned int), fd);
	else if (conversion == 'x' || conversion == 'X')
		print_hexa(mystruct, va_arg(ap, unsigned int), conversion, fd);
	else if (conversion == '%')
		print_percent(mystruct, fd);
}
