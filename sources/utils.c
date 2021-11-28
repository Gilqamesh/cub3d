#include "headers.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, unsigned int color)
{
	char	*dst;
	int		a;
	int		b;

	a = ft_round_to_nearest_int(x);
	b = ft_round_to_nearest_int(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Draws a line
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, int color)
{
	for (int i = y_start; i <= y_end; ++i)
		my_mlx_pixel_put(&mystruct->canvas, x, i, color);
}

unsigned int	get_color(t_data *data, double x, double y)
{
	char	*dst;
	int		a;
	int		b;

	a = ft_round_to_nearest_int(x);
	b = ft_round_to_nearest_int(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
