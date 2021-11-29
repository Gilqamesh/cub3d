#include "headers.h"

int	render_frame(void *param)
{
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
	}
	if (mystruct->is_paused == true)
	{
		draw_pause_screen(mystruct);
		return (0);
	}
	floor_casting(mystruct);
	wall_casting(mystruct);
	draw_crosshair(mystruct);
	update_canvas(mystruct);
	draw_minimap(mystruct);
	update_position(mystruct);
	update_mouse(mystruct);
	print_debug(mystruct);
	mlx_do_sync(mystruct->vars.mlx);
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
	else if (key == KEY_P)
	{
		if (mystruct->is_paused == false)
		{
			mystruct->is_paused = true;
			mlx_mouse_show();
		}
		else
		{
			mystruct->is_paused = false;
			mlx_mouse_hide();
		}
	}
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
