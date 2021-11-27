#ifndef FT_LIBFTMATH_H
# define FT_LIBFTMATH_H

// Returns the absolute value of an integer. INT_MIN -> INT_MAX
int		ft_abs_int(int a);
// Returns the number of digits in 'n' after converted to 'base' > 1
int		ft_baselen(unsigned long n, int base);
// Returns the absolute value of a double.
double	ft_fabs(double x);
// Returns the number of digits in 'd'
int		ft_intlen(int d);
// Returns the maximum integer out of 'a' and 'b'
int		ft_maxofint(int a, int b);
// Returns the minimum integer out of 'a' and 'b'
int		ft_minofint(int a, int b);
// Rounds to the nearest integer (towards 0).
int		ft_round_to_nearest_int(double a);

#endif /* FT_LIBFTMATH_H */
