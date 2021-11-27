#ifndef IMAGE_MANIPULATION_H
# define IMAGE_MANIPULATION_H

# include "struct.h"

void	extract_image(t_data *images, t_args1 args1);
void	resize_img(t_vars vars, t_data *img, t_point old_params,
			t_point new_params);
void	get_part_of_img(t_vars vars, t_data *img,
			t_point bot_left, t_point top_right);

#endif /* IMAGE_MANIPULATION_H */
