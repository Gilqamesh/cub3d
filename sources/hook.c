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
	// FLOOR CASTING
	for (int y = 0; y < SCREEN_H; ++y)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float	rayDirX0 = mystruct->dirX - mystruct->planeX;
		float	rayDirY0 = mystruct->dirY - mystruct->planeY;
		float	rayDirX1 = mystruct->dirX + mystruct->planeX;
		float	rayDirY1 = mystruct->dirY + mystruct->planeY;

		// Current y position compared to the center of the screen (the horizon)
		int p = y - SCREEN_H / 2;

		// Vertical position of the camera
		float	posZ = 0.5 * SCREEN_H;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float	rowDistance = posZ / p;

		// Calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the innter loop
		float	floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_W;
		float	floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_W;

		// Real world coordinates of the leftmost column. This will be updated as we step to the right.
		float	floorX = mystruct->posX + rowDistance * rayDirX0;
		float	floorY = mystruct->posY + rowDistance * rayDirY0;

		for (int x = 0; x < SCREEN_W; ++x)
		{
			// The cell coord is simply got from the integer parts of floorX and floorY
			int	cellX = (int)floorX;
			int	cellY = (int)floorY;

			// Get the texture coordinate from the fractional part
			int	tx = (int)(TEXTURE_W * (floorX - cellX)) & (TEXTURE_W - 1);
			int	ty = (int)(TEXTURE_H * (floorY - cellY)) & (TEXTURE_H - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			// Choose texture and draw the pixel
			int	floorTexture = WHITE_BRICK;
			int	ceilingTexture = WOOD;

			unsigned int	color;
			// floor
			color = get_color(&mystruct->textures[floorTexture], tx, ty);
			color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&mystruct->img, x, y, color);

			// Ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			color = get_color(&mystruct->textures[ceilingTexture], tx, ty);
			color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&mystruct->img, x, SCREEN_H - y - 1, color);
		}
	}

	// WALL CASTING
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
		int lineHeight = (int)(SCREEN_H / perpWallDist);

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
			wallX = mystruct->posY + perpWallDist * rayDirY;
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
		// verLine(mystruct, x, 0, SCREEN_H - 1, BLACK);
		for (int y = drawStart; y < drawEnd; ++y)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int	texY = (int)texPos & (TEXTURE_H - 1);
			texPos += step;
			unsigned int	color = get_color(&mystruct->textures[textNum], texX, texY);
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&mystruct->img, x, y, color);
		}
		// END TEXTURED

		// UNTEXTURED
		// draw the pixels of the stripe as a vertical line
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
