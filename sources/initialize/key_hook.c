#include "main.h"

static void	movement_keys_press(int key, t_cub3D *mystruct)
{
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
}

int	key_press(int key, void *param)
{
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
	}
	movement_keys_press(key, mystruct);
	if (key == KEY_ESC)
		exit_program(STDOUT_FILENO, "Program terminated by escape press\n");
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

static void	movement_keys_release(int key, t_cub3D *mystruct)
{
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
	movement_keys_release(key, mystruct);
	if (key == KEY_E && mystruct->at_door && mystruct->door_ahaed.dist < 2)
	{
		if (mystruct->door_ahaed.opened == true)
		{
			mystruct->door_ahaed.opened = false;
			mystruct->map[mystruct->door_ahaed.coordinates.y]
			[mystruct->door_ahaed.coordinates.x] = DOOR_CLOSED_C;
		}
		else
		{
			mystruct->door_ahaed.opened = true;
			mystruct->map[mystruct->door_ahaed.coordinates.y]
			[mystruct->door_ahaed.coordinates.x] = DOOR_OPEN_C;
		}
	}
	return (0);
}
