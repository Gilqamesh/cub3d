/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:36 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 10:29:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_printf	mystruct;

	if (format == NULL || fd < 0)
		return (-1);
	ft_bzero(&mystruct, sizeof(mystruct));
	while (format[mystruct.index])
	{
		if (format[mystruct.index] == '%')
		{
			mystruct.index++;
			ft_set_flags((char *)format, &mystruct);
			ft_conversion_router(format[mystruct.index], &mystruct, ap, fd);
		}
		else
		{
			ft_putchar_fd(format[mystruct.index], fd);
			mystruct.printed_bytes++;
		}
		mystruct.index++;
	}
	return (mystruct.printed_bytes);
}
