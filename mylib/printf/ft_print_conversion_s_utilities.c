/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_s_utilities.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:31:13 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:49:25 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_s_utilities.h"

void	set_precision(int *precision, int *flags, int str_len)
{
	if (flags[3] == -2)
		*precision = 0;
	else if (flags[3] == -3)
		*precision = -1;
	else if (flags[3] == -1)
		*precision = flags[4];
	else
		*precision = flags[3];
	if (*precision > str_len && flags[3] != -1)
		*precision = str_len;
}

int	handle_no_precision_fd(int *flags, int str_len, char *str, int outstream)
{
	int	printed_bytes;

	if (flags[2] > str_len)
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			ft_putstr_fd(str, outstream);
			while (flags[2]-- - str_len)
				ft_putchar_fd(' ', outstream);
		}
		else
		{
			while (flags[2]-- - str_len)
				ft_putchar_fd(' ', outstream);
			ft_putstr_fd(str, outstream);
		}
	}
	else
	{
		printed_bytes = str_len;
		ft_putstr_fd(str, outstream);
	}
	return (printed_bytes);
}

int	handle_flags_l_str(int *flags, int str_len, char *str)
{
	int	printed_bytes;

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
	return (printed_bytes);
}

int	handle_flags_l_str_fd(int *flags, int str_len, char *str, int outstream)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		ft_putstr_fd(str, outstream);
		while (flags[2]-- - str_len)
			ft_putchar_fd(' ', outstream);
	}
	else
	{
		while (flags[2]-- - str_len)
			ft_putchar_fd(' ', outstream);
		ft_putstr_fd(str, outstream);
	}
	return (printed_bytes);
}
