/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_hexa_utilities.h               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:05:13 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:22:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONVERSION_HEXA_UTILITIES_H
# define FT_PRINT_CONVERSION_HEXA_UTILITIES_H

int		handle_flag_g_precision(int *flags, t_2_int prec_conv_sl,
			char *converted_str, int outstream);
void	handle_left_justified(int *flags, t_2_int prec_conv_sl,
			char *converted_str, int outstream);

#endif
