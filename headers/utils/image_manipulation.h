#ifndef IMAGE_MANIPULATION_H
# define IMAGE_MANIPULATION_H

# include "struct.h"

void	extract_image(t_data *images, t_vars *vars, char *path,
			t_extract_img_args *args);
void	resize_img(t_vars *vars, t_data *img, t_point *old_params,
			t_point *new_params);
void	crop_img(t_vars *vars, t_data *img,
			t_point *bot_left, t_point *top_right);
void	make_image_transparent(t_data *img, int width, int height, int alpha);

#endif /* IMAGE_MANIPULATION_H */
