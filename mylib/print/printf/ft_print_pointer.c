/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:29:34 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 10:29:34 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprint.h"

void print_pointer(t_printf *mystruct, unsigned long addr, int fd)
{
	int		addrHexLen;
	char	*addrStr;

	addrHexLen = ft_baselen(addr, 16) + 2;
	mystruct->printed_bytes += ft_maxofint(mystruct->flags.min_field_width,
		addrHexLen);
	addrStr = ft_strjoin_free(ft_strdup("0x"), ft_itobase(addr, 16));
	if (mystruct->flags.is_left_justified)
		ft_putstr_fd(addrStr, fd);
	while (mystruct->flags.min_field_width-- - addrHexLen > 0)
		ft_putchar_fd(' ', fd);
	if (!mystruct->flags.is_left_justified)
		ft_putstr_fd(addrStr, fd);
	free(addrStr);
}
