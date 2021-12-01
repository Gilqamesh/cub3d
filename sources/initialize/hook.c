#include "main.h"

int	render_frame(void *param)
{
	// static int		var;
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
		mlx_mouse_hide();
		mlx_mouse_move(mystruct->vars.win, SCREEN_W / 2, SCREEN_H / 2);
		mystruct->prev_timestamp = get_current_timestamp();
	}
	if (mystruct->is_paused == true)
	{
		draw_pause_screen(mystruct);
		return (0);
	}
	if (++mystruct->n_of_renders == 30 / 4)
		mystruct->n_of_renders = 0;
	// if (++var == 100)
	// {	
	// 	var = 0;
	// 	system("leaks cub3D");
	// }
	floor_casting(mystruct);
	wall_casting(mystruct);
	sprite_casting(mystruct);
	update_canvas(mystruct);
	draw_brush(mystruct);
	draw_crosshair(mystruct);
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
	else if (key == KEY_E && mystruct->looking_at_door
		&& mystruct->door_to_interact_with.distance_from_player < 2)
	{
		if (mystruct->door_to_interact_with.opened == true)
		{
			mystruct->door_to_interact_with.opened = false;
			mystruct->map[mystruct->door_to_interact_with.coordinates.y]
				[mystruct->door_to_interact_with.coordinates.x] = DOOR_CLOSED_CHAR;
		}
		else
		{
			mystruct->door_to_interact_with.opened = true;
			mystruct->map[mystruct->door_to_interact_with.coordinates.y]
				[mystruct->door_to_interact_with.coordinates.x] = DOOR_OPEN_CHAR;
		}
	}
	return (0);
}

int	exit_program(void *param)
{
	t_cub3D	*mystruct;

	mystruct = (t_cub3D *)param;
	// free resources associated with mystruct
	exit(EXIT_SUCCESS);
}

int	mouse_press(int button, int x, int y, void *param)
{
	static bool		first_time = true;
	static t_cub3D	*mystruct = NULL;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
	}
	(void)x;
	(void)y;
	if (button == MOUSE_ZOOM_FORWARD)
	{
		if (sqrt(mystruct->dirX * mystruct->dirX + mystruct->dirY * mystruct->dirY)
			< ft_minofint(REALTIME_MINIMAP_W / 2 / MINIMAP_N_OF_CELL_X - 1,
			REALTIME_MINIMAP_H / 2 / MINIMAP_N_OF_CELL_Y) - 1)
		{
			mystruct->dirX *= 1 + ZOOM_FACTOR / 100.0;
			mystruct->dirY *= 1 + ZOOM_FACTOR / 100.0;
		}
	}
	else if (button == MOUSE_ZOOM_BACKWARD)
	{
		if (sqrt(mystruct->dirX * mystruct->dirX + mystruct->dirY * mystruct->dirY) > 0.2)
		{
			mystruct->dirX *= 1 - ZOOM_FACTOR / 100.0;
			mystruct->dirY *= 1 - ZOOM_FACTOR / 100.0;
		}
	}
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
