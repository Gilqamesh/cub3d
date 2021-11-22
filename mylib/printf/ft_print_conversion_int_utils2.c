/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_int_utils2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:46:02 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:46:33 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_int_utils.h"
#include <stdlib.h>

void	set_precision_and_negative(int *flags, int *precision, int n,
int *is_n)
{
	if (flags[3] == -3)
		*precision = -1;
	else if (flags[3] == -1)
		*precision = flags[4];
	else
		*precision = flags[3];
	*is_n = 0;
	if (n < 0)
		*is_n = 1;
}

static void	print_part(t_2_int prec_is_n, int conv_str_len, char *converted_str,
int outstream)
{
	if (prec_is_n.b)
		ft_putchar_fd('-', outstream);
	while (prec_is_n.a - conv_str_len++)
		ft_putchar_fd('0', outstream);
	ft_putstr_fd(converted_str, outstream);
}

int	handle_prec_g_str_i(int *flags, int precision, int is_n,
char *convStr)
{
	int	conv_str_len;
	int	printed_bytes;

	conv_str_len = ft_strlen(convStr);
	if (flags[2] > precision)
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			print_part((t_2_int){precision, is_n}, conv_str_len, convStr, 1);
			while (flags[2]-- - precision - is_n)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags[2]-- - precision - is_n)
				ft_putchar_fd(' ', 1);
			print_part((t_2_int){precision, is_n}, conv_str_len, convStr, 1);
		}
		return (printed_bytes);
	}
	printed_bytes = precision + is_n;
	print_part((t_2_int){precision, is_n}, conv_str_len, convStr, 1);
	free(convStr);
	return (printed_bytes);
}

int	handle_prec_g_str_i_fd(int *flags, t_2_int prec_is_n,
char *converted_str, int outstream)
{
	int	conv_str_len;
	int	printed_bytes;

	conv_str_len = ft_strlen(converted_str);
	if (flags[2] > prec_is_n.a)
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			print_part(prec_is_n, conv_str_len, converted_str, outstream);
			while (flags[2]-- - prec_is_n.a - prec_is_n.b)
				ft_putchar_fd(' ', outstream);
		}
		else
		{
			while (flags[2]-- - prec_is_n.a - prec_is_n.b)
				ft_putchar_fd(' ', outstream);
			print_part(prec_is_n, conv_str_len, converted_str, outstream);
		}
		return (printed_bytes);
	}
	printed_bytes = prec_is_n.a + prec_is_n.b;
	print_part(prec_is_n, conv_str_len, converted_str, outstream);
	free(converted_str);
	return (printed_bytes);
}
