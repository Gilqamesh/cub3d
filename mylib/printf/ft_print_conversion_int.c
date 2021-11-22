/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:45:29 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:03:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_conversions.h"
#include "ft_print_conversion_int_utils.h"
#include <stdlib.h>

int	print_conversion_int(int n, int *flags)
{
	char	*conv_str;
	int		conv_str_len;
	int		precision;
	int		printed_bytes;
	int		is_n;

	set_precision_and_negative(flags, &precision, n, &is_n);
	conv_str = ft_itoa(n);
	if (is_n)
		shift_str(&conv_str);
	if (flags[3] == -2 && !n)
		shift_str(&conv_str);
	conv_str_len = ft_strlen(conv_str);
	if (precision > conv_str_len)
		return (handle_prec_g_str_i(flags, precision, is_n, conv_str));
	if (flags[2] > conv_str_len)
		return (handle_flag_g_str_i(flags, precision, is_n, conv_str));
	printed_bytes = conv_str_len + is_n;
	if (is_n)
		ft_putchar_fd('-', 1);
	ft_putstr_fd(conv_str, 1);
	free(conv_str);
	return (printed_bytes);
}

int	print_conversion_int_fd(int n, int *flags, int outstream)
{
	char	*conv_str;
	int		conv_str_len;
	int		precision;
	int		printed_bytes;
	int		is_n;

	set_precision_and_negative(flags, &precision, n, &is_n);
	conv_str = ft_itoa(n);
	if (is_n)
		shift_str(&conv_str);
	if (flags[3] == -2 && !n)
		shift_str(&conv_str);
	conv_str_len = ft_strlen(conv_str);
	if (precision > conv_str_len)
		return (handle_prec_g_str_i_fd(flags, (t_2_int){precision, is_n},
			conv_str, outstream));
	if (flags[2] > conv_str_len)
		return (handle_flag_g_str_i_fd(flags, (t_2_int){precision, is_n},
			conv_str, outstream));
	printed_bytes = conv_str_len + is_n;
	if (is_n)
		ft_putchar_fd('-', outstream);
	ft_putstr_fd(conv_str, outstream);
	free(conv_str);
	return (printed_bytes);
}
