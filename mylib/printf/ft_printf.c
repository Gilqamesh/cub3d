/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:20:43 by edavid            #+#    #+#             */
/*   Updated: 2021/09/23 13:53:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"
#include "ft_conversions.h"

static void	set_vars_zero(int *format_index, int *n_of_printed)
{
	*format_index = 0;
	*n_of_printed = 0;
}

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
	int		format_index;
	int		n_of_printed;
	char	*conversion_specifier;

	set_vars_zero(&format_index, &n_of_printed);
	va_start(ap, format);
	while (format && format[format_index])
	{
		if (format[format_index] == '%')
		{
			format_index++;
			if (!is_valid_conv_spec((char *)format + format_index))
				continue ;
			conversion_specifier = malloc_conv_spec((char *)format
					+ format_index, &format_index);
			n_of_printed += handle_conversion_spec_fd(conversion_specifier, ap,
					fd);
			free(conversion_specifier);
			continue ;
		}
		ft_putchar_fd(*(format + format_index++), fd);
		n_of_printed++;
	}
	va_end(ap);
	return (n_of_printed);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		format_index;
	int		n_of_printed;
	char	*conversion_specifier;

	set_vars_zero(&format_index, &n_of_printed);
	while (format && format[format_index])
	{
		if (format[format_index] == '%')
		{
			format_index++;
			if (!is_valid_conv_spec((char *)format + format_index))
				continue ;
			conversion_specifier = malloc_conv_spec((char *)format
					+ format_index, &format_index);
			n_of_printed += handle_conversion_spec_fd(conversion_specifier, ap,
					fd);
			free(conversion_specifier);
			continue ;
		}
		ft_putchar_fd(*(format + format_index++), fd);
		n_of_printed++;
	}
	return (n_of_printed);
}
