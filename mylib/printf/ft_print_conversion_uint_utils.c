/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_uint_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:57:35 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:49:47 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_uint_utils.h"

static int	handle_flags_g_prec_u(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		while (prec_conv_sl.a-- - prec_conv_sl.b)
		{
			ft_putchar_fd('0', outstream);
			flags[2]--;
		}
		ft_putstr_fd(converted_str, outstream);
		while (flags[2]-- - prec_conv_sl.b)
			ft_putchar_fd(' ', outstream);
		return (printed_bytes);
	}
	while (flags[2]-- - prec_conv_sl.a)
		ft_putchar_fd(' ', outstream);
	while (prec_conv_sl.a-- - prec_conv_sl.b)
		ft_putchar_fd('0', outstream);
	ft_putstr_fd(converted_str, outstream);
	return (printed_bytes);
}

int	handle_prec_g_str_u(int *flags, int precision, int conv_str_len,
char *converted_str)
{
	int	printed_bytes;

	if (flags[2] > precision)
		return (handle_flags_g_prec_u(flags, (t_2_int){precision, conv_str_len},
			converted_str, 1));
	printed_bytes = precision;
	while (precision-- - conv_str_len)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(converted_str, 1);
	return (printed_bytes);
}

int	handle_prec_g_str_u_fd(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	int	printed_bytes;

	if (flags[2] > prec_conv_sl.a)
		return (handle_flags_g_prec_u(flags, prec_conv_sl,
				converted_str, outstream));
	printed_bytes = prec_conv_sl.a;
	while (prec_conv_sl.a-- - prec_conv_sl.b)
		ft_putchar_fd('0', outstream);
	ft_putstr_fd(converted_str, outstream);
	return (printed_bytes);
}

int	handle_flags_g_str_u(int *flags, int prec, int conv_s_len, char *conv_str)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		if (flags[1] && prec == -1)
		{
			while (flags[2]-- - conv_s_len)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(conv_str, 1);
			return (printed_bytes);
		}
		ft_putstr_fd(conv_str, 1);
		while (flags[2]-- - conv_s_len)
			ft_putchar_fd(' ', 1);
		return (printed_bytes);
	}
	if (flags[1] && prec == -1)
		while (flags[2]-- - conv_s_len)
			ft_putchar_fd('0', 1);
	else
		while (flags[2]-- - conv_s_len)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd(conv_str, 1);
	return (printed_bytes);
}

int	handle_flags_g_str_u_fd(int *flags, t_2_int prec_conv_sl,
char *conv_str, int outstream)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		if (flags[1] && prec_conv_sl.a == -1)
		{
			while (flags[2]-- - prec_conv_sl.b)
				ft_putchar_fd('0', outstream);
			ft_putstr_fd(conv_str, outstream);
			return (printed_bytes);
		}
		ft_putstr_fd(conv_str, outstream);
		while (flags[2]-- - prec_conv_sl.b)
			ft_putchar_fd(' ', outstream);
		return (printed_bytes);
	}
	if (flags[1] && prec_conv_sl.a == -1)
		while (flags[2]-- - prec_conv_sl.b)
			ft_putchar_fd('0', outstream);
	else
		while (flags[2]-- - prec_conv_sl.b)
			ft_putchar_fd(' ', outstream);
	ft_putstr_fd(conv_str, outstream);
	return (printed_bytes);
}
