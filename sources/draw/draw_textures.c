#include "main.h"

void	draw_crosshair(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->crosshair_img.img,
		SCREEN_W / 2 - CROSSHAIR_SIZE / 2, SCREEN_H / 2 - CROSSHAIR_SIZE / 2);
}

void	draw_pause_screen(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->canvas.img, 0, 0);
	draw_minimap(mystruct);
	draw_crosshair(mystruct);
	draw_brush(mystruct);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->pause_img.img, 0, 0);
}

void	draw_minimap(t_cub3D *mystruct)
{
	int		x;
	int		y;
	int		minimapX;
	int		minimapY;

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
			{
				my_mlx_pixel_put(&mystruct->real_time_minimap_img, x, REALTIME_MINIMAP_H -  y - 1,
					get_color(&mystruct->minimap_img, minimapX, minimapY));
			}
			else
			{
				my_mlx_pixel_put(&mystruct->real_time_minimap_img, x, REALTIME_MINIMAP_H -  y - 1, BLANK);
			}
		}
	}
	draw_filled_circle(&mystruct->real_time_minimap_img, (t_point){REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0},
		4, GREEN);
	draw_line(&mystruct->real_time_minimap_img, (t_point){REALTIME_MINIMAP_W / 2.0, REALTIME_MINIMAP_H / 2.0},
		(t_point){mystruct->dirX * 10 + REALTIME_MINIMAP_W / 2.0, -mystruct->dirY * 10 + REALTIME_MINIMAP_H / 2.0}, RED);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->real_time_minimap_img.img, 0, 0);
}

void	draw_brush(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->brush_img.img, SCREEN_W / 2,
		SCREEN_H / 2);
}
