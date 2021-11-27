/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:33 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 10:29:33 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"

void	print_string(t_printf *mystruct, char *str, int fd)
{
	int	space_padding;
	int	printedStrLen;

	if (!str)
		str = "(null)";
	printedStrLen = ft_strlen(str);
	if (mystruct->flags.is_there_precision)
		printedStrLen = ft_minofint(mystruct->flags.precision, ft_strlen(str));
	space_padding = mystruct->flags.min_field_width - printedStrLen;
	mystruct->printed_bytes += ft_maxofint(space_padding, 0) + printedStrLen;
	if (mystruct->flags.is_left_justified)
		ft_putnstr_fd(str, printedStrLen, fd);
	while (space_padding-- > 0)
		ft_putchar_fd(' ', fd);
	if (!mystruct->flags.is_left_justified)
		ft_putnstr_fd(str, printedStrLen, fd);
}
