#include "main.h"

static bool	can_we_move_to(char c)
{
	if (c != WALL_CHAR && c != DOOR_CLOSED_C)
		return (true);
	return (false);
}

void	handle_forward_backward(int key, t_cub3D *mystruct, double x,
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

void	handle_left_right_strafe(int key, t_cub3D *mystruct, double x,
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
