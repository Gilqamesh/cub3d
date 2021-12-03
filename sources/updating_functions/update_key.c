#include "main.h"

static void	key_left(t_cub3D *mystruct,
	double oldDirX, double oldPlaneX)
{
	oldDirX = mystruct->dirX;
	mystruct->dirX = mystruct->dirX * cos(ROTATE_SPEED)
		- mystruct->dirY * sin(ROTATE_SPEED);
	mystruct->dirY = oldDirX * sin(ROTATE_SPEED)
		+ mystruct->dirY * cos(ROTATE_SPEED);
	oldPlaneX = mystruct->planeX;
	mystruct->planeX = mystruct->planeX * cos(ROTATE_SPEED)
		- mystruct->planeY * sin(ROTATE_SPEED);
	mystruct->planeY = oldPlaneX * sin(ROTATE_SPEED)
		+ mystruct->planeY * cos(ROTATE_SPEED);
}

static void	key_right(t_cub3D *mystruct,
	double oldDirX, double oldPlaneX)
{
	oldDirX = mystruct->dirX;
	mystruct->dirX = mystruct->dirX * cos(-ROTATE_SPEED)
		- mystruct->dirY * sin(-ROTATE_SPEED);
	mystruct->dirY = oldDirX * sin(-ROTATE_SPEED)
		+ mystruct->dirY * cos(-ROTATE_SPEED);
	oldPlaneX = mystruct->planeX;
	mystruct->planeX = mystruct->planeX * cos(-ROTATE_SPEED)
		- mystruct->planeY * sin(-ROTATE_SPEED);
	mystruct->planeY = oldPlaneX * sin(-ROTATE_SPEED)
		+ mystruct->planeY * cos(-ROTATE_SPEED);
}

static void	handle_left_right(int key, t_cub3D *mystruct)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = 0.0;
	oldPlaneX = 0.0;
	if (key == KEY_RIGHT)
		key_right(mystruct, oldDirX, oldPlaneX);
	else if (key == KEY_LEFT)
		key_left(mystruct, oldDirX, oldPlaneX);
}

void	update_position_by_key(t_cub3D *mystruct, int key)
{
	double	x;
	double	y;
	double	vSize;

	vSize = euclidean_distance(mystruct->dirX, mystruct->dirY);
	if (vSize == 0)
		exit_program(STDERR_FILENO, "vector length is 0 in file %s in function"\
		" update_position_by_key\n", __FILE__);
	x = mystruct->dirX / vSize * MOVE_SPEED;
	y = mystruct->dirY / vSize * MOVE_SPEED;
	if (key == KEY_W || key == KEY_S)
		handle_forward_backward(key, mystruct, x, y);
	else if (key == KEY_A || key == KEY_D)
		handle_left_right_strafe(key, mystruct, x, y);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		handle_left_right(key, mystruct);
}
