/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:39:20 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 19:47:26 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_libftprint.h"

static void	print_n(t_pad_vars *vars, unsigned int n, bool is_left_justified,
int fd)
{
	if (!is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', fd);
	while (vars->zero_padding--)
		ft_putchar_fd('0', fd);
	if (vars->n_len)
		ft_putnbr_fd(n, fd);
	if (is_left_justified)
		while (vars->space_padding--)
			ft_putchar_fd(' ', fd);
}

static void	set_vars(t_printf *mystruct, t_pad_vars *vars, unsigned int n)
{
	vars->n_len = ft_baselen(n, 10);
	if (mystruct->flags.is_there_precision && !n)
		vars->n_len = 0;
	vars->zero_padding = ft_maxofint(mystruct->flags.precision
			- vars->n_len, 0);
	vars->space_padding = ft_maxofint(mystruct->flags.min_field_width
			- vars->zero_padding - vars->n_len, 0);
	if (mystruct->flags.zero_padding)
	{
		vars->zero_padding = ft_maxofint(vars->zero_padding,
				vars->space_padding);
		vars->space_padding = 0;
	}
}

static void	set_flags(t_printf *mystruct)
{
	if (mystruct->flags.is_there_precision || mystruct->flags.is_left_justified)
		mystruct->flags.zero_padding = false;
}

void	print_unsigned(t_printf *mystruct, unsigned int n, int fd)
{
	t_pad_vars	vars;

	set_flags(mystruct);
	set_vars(mystruct, &vars, n);
	mystruct->printed_bytes += vars.space_padding + vars.zero_padding
		+ vars.n_len;
	if (mystruct->flags.is_left_justified)
		print_n(&vars, n, true, fd);
	else
		print_n(&vars, n, false, fd);
}
