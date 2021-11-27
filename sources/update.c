#include "headers.h"

void	update_position(t_cub3D *mystruct, int key)
{
	if (key == KEY_W)
	{
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX + mystruct->dirX * mystruct->moveSpeed)] == '0')
			mystruct->posX += mystruct->dirX * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY + mystruct->dirY * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY += mystruct->dirY * mystruct->moveSpeed;
	}
	else if (key == KEY_S)
	{
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX - mystruct->dirX * mystruct->moveSpeed)] == '0')
			mystruct->posX -= mystruct->dirX * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY - mystruct->dirY * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY -= mystruct->dirY * mystruct->moveSpeed;
	}
	else if (key == KEY_A)
	{	
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX - mystruct->dirY * mystruct->moveSpeed)] == '0')
			mystruct->posX -= mystruct->dirY * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY + mystruct->dirX * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY += mystruct->dirX * mystruct->moveSpeed;
	}
	else if (key == KEY_D)
	{
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX + mystruct->dirY * mystruct->moveSpeed)] == '0')
			mystruct->posX += mystruct->dirY * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY - mystruct->dirX * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY -= mystruct->dirX * mystruct->moveSpeed;
	}
	else if (key == KEY_RIGHT)
	{
		double oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(-mystruct->rotSpeed) - mystruct->dirY * sin(-mystruct->rotSpeed);
		mystruct->dirY = oldDirX * sin(-mystruct->rotSpeed) + mystruct->dirY * cos(-mystruct->rotSpeed);
		double oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(-mystruct->rotSpeed) - mystruct->planeY * sin(-mystruct->rotSpeed);
		mystruct->planeY = oldPlaneX * sin(-mystruct->rotSpeed) + mystruct->planeY * cos(-mystruct->rotSpeed);
	}
	else if (key == KEY_LEFT)
	{
		double oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(mystruct->rotSpeed) - mystruct->dirY * sin(mystruct->rotSpeed);
		mystruct->dirY = oldDirX * sin(mystruct->rotSpeed) + mystruct->dirY * cos(mystruct->rotSpeed);
		double oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(mystruct->rotSpeed) - mystruct->planeY * sin(mystruct->rotSpeed);
		mystruct->planeY = oldPlaneX * sin(mystruct->rotSpeed) + mystruct->planeY * cos(mystruct->rotSpeed);
	}
}
