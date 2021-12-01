#include "main.h"

static bool	can_we_move_to(char c)
{
	if (c != WALL_CHAR && c != DOOR_CLOSED_CHAR)
		return (true);
	return (false);
}

static void	handle_forward_backward(int key, t_cub3D *mystruct, double x,
double y)
{
	if (key == KEY_W)
	{
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)]
			[(int)(mystruct->posX + x)]))
			mystruct->posX += x;
		if (can_we_move_to(mystruct->map [(int)(mystruct->posY + y)]
			[(int)(mystruct->posX)]))
			mystruct->posY += y;
	}
	else if (key == KEY_S)
	{
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)]
			[(int)(mystruct->posX - x)]))
			mystruct->posX -= x;
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY - y)]
			[(int)(mystruct->posX)]))
			mystruct->posY -= y;
	}
}

static void	handle_left_right_strafe(int key, t_cub3D *mystruct, double x,
double y)
{
	if (key == KEY_A)
	{	
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)]
			[(int)(mystruct->posX - y)]))
			mystruct->posX -= y;
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY + x)]
			[(int)(mystruct->posX)]))
			mystruct->posY += x;
	}
	else if (key == KEY_D)
	{
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)]
			[(int)(mystruct->posX + y)]))
			mystruct->posX += y;
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY - x)]
			[(int)(mystruct->posX)]))
			mystruct->posY -= x;
	}
}

static void	handle_left_right(int key, t_cub3D *mystruct)
{
	double	oldDirX;
	double	oldPlaneX;

	if (key == KEY_RIGHT)
	{
		oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(-ROTATE_SPEED) - mystruct->dirY * sin(-ROTATE_SPEED);
		mystruct->dirY = oldDirX * sin(-ROTATE_SPEED) + mystruct->dirY * cos(-ROTATE_SPEED);
		oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(-ROTATE_SPEED) - mystruct->planeY * sin(-ROTATE_SPEED);
		mystruct->planeY = oldPlaneX * sin(-ROTATE_SPEED) + mystruct->planeY * cos(-ROTATE_SPEED);
	}
	else if (key == KEY_LEFT)
	{
		oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(ROTATE_SPEED) - mystruct->dirY * sin(ROTATE_SPEED);
		mystruct->dirY = oldDirX * sin(ROTATE_SPEED) + mystruct->dirY * cos(ROTATE_SPEED);
		oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(ROTATE_SPEED) - mystruct->planeY * sin(ROTATE_SPEED);
		mystruct->planeY = oldPlaneX * sin(ROTATE_SPEED) + mystruct->planeY * cos(ROTATE_SPEED);
	}
}

void	update_position_by_key(t_cub3D *mystruct, int key)
{
	double	x;
	double	y;

	x = mystruct->dirX / euclidean_distance(mystruct->dirX, mystruct->dirY) * MOVE_SPEED;
	y = mystruct->dirY / euclidean_distance(mystruct->dirX, mystruct->dirY) * MOVE_SPEED;
	if (key == KEY_W || key == KEY_S)
		handle_forward_backward(key, mystruct, x, y);
	else if (key == KEY_A || key == KEY_D)
		handle_left_right_strafe(key, mystruct, x, y);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		handle_left_right(key, mystruct);
}
