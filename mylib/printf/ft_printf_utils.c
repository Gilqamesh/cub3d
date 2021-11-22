/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:43:59 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:54:25 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"
#include "ft_conversions.h"

int	is_valid_conv_spec(char *conv_spec)
{
	if (*conv_spec == '%')
		return (1);
	while (*conv_spec == '-' || *conv_spec == '0')
		conv_spec++;
	while (ft_isdigit(*conv_spec))
		conv_spec++;
	if (*conv_spec == '*')
		conv_spec++;
	if (*conv_spec == '.')
	{
		conv_spec++;
		if (*conv_spec == '*')
			conv_spec++;
		else
			while (ft_isdigit(*conv_spec))
				conv_spec++;
	}
	if (*conv_spec == '\0' || (*conv_spec != 'c' && *conv_spec != 's'
			&& *conv_spec != 'p' && *conv_spec != 'd' && *conv_spec != 'i'
			&& *conv_spec != 'u' && *conv_spec != 'x' && *conv_spec != 'X'
			&& *conv_spec != '%'))
		return (0);
	return (1);
}

int	handle_conversion_spec(char *conv_spec, va_list ap)
{
	int		*flags;
	int		conversion_index;
	int		printed_bytes;

	flags = ft_calloc(5, sizeof(int));
	conversion_index = set_flags(conv_spec, flags, ap);
	printed_bytes = print_conversion(conv_spec[conversion_index], ap, flags);
	free(flags);
	return (printed_bytes);
}

int	handle_conversion_spec_fd(char *conv_spec, va_list ap, int outstream)
{
	int		*flags;
	int		conversion_index;
	int		printed_bytes;

	flags = ft_calloc(5, sizeof(int));
	conversion_index = set_flags(conv_spec, flags, ap);
	printed_bytes = print_conversion_fd(conv_spec[conversion_index], ap, flags,
			outstream);
	free(flags);
	return (printed_bytes);
}
