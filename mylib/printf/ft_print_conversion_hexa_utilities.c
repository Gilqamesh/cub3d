/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_hexa_utilities.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:52:21 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:22:34 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_hexa_utilities.h"

int	handle_flag_g_precision(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		while (prec_conv_sl.a - prec_conv_sl.b++)
			ft_putchar_fd('0', outstream);
		ft_putstr_fd(converted_str, outstream);
		while (flags[2]-- - prec_conv_sl.a)
			ft_putchar_fd(' ', outstream);
	}
	else
	{
		while (flags[2]-- - prec_conv_sl.a)
			ft_putchar_fd(' ', outstream);
		while (prec_conv_sl.a-- - prec_conv_sl.b)
			ft_putchar_fd('0', outstream);
		ft_putstr_fd(converted_str, outstream);
	}
	return (printed_bytes);
}

void	handle_left_justified(int *flags, t_2_int prec_conv_sl,
char *converted_str, int outstream)
{
	if (flags[1] && prec_conv_sl.a == -1)
	{
		while (flags[2]-- - prec_conv_sl.b)
			ft_putchar_fd('0', outstream);
		ft_putstr_fd(converted_str, outstream);
	}
	else
	{
		ft_putstr_fd(converted_str, outstream);
		while (flags[2]-- - prec_conv_sl.b)
			ft_putchar_fd(' ', outstream);
	}
}
