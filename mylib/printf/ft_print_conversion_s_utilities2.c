/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_s_utilities2.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:48:28 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:50:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_s_utilities.h"

int	handle_no_precision(int *flags, int str_len, char *str)
{
	int	printed_bytes;

	if (flags[2] > str_len)
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			ft_putstr_fd(str, 1);
			while (flags[2]-- - str_len)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags[2]-- - str_len)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(str, 1);
		}
	}
	else
	{
		printed_bytes = str_len;
		ft_putstr_fd(str, 1);
	}
	return (printed_bytes);
}

static int	handle_prec_l_str(int *flags, int precision, char *str)
{
	int	printed_bytes;
	int	i;

	printed_bytes = flags[2];
	if (flags[0])
	{
		i = -1;
		while (++i < precision)
			ft_putchar_fd(*str++, 1);
		while (flags[2]-- - precision)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flags[2]-- - precision)
			ft_putchar_fd(' ', 1);
		while (precision--)
			ft_putchar_fd(*str++, 1);
	}
	return (printed_bytes);
}

static int	handle_prec_l_str_fd(int *flags, int precision, char *str,
int outstream)
{
	int	printed_bytes;
	int	i;

	printed_bytes = flags[2];
	if (flags[0])
	{
		i = -1;
		while (++i < precision)
			ft_putchar_fd(*str++, outstream);
		while (flags[2]-- - precision)
			ft_putchar_fd(' ', outstream);
	}
	else
	{
		while (flags[2]-- - precision)
			ft_putchar_fd(' ', outstream);
		while (precision--)
			ft_putchar_fd(*str++, outstream);
	}
	return (printed_bytes);
}

int	handle_flags_g_prec(int *flags, int precision, int str_len,
char *str)
{
	int	printed_bytes;

	if (precision < str_len)
		printed_bytes = handle_prec_l_str(flags, precision, str);
	else
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			ft_putstr_fd(str, 1);
			while (flags[2]-- - str_len)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags[2]-- - str_len)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(str, 1);
		}
	}
	return (printed_bytes);
}

int	handle_flags_g_prec_fd(int *flags, t_2_int prec_str_len, char *str,
int outstream)
{
	int	printed_bytes;

	if (prec_str_len.a < prec_str_len.b)
		printed_bytes = handle_prec_l_str_fd(flags, prec_str_len.a, str,
				outstream);
	else
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			ft_putstr_fd(str, outstream);
			while (flags[2]-- - prec_str_len.b)
				ft_putchar_fd(' ', outstream);
		}
		else
		{
			while (flags[2]-- - prec_str_len.b)
				ft_putchar_fd(' ', outstream);
			ft_putstr_fd(str, outstream);
		}
	}
	return (printed_bytes);
}
