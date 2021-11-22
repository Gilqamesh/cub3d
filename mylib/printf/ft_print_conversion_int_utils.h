/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_int_utils.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:47:18 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:05:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONVERSION_INT_UTILS_H
# define FT_PRINT_CONVERSION_INT_UTILS_H

void	set_precision_and_negative(int *flags, int *precision, int n,
			int *is_negative);
int		handle_prec_g_str_i(int *flags, int precision, int is_negative,
			char *converted_str);
int		handle_prec_g_str_i_fd(int *flags, t_2_int prec_is_n,
			char *converted_str, int outstream);
int		handle_flag_g_str_i(int *flags, int precision, int is_n,
			char *conv_str);
int		handle_flag_g_str_i_fd(int *flags, t_2_int prec_is_n,
			char *conv_str, int outstream);

#endif
