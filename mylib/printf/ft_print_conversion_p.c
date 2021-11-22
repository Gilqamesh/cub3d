/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:33:26 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:47:45 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_conversions.h"

static void	handle_edge_case(int *flags, int addr_len,
int null_pp, int *ps)
{
	if (flags[2] > addr_len + 2 - null_pp)
	{
		while (flags[2]-- > addr_len + 2 - null_pp)
		{
			ft_putchar_fd(' ', 1);
			(*ps)++;
		}
	}
}

static void	handle_edge_case_fd(int *flags, int *ps,
t_2_int addr_len_and_null_pp, int outstream)
{
	if (flags[2] > addr_len_and_null_pp.a + 2 - addr_len_and_null_pp.b)
	{
		while (flags[2]-- > addr_len_and_null_pp.a + 2 - addr_len_and_null_pp.b)
		{
			ft_putchar_fd(' ', outstream);
			(*ps)++;
		}
	}
}

int	print_conversion_p(void *arg_pointer, int *flags)
{
	int	addr_len;
	int	ps;
	int	null_pp;

	null_pp = 0;
	if (!arg_pointer && flags[3] == -2)
		null_pp = 1;
	ps = 0;
	addr_len = digits_in_hexa((unsigned long)arg_pointer);
	if (flags[0])
	{
		write(1, "0x", 2);
		if (!null_pp)
			print_ultoh((unsigned long)arg_pointer, 's', STDOUT_FILENO);
		handle_edge_case(flags, addr_len, null_pp, &ps);
	}
	else
	{
		handle_edge_case(flags, addr_len, null_pp, &ps);
		write(1, "0x", 2);
		if (!null_pp)
			print_ultoh((unsigned long)arg_pointer, 's', STDOUT_FILENO);
	}
	return (addr_len + ps + 2);
}

int	print_conversion_p_fd(void *arg_pointer, int *flags, int outstream)
{
	int	addr_len;
	int	ps;
	int	null_pp;

	null_pp = 0;
	if (!arg_pointer && flags[3] == -2)
		null_pp = 1;
	ps = 0;
	addr_len = digits_in_hexa((unsigned long)arg_pointer);
	if (flags[0])
	{
		write(outstream, "0x", 2);
		if (!null_pp)
			print_ultoh((unsigned long)arg_pointer, 's', outstream);
		handle_edge_case_fd(flags, &ps, (t_2_int){addr_len, ps}, outstream);
	}
	else
	{
		handle_edge_case_fd(flags, &ps,
			(t_2_int){addr_len, ps}, outstream);
		write(outstream, "0x", 2);
		if (!null_pp)
			print_ultoh((unsigned long)arg_pointer, 's', outstream);
	}
	return (addr_len + ps + 2);
}
