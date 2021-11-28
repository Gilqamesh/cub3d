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
			my_mlx_pixel_put(&mystruct->img, x, SCREEN_H / 2 - i, RED);
}

void	draw_pause_screen(t_cub3D *mystruct)
{
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->img.img, 0, 0);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->pause_img.img, 0, 0);
}
