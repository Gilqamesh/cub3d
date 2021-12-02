#include "main.h"

void	update_mouse(t_cub3D *mystruct)
{
	int	x;
	int	y;
	int	deltaX;

	mlx_mouse_get_pos(mystruct->vars.win, &x, &y);
	deltaX = x - SCREEN_W / 2;
	if (ft_abs_int(deltaX) > MAX_X_DELTA)
	{
		if (deltaX < 0)
			deltaX = -MAX_X_DELTA;
		else
			deltaX = MAX_X_DELTA;
	}
	float	mapDeltaX = 1.5 * sqrt(ft_abs_int(deltaX));
	if (deltaX > 0)
		mapDeltaX *= -1;
	double	oldDirX = mystruct->dirX;
	mystruct->dirX = mystruct->dirX * cos(mapDeltaX / 100.0) - mystruct->dirY * sin(mapDeltaX / 100.0);
	mystruct->dirY = oldDirX * sin(mapDeltaX / 100.0) + mystruct->dirY * cos(mapDeltaX / 100.0);
	double	oldPlaneX = mystruct->planeX;
	mystruct->planeX = mystruct->planeX * cos(mapDeltaX / 100.0) - mystruct->planeY * sin(mapDeltaX / 100.0);
	mystruct->planeY = oldPlaneX * sin(mapDeltaX / 100.0) + mystruct->planeY * cos(mapDeltaX / 100.0);
	mlx_mouse_move(mystruct->vars.win, SCREEN_W / 2, SCREEN_H / 2);
}

void	update_position(t_cub3D *mystruct)
{
	if (mystruct->is_w_held)
		update_position_by_key(mystruct, KEY_W);
	if (mystruct->is_s_held)
		update_position_by_key(mystruct, KEY_S);
	if (mystruct->is_a_held)
		update_position_by_key(mystruct, KEY_A);
	if (mystruct->is_d_held)
		update_position_by_key(mystruct, KEY_D);
	if (mystruct->is_left_held)
		update_position_by_key(mystruct, KEY_LEFT);
	if (mystruct->is_right_held)
		update_position_by_key(mystruct, KEY_RIGHT);
}

void	update_canvas(t_cub3D *mystruct)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
			my_mlx_pixel_put(&mystruct->canvas, x, y,
				mystruct->draw_buffer[y][x]);
	}
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->canvas.img, 0, 0);
}
