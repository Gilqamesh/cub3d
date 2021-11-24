#include "hook.h"
#include "struct.h"
#include "definitions.h"
#include <math.h>
#include <unistd.h>
#include "utils.h"
#include "mlx.h"
#include "mylib.h"
#include <stdio.h>

int	render_frame(void *param)
{
	t_cub3D	*mystruct;

	mystruct = (t_cub3D *)param;
	for (int x = 0; x < SCREEN_W; ++x)
    {
		// calculate ray position and direction
		double	cameraX = 2 * x / (double)SCREEN_W - 1; // x-coordinate in camera space
		double	rayDirX = mystruct->dirX + mystruct->planeX * cameraX;
		double	rayDirY = mystruct->dirY + mystruct->planeY * cameraX;

		// which box of the map we're in
		int mapX = (int)mystruct->posX;
		int mapY = (int)mystruct->posY;

		// length of ray from current position to next x or y-side
		double	sideDistX;
		double	sideDistY;

		// length of ray from one x or y-side to next x or y-side
		double	deltaDistX = (rayDirX == 0) ? INFINITY : fabs(1 / rayDirX);
		double	deltaDistY = (rayDirY == 0) ? INFINITY : fabs(1 / rayDirY);
		double	perpWallDist;

		// what direction to step in x or y-direction (either +1 or -1)
		int	stepX;
		int	stepY;

		int	hit = 0;	// was there a wall hit?
		int	side;		// was a NS or a EW wall hit?

		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (mystruct->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - mystruct->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (mystruct->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - mystruct->posY) * deltaDistY;
		}

		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
			if (mystruct->map[mapY][mapX] > '0')
				hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
		{
			// Fisheye
			// perpWallDist = sideDistX;
			// Without
			perpWallDist = (sideDistX - deltaDistX);
		}
		else
		{
			// Fisheye
			// perpWallDist = sideDistY;
			// Without
			perpWallDist = (sideDistY - deltaDistY);
		}

		// Calculate height of line to draw on screen
		int lineHeight = (int)(2 * SCREEN_H / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_H / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_H / 2;
		if (drawEnd >= SCREEN_H)
			drawEnd = SCREEN_H - 1;

		// UNTEXTURED
		// // choose wall color
		// enum color	color;
		// switch (mystruct->map[mapY][mapX])
		// {
		// 	case '1':  color = RED;  break;	// red
		// 	case '2':  color = GREEN;  break;	// green
		// 	case '3':  color = BLUE;   break;	// blue
		// 	case '4':  color = WHITE;  break;	// white
		// 	default: color = YELLOW; break;	// yellow
		// }

		// // give x and y sides different brightness
		// if (side == 1)
		// 	color = color / 2;
		// END UNTEXTURED

		// TEXTURED
		// texturing calculations
		int	textNum = mystruct->map[mapY][mapX] - '0' - 1; // 1 subtracted from it so that texture 0 can be used!

		// calculate value of wallX
		double	wallX; // where exactly the wall was hit
		if (side == 0)
			wallX = mystruct->posY + perpWallDist * rayDirX;
		else
			wallX = mystruct->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int	texX = (int)(wallX * (double)TEXTURE_W);
		if (side == 0 && rayDirX > 0)
			texX = TEXTURE_W - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = TEXTURE_W - texX - 1;

		// How much to increase the texture coordinate per screen pixel
		double	step = 1.0 * TEXTURE_H / lineHeight;
		// Starting texture coordinate
		double	texPos = (drawStart - SCREEN_H / 2 + lineHeight / 2) * step;
		verLine(mystruct, x, 0, SCREEN_H - 1, BLACK);
		for (int y = drawStart; y < drawEnd; ++y)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int	texY = (int)texPos & (TEXTURE_H - 1);
			texPos += step;
			// printf("%d %d\n", texX, texY);
			unsigned int	color = get_color(&mystruct->textures[textNum], texX, texY);
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			// if (side == 1)
			// 	color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&mystruct->img, x, y, color);
		}
		// END TEXTURED

		// draw the pixels of the stripe as a vertical line
		// UNTEXTURED
		// verLine(mystruct, x, 0, SCREEN_H - 1, BLACK);
		// verLine(mystruct, x, drawStart, drawEnd, color);
	}
	// timing for input and FPS counter
	double	frameTime = 1 / FPS;
	// printf("%f, %f\n", frameTime, 1.0 / frameTime);

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
