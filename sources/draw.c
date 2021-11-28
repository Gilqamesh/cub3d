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
			if (minimapX >= 0 && minimapX < MINIMAP_WIDTH && minimapY >= 0 && minimapY < MINIMAP_HEIGHT)
				my_mlx_pixel_put(&mystruct->real_time_minimap_img, x, y,
					get_color(&mystruct->minimap_img, minimapX, minimapY));
			else
				my_mlx_pixel_put(&mystruct->real_time_minimap_img, x, y, BLANK);
		}
	}
	my_mlx_pixel_put(&mystruct->real_time_minimap_img, REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0, RED);
	my_mlx_pixel_put(&mystruct->real_time_minimap_img, REALTIME_MINIMAP_W / 2.0 + 1, REALTIME_MINIMAP_H / 2.0, RED);
	my_mlx_pixel_put(&mystruct->real_time_minimap_img, REALTIME_MINIMAP_W / 2.0 - 1, REALTIME_MINIMAP_H / 2.0, RED);
	my_mlx_pixel_put(&mystruct->real_time_minimap_img, REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0 + 1, RED);
	my_mlx_pixel_put(&mystruct->real_time_minimap_img, REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0 - 1, RED);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->real_time_minimap_img.img, 0, 0);
}
