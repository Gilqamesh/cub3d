#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include <stdbool.h>
# include <stdint.h>

double	ft_fabs(double x);
int		round_to_nearest(double a);
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
void	get_part_of_img(t_vars vars, t_data *img,
            t_point bot_left, t_point top_right);
void	extract_image(t_data *images, t_args1 args1);
void	resize_img(t_vars vars, t_data *img, t_point old_params,
t_point new_params);
int 	get_color(t_data *data, double x, double y);

#endif /* UTILS_H */
