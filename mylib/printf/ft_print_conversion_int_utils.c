/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_int_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:47:56 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:46:30 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_int_utils.h"
#include <stdlib.h>

static int	left_justified(int *flags, t_2_int prec_is_n,
char *conv_str, int outstream)
{
	int	conv_str_len;
	int	printed_bytes;

	conv_str_len = ft_strlen(conv_str);
	printed_bytes = flags[2];
	if (flags[1] && prec_is_n.a == -1)
	{
		if (prec_is_n.b)
			ft_putchar_fd('-', outstream);
		while (flags[2]-- - conv_str_len - prec_is_n.b)
			ft_putchar_fd('0', outstream);
		ft_putstr_fd(conv_str, outstream);
	}
	else
	{
		if (prec_is_n.b)
			ft_putchar_fd('-', outstream);
		ft_putstr_fd(conv_str, outstream);
		while (flags[2]-- - conv_str_len - prec_is_n.b)
			ft_putchar_fd(' ', outstream);
	}
	return (printed_bytes);
}

int	handle_flag_g_str_i(int *flags, int precision, int is_n, char *conv_str)
{
	int	printed_bytes;
	int	conv_str_len;

	conv_str_len = ft_strlen(conv_str);
	printed_bytes = flags[2];
	if (flags[0])
		return (left_justified(flags, (t_2_int){precision, is_n}, conv_str, 1));
	if (flags[1] && precision == -1)
	{
		if (is_n)
			ft_putchar_fd('-', 1);
		while (flags[2]-- - conv_str_len - is_n)
			ft_putchar_fd('0', 1);
	}
	else
	{
		while (flags[2]-- - conv_str_len - is_n)
			ft_putchar_fd(' ', 1);
		if (is_n)
			ft_putchar_fd('-', 1);
	}
	ft_putstr_fd(conv_str, 1);
	free(conv_str);
	return (printed_bytes);
}

int	handle_flag_g_str_i_fd(int *flags, t_2_int prec_is_n,
char *conv_str, int outstream)
{
	int	printed_bytes;
	int	conv_str_len;

	conv_str_len = ft_strlen(conv_str);
	printed_bytes = flags[2];
	if (flags[0])
		return (left_justified(flags, prec_is_n, conv_str, outstream));
	if (flags[1] && prec_is_n.a == -1)
	{
		if (prec_is_n.b)
			ft_putchar_fd('-', outstream);
		while (flags[2]-- - conv_str_len - prec_is_n.b)
			ft_putchar_fd('0', outstream);
	}
	else
	{
		while (flags[2]-- - conv_str_len - prec_is_n.b)
			ft_putchar_fd(' ', outstream);
		if (prec_is_n.b)
			ft_putchar_fd('-', outstream);
	}
	ft_putstr_fd(conv_str, outstream);
	free(conv_str);
	return (printed_bytes);
}
