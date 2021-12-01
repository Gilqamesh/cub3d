#include "main.h"

// If args is NULL, take the image literally without resizing and cropping
void	extract_image(t_data *images, t_vars *vars, char *path, t_extract_img_args *args)
{
	t_point				parameters;
	t_point				A;
	t_point				B;

	images->img = mlx_xpm_file_to_image(vars->mlx, path,
		&parameters.x, &parameters.y);
	if (images->img == NULL)
		exit(EXIT_FAILURE);
	images->addr = mlx_get_data_addr(images->img, &images->bits_per_pixel,
		&images->line_length, &images->endian);
	if (args == NULL)
		return ;
	if (args->A && args->B && (args->A->x < 0 || args->B->x < 0 || args->A->y < 0 || args->B->y < 0
		|| args->A->x > parameters.x || args->B->x > parameters.x
		|| args->A->y > parameters.y || args->B->y > parameters.y))
	{
		ft_dprintf(STDERR_FILENO, "Warning: wrong parameters in extract image, requested parameters: "\
			"w: %d h: %d x0: %d x1: %d y0: %d y1: %d, but image %s has parameters width %d and height %d\n",
			ft_abs_int(args->A->x - args->B->x), ft_abs_int(args->A->y - args->B->y), args->A->x, args->B->x,
			args->A->y, args->B->y, path, parameters.x, parameters.y);
		exit(EXIT_FAILURE);
	}
	if (args->A == NULL || args->B == NULL)
	{
		A.x = 0;
		A.y = parameters.y;
		B.x = parameters.x;
		B.y = 0;
	}
	else
	{
		A = *args->A;
		B = *args->B;
	}
	crop_img(vars, images, &A, &B);
	if (args->cell_size)
		resize_img(vars, images, &(t_point){B.x - A.x, A.y - B.y}, args->cell_size);
}

void	resize_img(t_vars *vars, t_data *img, t_point *old_params,
t_point *new_params)
{
	t_data	new_img;
	double	ratio_w;
	double	ratio_h;
	int		y;
	int		x;

	ratio_w = (double)(new_params->x - 1) / (old_params->x - 1);
	ratio_h = (double)(new_params->y - 1) / (old_params->y - 1);
	new_img.img = mlx_new_image(vars->mlx, new_params->x, new_params->y);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
		&new_img.line_length, &new_img.endian);
	y = -1;
	while (++y < old_params->y)
	{
		x = -1;
		while (++x < old_params->x)
			my_mlx_pixel_put(&new_img, x * ratio_w, y * ratio_h,
				get_color(img, x, y));
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
	new_img.img = mlx_new_image(vars->mlx, ft_abs_int(top_right->x - bot_left->x),
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
