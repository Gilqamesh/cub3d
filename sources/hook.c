#include "headers.h"

int	render_frame(void *param)
{
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;
	static int		counter = 0;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
	}
	// floor_casting(mystruct);
	wall_casting(mystruct);
	draw_crosshair(mystruct);
	mlx_do_sync(mystruct->vars.mlx);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->img.img, 0, 0);
	if (++counter == 2)
	{
		counter = 0;
		if (mystruct->is_w_held)
			update_position(mystruct, KEY_W);
		if (mystruct->is_s_held)
			update_position(mystruct, KEY_S);
		if (mystruct->is_a_held)
			update_position(mystruct, KEY_A);
		if (mystruct->is_d_held)
			update_position(mystruct, KEY_D);
		if (mystruct->is_left_held)
			update_position(mystruct, KEY_LEFT);
		if (mystruct->is_right_held)
			update_position(mystruct, KEY_RIGHT);
	}
	update_mouse(mystruct);
	return (0);
}

// double oldDirX = mystruct->dirX;
// mystruct->dirX = mystruct->dirX * cos(-mystruct->rotSpeed) - mystruct->dirY * sin(-mystruct->rotSpeed);
// mystruct->dirY = oldDirX * sin(-mystruct->rotSpeed) + mystruct->dirY * cos(-mystruct->rotSpeed);
// double oldPlaneX = mystruct->planeX;
// mystruct->planeX = mystruct->planeX * cos(-mystruct->rotSpeed) - mystruct->planeY * sin(-mystruct->rotSpeed);
// mystruct->planeY = oldPlaneX * sin(-mystruct->rotSpeed) + mystruct->planeY * cos(-mystruct->rotSpeed);

int	key_press(int key, void *param)
{
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
	}
	if (key == KEY_W)
		mystruct->is_w_held = true;
	else if (key == KEY_S)
		mystruct->is_s_held = true;
	else if (key == KEY_A)
		mystruct->is_a_held = true;
	else if (key == KEY_D)
		mystruct->is_d_held = true;
	else if (key == KEY_RIGHT)
		mystruct->is_right_held = true;
	else if (key == KEY_LEFT)
		mystruct->is_left_held = true;
	else if (key == KEY_ESC)
		exit_program(mystruct);
	return (0);
}

int	key_release(int key, void *param)
{
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
	}
	if (key == KEY_W)
		mystruct->is_w_held = false;
	else if (key == KEY_S)
		mystruct->is_s_held = false;
	else if (key == KEY_A)
		mystruct->is_a_held = false;
	else if (key == KEY_D)
		mystruct->is_d_held = false;
	else if (key == KEY_RIGHT)
		mystruct->is_right_held = false;
	else if (key == KEY_LEFT)
		mystruct->is_left_held = false;
	return (0);
}

int	exit_program(void *param)
{
	t_cub3D	*mystruct;

	mystruct = (t_cub3D *)param;
	// free resources associated with mystruct
	exit(EXIT_SUCCESS);
}
