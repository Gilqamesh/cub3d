/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:24:54 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 19:49:34 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"

static void	set_flags_helper(char *format, t_printf *mystruct)
{
	while (1)
	{
		if (format[mystruct->index] == '#' || format[mystruct->index] == '0'
			|| format[mystruct->index] == '-' || format[mystruct->index] == ' '
			|| format[mystruct->index] == '+')
		{
			if (format[mystruct->index] == '#')
				mystruct->flags.is_alternate_form = true;
			else if (format[mystruct->index] == '0')
				mystruct->flags.zero_padding = true;
			else if (format[mystruct->index] == '-')
				mystruct->flags.is_left_justified = true;
			else if (format[mystruct->index] == ' ')
				mystruct->flags.is_space_prefixed = true;
			else if (format[mystruct->index] == '+')
				mystruct->flags.is_sign_prefixed = true;
			mystruct->index++;
		}
		else
			break ;
	}
}

void	ft_set_flags(char *format, t_printf *mystruct)
{
	ft_bzero(&mystruct->flags, sizeof(mystruct->flags));
	set_flags_helper(format, mystruct);
	if (ft_isdigit(format[mystruct->index]))
	{
		mystruct->flags.min_field_width = ft_atoi(format + mystruct->index);
		mystruct->index += ft_intlen(mystruct->flags.min_field_width);
	}
	if (format[mystruct->index] == '.')
	{
		mystruct->flags.is_there_precision = true;
		mystruct->index++;
		while (format[mystruct->index] == '0')
			mystruct->index++;
		if (ft_isdigit(format[mystruct->index]))
		{
			mystruct->flags.precision = ft_atoi(format + mystruct->index);
			mystruct->index += ft_intlen(mystruct->flags.precision);
		}
	}
}
