#include "headers.h"

void	draw_crosshair(t_cub3D *mystruct)
{
	int	i;

	i = -2;
	while (++i < 2)
		verLine(mystruct, SCREEN_W / 2 - i, SCREEN_H / 2 - 10, SCREEN_H / 2 + 10, RED);
	i = -2;
	while (++i < 2)
		for (int x = SCREEN_W / 2 - 10; x < SCREEN_W / 2 + 10; ++x)
			my_mlx_pixel_put(&mystruct->canvas, x, SCREEN_H / 2 - i, RED);
}

void	draw_pause_screen(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->canvas.img, 0, 0);
	draw_minimap(mystruct);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->pause_img.img, 0, 0);
}

void	draw_minimap(t_cub3D *mystruct)
{
	int		x;
	int		y;
	double	minimapX;
	double	minimapY;

	y = -1;
	while (++y < REALTIME_MINIMAP_H)
	{
		x = -1;
		while (++x < REALTIME_MINIMAP_W)
		{
			minimapX = mystruct->posX * MINIMAP_CELL_X - REALTIME_MINIMAP_W / 2.0 + x;
			minimapY = mystruct->posY * MINIMAP_CELL_Y - REALTIME_MINIMAP_H / 2.0 + y;
			if (minimapX >= 0 && minimapX < MINIMAP_CELL_X * mystruct->map_width
				&& minimapY >= 0 && minimapY < MINIMAP_CELL_Y * mystruct->map_height)
				my_mlx_pixel_put(&mystruct->real_time_minimap_img, x, REALTIME_MINIMAP_H -  y - 1,
					get_color(&mystruct->minimap_img, minimapX, minimapY));
			else
				my_mlx_pixel_put(&mystruct->real_time_minimap_img, x, REALTIME_MINIMAP_H -  y - 1, BLANK);
		}
	}
	draw_filled_circle(&mystruct->real_time_minimap_img, (t_point){REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0},
		4, GREEN);
	draw_line(&mystruct->real_time_minimap_img, (t_point){REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0},
		(t_point){mystruct->dirX * 10 + REALTIME_MINIMAP_W / 2.0, -mystruct->dirY * 10 + REALTIME_MINIMAP_H / 2.0}, RED);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->real_time_minimap_img.img, 0, 0);
}

// Draws a vertical line
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, int color)
{
	for (int i = y_start; i <= y_end; ++i)
		my_mlx_pixel_put(&mystruct->canvas, x, i, color);
}

// Helper for draw_line
static void	low_slope_logic(t_data *data, t_line_segment s, t_point delta)
{
	t_point	tmp;
	int		decision_var;

	if (s.B.x < s.A.x)
	{
		tmp.x = s.B.x;
		tmp.y = s.B.y;
		s.B.x = s.A.x;
		s.B.y = s.A.y;
		s.A.x = tmp.x;
		s.A.y = tmp.y;
	}
	if (delta.y >= 0)
		decision_var = 2 * delta.y - delta.x;
	else
		decision_var = -delta.x;
	tmp.x = s.A.x;
	tmp.y = s.A.y;
	while (tmp.x <= s.B.x)
	{
		my_mlx_pixel_put(data, tmp.x, tmp.y, s.color);
		if (decision_var < 0)
		{
			if (delta.y >= 0)
				decision_var += 2 * delta.y;
			else
				decision_var -= 2 * delta.y;
		}
		else
		{
			if (s.B.y > s.A.y)
				++tmp.y;
			else
				--tmp.y;
			if (delta.y >= 0)
				decision_var += 2 * (delta.y - delta.x);
			else
				decision_var -= 2 * (delta.y + delta.x);
		}
		++tmp.x;
	}
}

// Helper for draw_line
static void	high_slope_logic(t_data *data, t_line_segment s, t_point delta)
{
	t_point	tmp;
	int		decision_var;

	if (s.B.y < s.A.y)
	{
		tmp.x = s.B.x;
		tmp.y = s.B.y;
		s.B.x = s.A.x;
		s.B.y = s.A.y;
		s.A.x = tmp.x;
		s.A.y = tmp.y;
	}
	decision_var = -delta.y;
	tmp.x = s.A.x;
	tmp.y = s.A.y;
	while (tmp.y <= s.B.y)
	{
		my_mlx_pixel_put(data, tmp.x, tmp.y, s.color);
		if (decision_var < 0)
		{
			if (delta.y > delta.x)
				decision_var += 2 * delta.x;
			else
				decision_var -= 2 * delta.x;
		}
		else
		{
			if (s.B.x > s.A.x)
				++tmp.x;
			else
				--tmp.x;
			if (delta.y > delta.x)
				decision_var += 2 * (delta.x - delta.y);
			else
				decision_var -= 2 * (delta.x + delta.y);
		}
		++tmp.y;
	}
}

// Based on Bresenham's algorithm
void	draw_line(t_data *data, t_point A, t_point B, int color)
{
	t_point	delta;

	delta.x = ft_abs_int(B.x - A.x);
	delta.y = ft_abs_int(B.y - A.y);
	if (delta.y <= delta.x && delta.y >= -delta.x)
		low_slope_logic(data, (t_line_segment){A, B, color}, delta);
	else
		high_slope_logic(data, (t_line_segment){A, B, color}, delta);
}

void	draw_filled_circle(t_data *data, t_point center, int radius, int color)
{
	t_point	iter;

	iter.y = center.y - radius;
	while (iter.y <= center.y + radius)
	{
		iter.x = center.x - radius;
		while (iter.x <= center.x + radius)
		{
			if ((iter.x - center.x) * (iter.x - center.x) + (iter.y - center.y) * (iter.y - center.y)
				<= radius * radius)
				my_mlx_pixel_put(data, iter.x, iter.y, color);
			++iter.x;
		}
		++iter.y;
	}
}
