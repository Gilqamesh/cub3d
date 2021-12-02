#include "main.h"

static int	extract_image_error(char *path, t_extract_img_args *args,
t_point *parameters)
{
	if (args == NULL)
		return (1);
	if (args->A && args->B && (args->A->x < 0 || args->B->x < 0
			|| args->A->y < 0 || args->B->y < 0 || args->A->x > parameters->x
			|| args->B->x > parameters->x || args->A->y > parameters->y
			|| args->B->y > parameters->y))
	{
		ft_dprintf(STDERR_FILENO, "Error: wrong parameters in extract image, "\
			"requested parameters: w: %d h: %d x0: %d x1: %d y0: %d y1: %d, "\
			"but image %s has parameters width %d and height %d\n",
			ft_abs_int(args->A->x - args->B->x), ft_abs_int(args->A->y
				- args->B->y), args->A->x, args->B->x, args->A->y, args->B->y,
			path, parameters->x, parameters->y);
		exit(EXIT_FAILURE);
	}
	return (0);
}

// If args is NULL, take the image literally without resizing and cropping
void	extract_image(t_data *images, t_vars *vars, char *path,
t_extract_img_args *args)
{
	t_point				p;
	t_line_segment		AB;

	images->img = mlx_xpm_file_to_image(vars->mlx, path, &p.x, &p.y);
	if (images->img == NULL)
		exit(EXIT_FAILURE);
	images->addr = mlx_get_data_addr(images->img, &images->bits_per_pixel,
			&images->line_length, &images->endian);
	if (extract_image_error(path, args, &p))
		return ;
	ft_bzero(&AB, sizeof(AB));
	if (args->A == NULL || args->B == NULL)
	{
		AB.A.y = p.y;
		AB.B.x = p.x;
	}
	else
	{
		AB.A = *args->A;
		AB.B = *args->B;
	}
	crop_img(vars, images, &AB.A, &AB.B);
	if (args->cell_size)
		resize_img(vars, images, &(t_point){AB.B.x - AB.A.x, AB.A.y - AB.B.y},
			args->cell_size);
}

void	resize_img(t_vars *vars, t_data *img, t_point *old_params,
t_point *new_params)
{
	t_data	new_img;
	double	ratio_w;
	double	ratio_h;
	t_point	iter;

	if (new_params->x < 2 || new_params->y < 2)
		return ;
	new_img.img = mlx_new_image(vars->mlx, new_params->x, new_params->y);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	ratio_w = (double)(old_params->x - 1) / (new_params->x - 1);
	ratio_h = (double)(old_params->y - 1) / (new_params->y - 1);
	iter.y = -1;
	while (++iter.y < new_params->y)
	{
		iter.x = -1;
		while (++iter.x < new_params->x)
			my_mlx_pixel_put(&new_img, iter.x, iter.y,
				get_color(img, iter.x * ratio_w, iter.y * ratio_h));
	}
	mlx_destroy_image(vars->mlx, img->img);
	*img = new_img;
}

void	crop_img(t_vars *vars, t_data *img,
t_point *bot_left, t_point *top_right)
{
	t_data	new_img;
	t_point	A;
	t_point	B;

	if (bot_left == NULL || top_right == NULL)
		return ;
	new_img.img = mlx_new_image(vars->mlx,
			ft_abs_int(top_right->x - bot_left->x),
			ft_abs_int(bot_left->y - top_right->y));
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	B.y = 0;
	A.y = top_right->y - 1;
	while (++A.y < bot_left->y)
	{
		A.x = bot_left->x - 1;
		B.x = 0;
		while (++A.x < top_right->x)
			my_mlx_pixel_put(&new_img, B.x++, B.y, get_color(img, A.x, A.y));
		++B.y;
	}
	mlx_destroy_image(vars->mlx, img->img);
	*img = new_img;
}

// alpha ranges from 0 to 255
void	make_image_transparent(t_data *img, int width, int height, int alpha)
{
	int	x;
	int	y;
	int	alpha_mask;

	alpha_mask = alpha << 24;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			my_mlx_pixel_put(img, x, y, get_color(img, x, y) | alpha_mask);
	}
}
