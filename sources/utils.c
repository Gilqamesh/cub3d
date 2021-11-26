#include "headers.h"

double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

// Need testing :)
int	round_to_nearest(double a)
{
	if (ft_fabs(a - (int)a) < 0.5)
		return ((int)a);
	if (a < 0)
		return ((int)(a - 1));
	return ((int)(a + 1));
}

void	my_mlx_pixel_put(t_data *data, double x, double y, unsigned int color)
{
	char	*dst;
	int		a;
	int		b;

	a = round_to_nearest(x);
	b = round_to_nearest(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Draws a line
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, int color)
{
	for (int i = y_start; i <= y_end; ++i)
		my_mlx_pixel_put(&mystruct->img, x, i, color);
}

unsigned int	get_color(t_data *data, double x, double y)
{
	char	*dst;
	int		a;
	int		b;

	a = round_to_nearest(x);
	b = round_to_nearest(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	abs_int(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	get_part_of_img(t_vars vars, t_data *img,
t_point bot_left, t_point top_right)
{
	t_data	new_img;
	t_point	A;
	t_point	B;

	new_img.img = mlx_new_image(vars.mlx, abs_int(top_right.x - bot_left.x),
		abs_int(bot_left.y - top_right.y));
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
		&new_img.line_length, &new_img.endian);
	B.x = top_right.y;
	B.y = 0;
	while (++B.x < bot_left.y)
	{
		A.x = bot_left.x;
		A.y = 0;
		while (++A.x < top_right.x)
		{
			my_mlx_pixel_put(&new_img, A.y, B.y, *(int *)(img->addr + B.x
				* img->line_length + A.x * (img->bits_per_pixel / 8)));
			++A.y;
		}
		++B.y;
	}
	mlx_destroy_image(vars.mlx, img->img);
	*img = new_img;
}

void	extract_image(t_data *images, t_args1 args1)
{
	t_point	parameters;

	images->img = mlx_xpm_file_to_image(args1.vars->mlx, args1.filePath,
		&parameters.x, &parameters.y);
	images->addr = mlx_get_data_addr(images->img, &images->bits_per_pixel,
		&images->line_length, &images->endian);
	// PRINT_HERE();
	// printf("%d %d %d %d\n", args1.A.x, args1.A.y, args1.B.x, args1.B.y);
	get_part_of_img(*args1.vars, images, args1.A, args1.B);
	// PRINT_HERE();
	// resize_img(*args1.vars, images, (t_point){args1.B.x - args1.A.x,
	// 	args1.A.y - args1.B.y}, args1.cell_size);
	// PRINT_HERE();
	// mlx_put_image_to_window(args1.vars->mlx, args1.vars->win, images->img,
	// 	args1.A.x, args1.A.y);
}

void	resize_img(t_vars vars, t_data *img, t_point old_params,
t_point new_params)
{
	t_data	new_img;
	double	ratio_w;
	double	ratio_h;
	int		y;
	int		x;

	ratio_w = (double)new_params.x / old_params.x;
	ratio_h = (double)new_params.y / old_params.y;
	new_img.img = mlx_new_image(vars.mlx, new_params.x, new_params.y);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
		&new_img.line_length, &new_img.endian);
	y = -1;
	while (++y < old_params.y)
	{
		x = -1;
		while (++x < old_params.x)
			my_mlx_pixel_put(&new_img, x * ratio_w, y * ratio_h,
				*(int *)(img->addr + y * img->line_length + x
					* (img->bits_per_pixel / 8)));
	}
	mlx_destroy_image(vars.mlx, img->img);
	*img = new_img;
}
