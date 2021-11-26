/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:28 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 19:47:15 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_libftprint.h"

static char	*get_sign_prefix(t_printf *mystruct, int n)
{
	if (n < 0)
		return ("-");
	else if (mystruct->flags.is_sign_prefixed)
		return ("+");
	else if (mystruct->flags.is_space_prefixed)
		return (" ");
	else
		return ("");
}

static void	print_n(char *sign_prefix, t_pad_vars *vars, int n,
t_printf_vars x)
{
	if (x.is_left_justified == false)
		while (vars->space_padding--)
			ft_putchar_fd(' ', x.fd);
	ft_putstr_fd(sign_prefix, x.fd);
	while (vars->zero_padding--)
		ft_putchar_fd('0', x.fd);
	if (n == INT_MIN)
		ft_putstr_fd("2147483648", x.fd);
	else if (vars->n_len)
		ft_putnbr_fd(ft_abs_int(n), x.fd);
	if (x.is_left_justified == true)
		while (vars->space_padding--)
			ft_putchar_fd(' ', x.fd);
}

static void	set_vars(t_printf *mystruct, t_pad_vars *vars, char **sign_prefix,
int n)
{
	vars->n_len = ft_intlen(n);
	if (mystruct->flags.is_there_precision && !n)
		vars->n_len = 0;
	*sign_prefix = get_sign_prefix(mystruct, n);
	vars->zero_padding = ft_maxofint(mystruct->flags.precision
			- vars->n_len, 0);
	vars->space_padding = ft_maxofint(mystruct->flags.min_field_width
			- ft_strlen(*sign_prefix) - vars->zero_padding - vars->n_len, 0);
	if (mystruct->flags.zero_padding)
	{
		vars->zero_padding = vars->space_padding;
		vars->space_padding = 0;
	}
}

static void	set_flags(t_printf *mystruct)
{
	if (mystruct->flags.is_there_precision || mystruct->flags.is_left_justified)
		mystruct->flags.zero_padding = false;
	if (mystruct->flags.is_sign_prefixed)
		mystruct->flags.is_space_prefixed = false;
}

void	print_integer(t_printf *mystruct, int n, int fd)
{
	t_pad_vars	vars;
	char		*sign_prefix;

	set_flags(mystruct);
	set_vars(mystruct, &vars, &sign_prefix, n);
	mystruct->printed_bytes += vars.space_padding + ft_strlen(sign_prefix)
		+ vars.zero_padding + vars.n_len;
	if (mystruct->flags.is_left_justified)
		print_n(sign_prefix, &vars, n, (t_printf_vars){0, 0, true, fd});
	else
		print_n(sign_prefix, &vars, n, (t_printf_vars){0, 0, false, fd});
}
