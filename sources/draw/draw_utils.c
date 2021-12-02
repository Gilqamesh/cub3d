#include "main.h"

void	draw_filled_circle(t_data *data, t_point center, int radius,
unsigned int color)
{
	t_point	iter;

	iter.y = center.y - radius;
	while (iter.y <= center.y + radius)
	{
		iter.x = center.x - radius;
		while (iter.x <= center.x + radius)
		{
			if ((iter.x - center.x) * (iter.x - center.x)
				+ (iter.y - center.y) * (iter.y - center.y) <= radius * radius)
				my_mlx_pixel_put(data, iter.x, iter.y, color);
			++iter.x;
		}
		++iter.y;
	}
}

// Draws a vertical line
void	verLine(t_cub3D *mystruct, int x, t_point y_start_end,
unsigned int color)
{
	int	i;

	i = y_start_end.x - 1;
	while (++i < y_start_end.y)
		my_mlx_pixel_put(&mystruct->canvas, x, i, color);
}
