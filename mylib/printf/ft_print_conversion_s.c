/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:29:49 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:48:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_conversions.h"
#include "ft_print_conversion_s_utilities.h"

static int	handle_else_case(int precision, int str_len, char *str)
{
	int	printed_bytes;

	if (precision < str_len)
	{
		printed_bytes = precision;
		while (precision--)
			ft_putchar_fd(*str++, 1);
	}
	else
	{
		printed_bytes = str_len;
		ft_putstr_fd(str, 1);
	}
	return (printed_bytes);
}

static int	handle_else_case_fd(int precision, int str_len, char *str,
int outstream)
{
	int	printed_bytes;

	if (precision < str_len)
	{
		printed_bytes = precision;
		while (precision--)
			ft_putchar_fd(*str++, outstream);
	}
	else
	{
		printed_bytes = str_len;
		ft_putstr_fd(str, outstream);
	}
	return (printed_bytes);
}

int	print_conversion_s(char *str, int *flags)
{
	int	str_len;
	int	printed_bytes;
	int	precision;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	set_precision(&precision, flags, str_len);
	printed_bytes = 0;
	if (precision == -1)
		printed_bytes = handle_no_precision(flags, str_len, str);
	else if (flags[2] > precision)
		printed_bytes = handle_flags_g_prec(flags, precision, str_len, str);
	else if (flags[2] > str_len)
		printed_bytes = handle_flags_l_str(flags, str_len, str);
	else
		printed_bytes = handle_else_case(precision, str_len, str);
	return (printed_bytes);
}

int	print_conversion_s_fd(char *str, int *flags, int outstream)
{
	int	str_len;
	int	printed_bytes;
	int	precision;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	set_precision(&precision, flags, str_len);
	printed_bytes = 0;
	if (precision == -1)
		printed_bytes = handle_no_precision_fd(flags, str_len, str, outstream);
	else if (flags[2] > precision)
		printed_bytes = handle_flags_g_prec_fd(flags,
				(t_2_int){precision, str_len}, str, outstream);
	else if (flags[2] > str_len)
		printed_bytes = handle_flags_l_str_fd(flags, str_len, str, outstream);
	else
		printed_bytes = handle_else_case_fd(precision, str_len, str, outstream);
	return (printed_bytes);
}
