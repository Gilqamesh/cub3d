#ifndef FT_LIBFTPRINT_H
# define FT_LIBFTPRINT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include "ft_libftmemory.h"
# include "ft_libftput.h"
# include "ft_libftstring.h"
# include "ft_libftmath.h"
# include "ft_libftctype.h"

typedef struct s_printf_flags
{
	bool	is_left_justified;
	bool	zero_padding;
	bool	is_there_precision;
	int		precision;
	bool	is_alternate_form;
	bool	is_space_prefixed;
	bool	is_sign_prefixed;
	int		min_field_width;
}	t_printf_flags;

typedef struct s_printf
{
	t_printf_flags	flags;
	int				printed_bytes;
	int				index;
}	t_printf;

typedef struct s_pad_vars
{
	int	space_padding;
	int	zero_padding;
	int	n_len;
}	t_pad_vars;

typedef struct s_printf_vars
{
	unsigned int	n;
	char			c;
	bool			is_left_justified;
	int				fd;
}	t_printf_vars;

// Works like printf
// Needs support: wildcard flag, %f
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
void	ft_set_flags(char *format, t_printf *mystruct);
void	ft_conversion_router(char conversion, t_printf *mystruct, va_list ap,
			int fd);
void	print_character(t_printf *mystruct, unsigned char c, int fd);
void	print_string(t_printf *mystruct, char *str, int fd);
void	print_pointer(t_printf *mystruct, unsigned long addr, int fd);
void	print_integer(t_printf *mystruct, int n, int fd);
void	print_unsigned(t_printf *mystruct, unsigned int n, int fd);
void	print_hexa(t_printf *mystruct, unsigned int n, char conversion, int fd);
void	print_percent(t_printf *mystruct, int fd);

// Prints 'n' integers from 'arr' as integers
void	ft_printintarr(int *arr, int n);

#endif /* FT_LIBFTPRINT_H */
