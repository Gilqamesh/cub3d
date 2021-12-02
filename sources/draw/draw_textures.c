#include "main.h"

void	draw_crosshair(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->crosshair_img.img, SCREEN_W / 2 - CROSSHAIR_SIZE / 2,
		SCREEN_H / 2 - CROSSHAIR_SIZE / 2);
}

void	draw_pause_screen(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->canvas.img, 0, 0);
	draw_minimap(mystruct);
	draw_crosshair(mystruct);
	draw_brush(mystruct);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->pause_img.img, 0, 0);
}

static void	map_minimap_to_realtime_minimap(t_cub3D *mystruct, int x, int y)
{
	int	minimapX;
	int	minimapY;

	minimapX = mystruct->posX * SCREEN_W / 40
		- SCREEN_W / 40 * MINIMAP_N_OF_CELL_X / 2.0 + x;
	minimapY = mystruct->posY * SCREEN_H / 40 - SCREEN_H / 40
		* MINIMAP_N_OF_CELL_Y / 2.0 + y;
	if (minimapX >= 0 && minimapX < SCREEN_W / 40 * mystruct->map_width
		&& minimapY >= 0 && minimapY < SCREEN_H / 40 * mystruct->map_height)
		my_mlx_pixel_put(&mystruct->real_time_minimap_img, x,
			SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y - y - 1,
			get_color(&mystruct->minimap_img, minimapX, minimapY));
	else
		my_mlx_pixel_put(&mystruct->real_time_minimap_img, x,
			SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y - y - 1, BLANK);
}

void	draw_minimap(t_cub3D *mystruct)
{
	int		x;
	int		y;

	y = -1;
	while (++y < SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y)
	{
		x = -1;
		while (++x < SCREEN_W / 40 * MINIMAP_N_OF_CELL_X)
			map_minimap_to_realtime_minimap(mystruct, x, y);
	}
	draw_filled_circle(&mystruct->real_time_minimap_img,
		(t_point){SCREEN_W / 40 * MINIMAP_N_OF_CELL_X / 2.0,
		SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y / 2.0}, 4, GREEN);
	draw_line(&mystruct->real_time_minimap_img,
		(t_point){SCREEN_W / 40 * MINIMAP_N_OF_CELL_X / 2.0,
		SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y / 2.0},
		(t_point){mystruct->dirX * 10 + SCREEN_W / 40 * MINIMAP_N_OF_CELL_X
		/ 2.0, -mystruct->dirY * 10 + SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y
		/ 2.0}, RED);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->real_time_minimap_img.img, 0, 0);
}

void	draw_brush(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win,
		mystruct->brush_img.img, 2 * SCREEN_W / 3, 2 * SCREEN_H / 3);
}
