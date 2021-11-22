/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:31:15 by edavid            #+#    #+#             */
/*   Updated: 2021/09/22 18:33:25 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_H
# define FT_CONVERSIONS_H

# include <stdarg.h>
int		print_conversion(char conversion, va_list ap, int *flags);
int		print_conversion_fd(char conversion, va_list ap, int *flags,
			int outstream);
int		print_conversion_c(unsigned char c, int *flags);
int		print_conversion_c_fd(unsigned char c, int *flags, int outstream);
int		print_conversion_s(char *str, int *flags);
int		print_conversion_s_fd(char *str, int *flags, int outstream);
int		print_conversion_p(void *arg_pointer, int *flags);
int		print_conversion_p_fd(void *arg_pointer, int *flags, int outstream);
int		print_conversion_int(int n, int *flags);
int		print_conversion_int_fd(int n, int *flags, int outstream);
int		print_conversion_uint(unsigned int n, int *flags);
int		print_conversion_uint_fd(unsigned int n, int *flags, int outstream);
int		print_conversion_hexa(unsigned int n, int *flags, char check_casing);
int		print_conversion_hexa_fd(unsigned int n, int *flags, char check_casing,
			int outstream);
int		print_conversion_perc(int *flags, int outstream);
void	print_ultoh(unsigned long n, char check_casing, int outstream);
int		digits_in_hexa(unsigned long n);
void	shift_str(char **str);
char	*ft_utox(unsigned int n, char check_casing);
char	*ft_utoa(unsigned int n);
int		ft_uintlen(unsigned int n);
char	*ft_initstr(char **str, int len, int is_zero);

#endif
