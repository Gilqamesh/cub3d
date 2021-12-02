#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include <stdbool.h>
# include <stdint.h>

double			ft_fabs(double x);
int				round_to_nearest(double a);
void			my_mlx_pixel_put(t_data *data, double x, double y, unsigned int color);
unsigned int	get_color(t_data *data, double x, double y);
double			euclidean_distance(double a, double b);
unsigned int	divide_color(unsigned int color, double divisor);

#endif /* UTILS_H */
