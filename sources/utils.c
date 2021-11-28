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

// Draws a vertical line
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, int color)
{
	for (int i = y_start; i <= y_end; ++i)
		my_mlx_pixel_put(&mystruct->canvas, x, i, color);
}

// Based on Bresenham's algorithm
void	draw_line(t_data *data, t_point A, t_point B, int color)
{
	t_point	tmp;
	int	deltaX;
	int	deltaY;
	int	decision_var;

	deltaX = ft_abs_int(B.x - A.x);
	deltaY = ft_abs_int(B.y - A.y);
	if (deltaY <= deltaX && deltaY >= -deltaX)
	{
		if (B.x < A.x)
		{
			tmp.x = B.x;
			tmp.y = B.y;
			B.x = A.x;
			B.y = A.y;
			A.x = tmp.x;
			A.y = tmp.y;
		}
		if (deltaY >= 0)
			decision_var = 2 * deltaY - deltaX;
		else
			decision_var = -deltaX;
		tmp.x = A.x;
		tmp.y = A.y;
		while (tmp.x <= B.x)
		{
			my_mlx_pixel_put(data, tmp.x, tmp.y, color);
			if (decision_var < 0)
			{
				if (deltaY >= 0)
					decision_var += 2 * deltaY;
				else
					decision_var -= 2 * deltaY;
			}
			else
			{
				if (B.y > A.y)
					++tmp.y;
				else
					--tmp.y;
				if (deltaY >= 0)
					decision_var += 2 * (deltaY - deltaX);
				else
					decision_var -= 2 * (deltaY + deltaX);
			}
			++tmp.x;
		}
	}
	else
	{
		if (B.y < A.y)
		{
			tmp.x = B.x;
			tmp.y = B.y;
			B.x = A.x;
			B.y = A.y;
			A.x = tmp.x;
			A.y = tmp.y;
		}
		decision_var = -deltaY;
		tmp.x = A.x;
		tmp.y = A.y;
		while (tmp.y <= B.y)
		{
			my_mlx_pixel_put(data, tmp.x, tmp.y, color);
			if (decision_var < 0)
			{
				if (deltaY > deltaX)
					decision_var += 2 * deltaX;
				else
					decision_var -= 2 * deltaX;
			}
			else
			{
				if (B.x > A.x)
					++tmp.x;
				else
					--tmp.x;
				if (deltaY > deltaX)
					decision_var += 2 * (deltaX - deltaY);
				else
					decision_var -= 2 * (deltaX + deltaY);
			}
			++tmp.y;
		}
	}
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
