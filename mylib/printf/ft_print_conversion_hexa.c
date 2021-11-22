/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_hexa.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:06:08 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:45:17 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions.h"
#include "../libft/libft.h"
#include "ft_print_conversion_hexa_utilities.h"

static int	handle_flag_g_str(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
		handle_left_justified(flags, prec_conv_sl, converted_str, outstream);
	else
	{
		if (flags[1] && prec_conv_sl.a == -1)
			while (flags[2]-- - prec_conv_sl.b)
				ft_putchar_fd('0', outstream);
		else
			while (flags[2]-- - prec_conv_sl.b)
				ft_putchar_fd(' ', outstream);
		ft_putstr_fd(converted_str, outstream);
	}
	return (printed_bytes);
}

static int	handle_prec_g_str(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	int	printed_bytes;

	if (flags[2] > prec_conv_sl.a)
		printed_bytes = handle_flag_g_precision(flags, prec_conv_sl,
				converted_str, outstream);
	else
	{
		printed_bytes = prec_conv_sl.a;
		while (prec_conv_sl.a-- - prec_conv_sl.b)
			ft_putchar_fd('0', outstream);
		ft_putstr_fd(converted_str, outstream);
	}
	return (printed_bytes);
}

static int	handle_prec_le_str(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	int	printed_bytes;

	if (flags[2] > prec_conv_sl.b)
		printed_bytes = handle_flag_g_str(flags, prec_conv_sl,
				converted_str, outstream);
	else
	{
		ft_putstr_fd(converted_str, 1);
		printed_bytes = prec_conv_sl.b;
	}
	return (printed_bytes);
}

int	print_conversion_hexa(unsigned int n, int *flags, char check_casing)
{
	char	*converted_str;
	int		conv_str_len;
	int		precision;
	int		printed_bytes;

	if (flags[3] == -3)
		precision = -1;
	else if (flags[3] == -1)
		precision = flags[4];
	else
		precision = flags[3];
	converted_str = ft_utox(n, check_casing);
	if (flags[3] == -2 && !n)
		shift_str(&converted_str);
	conv_str_len = ft_strlen(converted_str);
	if (precision > conv_str_len)
		printed_bytes = handle_prec_g_str(flags,
				(t_2_int){precision, conv_str_len}, converted_str, 1);
	else
		printed_bytes = handle_prec_le_str(flags,
				(t_2_int){precision, conv_str_len}, converted_str, 1);
	return (printed_bytes);
}

int	print_conversion_hexa_fd(unsigned int n, int *flags, char check_casing,
int outstream)
{
	char	*converted_str;
	int		conv_str_len;
	int		precision;
	int		printed_bytes;

	if (flags[3] == -3)
		precision = -1;
	else if (flags[3] == -1)
		precision = flags[4];
	else
		precision = flags[3];
	converted_str = ft_utox(n, check_casing);
	if (flags[3] == -2 && !n)
		shift_str(&converted_str);
	conv_str_len = ft_strlen(converted_str);
	if (precision > conv_str_len)
		printed_bytes = handle_prec_g_str(flags,
				(t_2_int){precision, conv_str_len}, converted_str, outstream);
	else
		printed_bytes = handle_prec_le_str(flags,
				(t_2_int){precision, conv_str_len}, converted_str, outstream);
	return (printed_bytes);
}
