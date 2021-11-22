/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:33:04 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:45:10 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions.h"
#include "../libft/libft.h"

static void	handle_left_justified(int *flags, int outstream)
{
	if (flags[1])
	{
		while (flags[2]-- - outstream)
			ft_putchar_fd('0', outstream);
		ft_putchar_fd('%', outstream);
	}
	else
	{
		ft_putchar_fd('%', outstream);
		while (flags[2]-- - outstream)
			ft_putchar_fd(' ', outstream);
	}
}

static void	handle_right_justified(int *flags, int *printed_bytes,
int outstream)
{
	*printed_bytes = 1;
	if (flags[1])
	{
		while (flags[2]-- - outstream)
			ft_putchar_fd('0', outstream);
	}
	else
	{
		while (flags[2]-- - outstream)
			ft_putchar_fd(' ', outstream);
	}
	ft_putchar_fd('%', outstream);
}

int	print_conversion_perc(int *flags, int outstream)
{
	int		printed_bytes;

	if (flags[2] > 1)
	{
		printed_bytes = flags[2];
		if (flags[0])
			handle_left_justified(flags, outstream);
		else
			handle_right_justified(flags, &printed_bytes, outstream);
	}
	else
	{
		ft_putchar_fd('%', outstream);
		printed_bytes = 1;
	}
	return (printed_bytes);
}

int	print_conversion(char conversion, va_list ap, int *flags)
{
	if (conversion == 'c')
		return (print_conversion_c((unsigned char)va_arg(ap, int), flags));
	else if (conversion == 's')
		return (print_conversion_s(va_arg(ap, char *), flags));
	else if (conversion == 'p')
		return (print_conversion_p(va_arg(ap, void *), flags));
	else if (conversion == 'd' || conversion == 'i')
		return (print_conversion_int(va_arg(ap, int), flags));
	else if (conversion == 'u')
		return (print_conversion_uint((unsigned int)va_arg(ap, int), flags));
	else if (conversion == 'x' || conversion == 'X')
		return (print_conversion_hexa((unsigned int)va_arg(ap, int), flags,
				conversion));
	else if (conversion == '%')
		return (print_conversion_perc(flags, 1));
	else
		return (-1);
}

int	print_conversion_fd(char conversion, va_list ap, int *flags, int outstream)
{
	if (conversion == 'c')
		return (print_conversion_c_fd((unsigned char)va_arg(ap, int), flags,
				outstream));
	else if (conversion == 's')
		return (print_conversion_s_fd(va_arg(ap, char *), flags, outstream));
	else if (conversion == 'p')
		return (print_conversion_p_fd(va_arg(ap, void *), flags, outstream));
	else if (conversion == 'd' || conversion == 'i')
		return (print_conversion_int_fd(va_arg(ap, int), flags, outstream));
	else if (conversion == 'u')
		return (print_conversion_uint_fd((unsigned int)va_arg(ap, int), flags,
				outstream));
	else if (conversion == 'x' || conversion == 'X')
		return (print_conversion_hexa_fd((unsigned int)va_arg(ap, int), flags,
				conversion, outstream));
	else if (conversion == '%')
		return (print_conversion_perc(flags, outstream));
	else
		return (-1);
}
