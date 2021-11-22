/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:51:47 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:52:11 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"
#include "ft_conversions.h"

static char	*alloc_null_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return ((char *)0);
	*str = '\0';
	return (str);
}

static void	handle_precision(int *index, char *format)
{
	(*index)++;
	if (format[*index] == '*')
		(*index)++;
	else
		while (ft_isdigit(format[*index]))
			(*index)++;
}

char	*malloc_conv_spec(char *format, int *format_index)
{
	int		index;
	int		format_len;
	char	*conversion_specifier;

	if (!*format)
		return (alloc_null_str());
	index = 0;
	while (format[index] == '-' || format[index] == '0')
		index++;
	while (ft_isdigit(format[index]))
		index++;
	if (format[index] == '*')
		index++;
	if (format[index] == '.')
		handle_precision(&index, format);
	format_len = index + 1;
	conversion_specifier = malloc(format_len + 1);
	index = -1;
	while (++index < format_len)
		conversion_specifier[index] = format[index];
	conversion_specifier[index] = '\0';
	*format_index += format_len;
	return (conversion_specifier);
}
