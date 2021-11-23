#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

double	ft_fabs(double x);
int		round_to_nearest(double a);
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, int color);

#endif /* UTILS_H */
