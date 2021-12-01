#include "main.h"

// initialize x-coordinate in camera space (cameraX)
// calculate ray position and direction (rayDir vector)
// initialize which box of the map we're in (mapX, mapY)
// initialize length of ray from one x or y-side to next x or y-side (deltaDist vector)
// calculate step and initialize sideDist
void	initialize_wall_ray(t_cub3D *mystruct, int current_column,
t_wall_cast_params *p)
{
	p->cameraX = 2.0 * current_column / SCREEN_W - 1;
	p->rayDirX = mystruct->dirX + mystruct->planeX * p->cameraX;
	p->rayDirY = mystruct->dirY + mystruct->planeY * p->cameraX;
	p->mapX = (int)mystruct->posX;
	p->mapY = (int)mystruct->posY;
	if (ft_fabs(p->rayDirX) < EPSILON)
		p->deltaDistX = INFINITY;
	else
		p->deltaDistX = ft_fabs(1.0 / p->rayDirX);
	if (ft_fabs(p->rayDirY) < EPSILON)
		p->deltaDistY = INFINITY;
	else
		p->deltaDistY = ft_fabs(1.0 / p->rayDirY);
	if (p->rayDirX < 0)
	{
		p->stepX = -1;
		p->sideDistX = (mystruct->posX - p->mapX) * p->deltaDistX;
	}
	else
	{
		p->stepX = 1;
		p->sideDistX = (p->mapX + 1.0 - mystruct->posX) * p->deltaDistX;
	}
	if (p->rayDirY < 0)
	{
		p->stepY = -1;
		p->sideDistY = (mystruct->posY - p->mapY) * p->deltaDistY;
	}
	else
	{
		p->stepY = 1;
		p->sideDistY = (p->mapY + 1.0 - mystruct->posY) * p->deltaDistY;
	}
}
