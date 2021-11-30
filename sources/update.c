#include "headers.h"

static bool	can_we_move_to(char c)
{
	if (c != WALL_CHAR && c != DOOR_CLOSED_CHAR)
		return (true);
	return (false);
}

void	update_position_by_key(t_cub3D *mystruct, int key)
{
	if (key == KEY_W)
	{
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)][(int)(mystruct->posX + mystruct->dirX * MOVE_SPEED)]))
			mystruct->posX += mystruct->dirX * MOVE_SPEED;
		if (can_we_move_to(mystruct->map [(int)(mystruct->posY + mystruct->dirY * MOVE_SPEED)][(int)(mystruct->posX)]))
			mystruct->posY += mystruct->dirY * MOVE_SPEED;
	}
	else if (key == KEY_S)
	{
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)][(int)(mystruct->posX - mystruct->dirX * MOVE_SPEED)]))
			mystruct->posX -= mystruct->dirX * MOVE_SPEED;
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY - mystruct->dirY * MOVE_SPEED)][(int)(mystruct->posX)]))
			mystruct->posY -= mystruct->dirY * MOVE_SPEED;
	}
	else if (key == KEY_A)
	{	
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)][(int)(mystruct->posX - mystruct->dirY * MOVE_SPEED)]))
			mystruct->posX -= mystruct->dirY * MOVE_SPEED;
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY + mystruct->dirX * MOVE_SPEED)][(int)(mystruct->posX)]))
			mystruct->posY += mystruct->dirX * MOVE_SPEED;
	}
	else if (key == KEY_D)
	{
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY)][(int)(mystruct->posX + mystruct->dirY * MOVE_SPEED)]))
			mystruct->posX += mystruct->dirY * MOVE_SPEED;
		if (can_we_move_to(mystruct->map[(int)(mystruct->posY - mystruct->dirX * MOVE_SPEED)][(int)(mystruct->posX)]))
			mystruct->posY -= mystruct->dirX * MOVE_SPEED;
	}
	else if (key == KEY_RIGHT)
	{
		double oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(-ROTATE_SPEED) - mystruct->dirY * sin(-ROTATE_SPEED);
		mystruct->dirY = oldDirX * sin(-ROTATE_SPEED) + mystruct->dirY * cos(-ROTATE_SPEED);
		double oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(-ROTATE_SPEED) - mystruct->planeY * sin(-ROTATE_SPEED);
		mystruct->planeY = oldPlaneX * sin(-ROTATE_SPEED) + mystruct->planeY * cos(-ROTATE_SPEED);
	}
	else if (key == KEY_LEFT)
	{
		double oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(ROTATE_SPEED) - mystruct->dirY * sin(ROTATE_SPEED);
		mystruct->dirY = oldDirX * sin(ROTATE_SPEED) + mystruct->dirY * cos(ROTATE_SPEED);
		double oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(ROTATE_SPEED) - mystruct->planeY * sin(ROTATE_SPEED);
		mystruct->planeY = oldPlaneX * sin(ROTATE_SPEED) + mystruct->planeY * cos(ROTATE_SPEED);
	}
}

// Under testing :)
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
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->canvas.img, 0, 0);
}
