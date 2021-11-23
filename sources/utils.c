#include "utils.h"
#include "bass.h"
#include "definitions.h"

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

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
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
