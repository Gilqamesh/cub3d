#include "headers.h"

int	render_frame(void *param)
{
	t_cub3D	*mystruct;

	mystruct = (t_cub3D *)param;
	floor_casting(mystruct);
	wall_casting(mystruct);
	// timing for input and FPS counter
	double	frameTime = 1.0 / FPS;
	// speed modifiers
	mystruct->moveSpeed = frameTime * 5.0;	// the constant value is in squares/second
	mystruct->rotSpeed = frameTime * 3.0;	// the constant value is in radians/second
	// Idk, maybe we need this
	// mlx_do_sync(mystruct->vars.mlx);
	mlx_put_image_to_window(mystruct->vars.mlx, mystruct->vars.win, mystruct->img.img, 0, 0);
	return (0);
}

int	key_hook(int key, void *param)
{
	t_cub3D	*mystruct = (t_cub3D *)param;

	// move forward if no wall in front of you
	if (key == KEY_W)
	{
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX + mystruct->dirX * mystruct->moveSpeed)] == '0')
			mystruct->posX += mystruct->dirX * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY + mystruct->dirY * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY += mystruct->dirY * mystruct->moveSpeed;
	}
	// move backwards if no wall behind you
	if (key == KEY_S)
	{
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX - mystruct->dirX * mystruct->moveSpeed)] == '0')
			mystruct->posX -= mystruct->dirX * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY - mystruct->dirY * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY -= mystruct->dirY * mystruct->moveSpeed;
	}
	// move left if no wall to the left
	if (key == KEY_A)
	{
		
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX - mystruct->dirY * mystruct->moveSpeed)] == '0')
			mystruct->posX -= mystruct->dirY * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY + mystruct->dirX * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY += mystruct->dirX * mystruct->moveSpeed;
	}
	// // move right if no wall to the right
	if (key == KEY_D)
	{
		if (mystruct->map [(int)(mystruct->posY)][(int)(mystruct->posX + mystruct->dirY * mystruct->moveSpeed)] == '0')
			mystruct->posX += mystruct->dirY * mystruct->moveSpeed;
		if (mystruct->map [(int)(mystruct->posY - mystruct->dirX * mystruct->moveSpeed)][(int)(mystruct->posX)] == '0')
			mystruct->posY -= mystruct->dirX * mystruct->moveSpeed;
	}
	// rotate to the right
	if (key == KEY_RIGHT)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(-mystruct->rotSpeed) - mystruct->dirY * sin(-mystruct->rotSpeed);
		mystruct->dirY = oldDirX * sin(-mystruct->rotSpeed) + mystruct->dirY * cos(-mystruct->rotSpeed);
		double oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(-mystruct->rotSpeed) - mystruct->planeY * sin(-mystruct->rotSpeed);
		mystruct->planeY = oldPlaneX * sin(-mystruct->rotSpeed) + mystruct->planeY * cos(-mystruct->rotSpeed);
	}
	// rotate to the left
	if (key == KEY_LEFT)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = mystruct->dirX;
		mystruct->dirX = mystruct->dirX * cos(mystruct->rotSpeed) - mystruct->dirY * sin(mystruct->rotSpeed);
		mystruct->dirY = oldDirX * sin(mystruct->rotSpeed) + mystruct->dirY * cos(mystruct->rotSpeed);
		double oldPlaneX = mystruct->planeX;
		mystruct->planeX = mystruct->planeX * cos(mystruct->rotSpeed) - mystruct->planeY * sin(mystruct->rotSpeed);
		mystruct->planeY = oldPlaneX * sin(mystruct->rotSpeed) + mystruct->planeY * cos(mystruct->rotSpeed);
	}
	// render_frame(mystruct);
	return (0);
}
