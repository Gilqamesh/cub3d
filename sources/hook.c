#include "hook.h"
#include "struct.h"
#include "definitions.h"
#include <math.h>

int	render_frame(void *param)
{
	cub3D	*mystruct;

	mystruct = (cub3D *)param;
	for(int x = 0; x < SCREEN_W; x++)
    {
      //calculate ray position and direction
		double	cameraX = 2 * x / (double)SCREEN_W - 1; //x-coordinate in camera space
		double	rayDirX = mystruct->dirX + mystruct->planeX * cameraX;
		double	rayDirY = mystruct->dirY + mystruct->planeY * cameraX;
		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);
		//which box of the map we're in
		int mapX = (int)mystruct->posX;
		int mapY = (int)mystruct->posY;

		//length of ray from current position to next x or y-side
		double	sideDistX;
		double	sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double	deltaDistX = (rayDirX == 0) ? INFINITY : fabs(1 / rayDirX);
		double	deltaDistY = (rayDirY == 0) ? INFINITY : fabs(1 / rayDirY);
		double	perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int	stepX;
		int	stepY;

		int	hit = 0; //was there a wall hit?
		int	side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
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
	}
	// mlx_sync();
}
