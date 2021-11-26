/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:35 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 10:29:35 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"
#include "ft_libftput.h"

void	print_character(t_printf *mystruct, unsigned char c, int fd)
{
	mystruct->printed_bytes += 1;
	if (mystruct->flags.min_field_width > 1)
		mystruct->printed_bytes += mystruct->flags.min_field_width - 1;
	if (mystruct->flags.is_left_justified)
		ft_putchar_fd(c, fd);
	while (--mystruct->flags.min_field_width > 0)
		ft_putchar_fd(' ', fd);
	if (!mystruct->flags.is_left_justified)
		ft_putchar_fd(c, fd);
}
