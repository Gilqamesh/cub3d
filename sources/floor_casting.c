#include "headers.h"

void	floor_casting(t_cub3D *mystruct)
{
	(void)mystruct;
	// for (int y = 0; y < SCREEN_H; ++y)
	// {
	// 	// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
	// 	float	rayDirX0 = mystruct->dirX - mystruct->planeX;
	// 	float	rayDirY0 = mystruct->dirY - mystruct->planeY;
	// 	float	rayDirX1 = mystruct->dirX + mystruct->planeX;
	// 	float	rayDirY1 = mystruct->dirY + mystruct->planeY;

	// 	// Current y position compared to the center of the screen (the horizon)
	// 	int p = y - SCREEN_H / 2;

	// 	// Vertical position of the camera
	// 	float	posZ = 0.5 * SCREEN_H;

	// 	// Horizontal distance from the camera to the floor for the current row.
	// 	// 0.5 is the z position exactly in the middle between floor and ceiling.
	// 	float	rowDistance = posZ / p;

	// 	// Calculate the real world step vector we have to add for each x (parallel to camera plane)
	// 	// adding step by step avoids multiplications with a weight in the innter loop
	// 	float	floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_W;
	// 	float	floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_W;

	// 	// Real world coordinates of the leftmost column. This will be updated as we step to the right.
	// 	float	floorX = mystruct->posX + rowDistance * rayDirX0;
	// 	float	floorY = mystruct->posY + rowDistance * rayDirY0;

	// 	for (int x = 0; x < SCREEN_W; ++x)
	// 	{
	// 		// The cell coord is simply got from the integer parts of floorX and floorY
	// 		int	cellX = (int)floorX;
	// 		int	cellY = (int)floorY;

	// 		// Get the texture coordinate from the fractional part
	// 		int	tx = (int)(TEXTURE_W * (floorX - cellX)) & (TEXTURE_W - 1);
	// 		int	ty = (int)(TEXTURE_H * (floorY - cellY)) & (TEXTURE_H - 1);

	// 		floorX += floorStepX;
	// 		floorY += floorStepY;

	// 		// Choose texture and draw the pixel
	// 		int	floorTexture = WHITE_BRICK;
	// 		int	ceilingTexture = WOOD;

	// 		unsigned int	color;
	// 		// floor
	// 		color = get_color(&mystruct->textures[floorTexture], tx, ty);
	// 		color = (color >> 1) & 8355711;
	// 		my_mlx_pixel_put(&mystruct->img, x, y, color);

	// 		// Ceiling (symmetrical, at screenHeight - y - 1 instead of y)
	// 		color = get_color(&mystruct->textures[ceilingTexture], tx, ty);
	// 		color = (color >> 1) & 8355711;
	// 		my_mlx_pixel_put(&mystruct->img, x, SCREEN_H - y - 1, color);
	// 	}
	// }
}
