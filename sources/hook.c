#include "hook.h"
#include "struct.h"
#include "definitions.h"

int	render_frame(void *param)
{
	cub3D	*mystruct;

	mystruct = (cub3D *)param;
	for(int x = 0; x < SCREEN_W; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)SCREEN_W - 1; //x-coordinate in camera space
      double rayDirX = mystruct->dirX + mystruct->planeX * cameraX;
      double rayDirY = mystruct->dirY + mystruct->planeY * cameraX;
	}
}
