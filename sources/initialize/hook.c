#include "main.h"

static void	zoom_forward(t_cub3D *mystruct)
{
	if (euclidean_distance(mystruct->dirX, mystruct->dirY)
		< ft_minofint(SCREEN_W / 40 * MINIMAP_N_OF_CELL_X / 2
			/ MINIMAP_N_OF_CELL_X - 1, SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y / 2
			/ MINIMAP_N_OF_CELL_Y) - 1)
	{
		mystruct->dirX *= 1 + ZOOM_FACTOR / 100.0;
		mystruct->dirY *= 1 + ZOOM_FACTOR / 100.0;
	}
}

static void	zoom_backward(t_cub3D *mystruct)
{
	if (euclidean_distance(mystruct->dirX, mystruct->dirY) > 0.2)
	{
		mystruct->dirX *= 1 - ZOOM_FACTOR / 100.0;
		mystruct->dirY *= 1 - ZOOM_FACTOR / 100.0;
	}
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
		zoom_forward(mystruct);
	else if (button == MOUSE_ZOOM_BACKWARD)
		zoom_backward(mystruct);
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

int	destroy_window(void *param)
{
	(void)param;
	return (exit_program(STDOUT_FILENO, "Clicked on window exit\n"));
}
