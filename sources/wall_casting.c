#include "headers.h"

void	wall_casting(t_cub3D *mystruct)
{
	t_wall_cast_params	p;

	for (int x = 0; x < SCREEN_W; ++x)
    {
		initialize_ray(mystruct, x, &p);
		perform_dda(mystruct, &p);
		calculate_distance(&p);
		draw_wall(mystruct, x, &p);
	}
}

// Jump to next map square, either in x-direction, or in y-direction
// Each iteration check if the ray has hit a wall
void	perform_dda(t_cub3D *mystruct, t_wall_cast_params *p)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (p->sideDistX < p->sideDistY)
		{
			p->sideDistX += p->deltaDistX;
			p->mapX += p->stepX;
			p->side = 0;
		}
		else
		{
			p->sideDistY += p->deltaDistY;
			p->mapY += p->stepY;
			p->side = 1;
		}
		if (mystruct->map[p->mapY][p->mapX] > '0')
			hit = 1;
	}
}

// initialize x-coordinate in camera space (cameraX)
// calculate ray position and direction (rayDir vector)
// initialize which box of the map we're in (mapX, mapY)
// initialize length of ray from one x or y-side to next x or y-side (deltaDist vector)
// calculate step and initialize sideDist
void	initialize_ray(t_cub3D *mystruct, int current_column, t_wall_cast_params *p)
{
	p->cameraX = 2 * current_column / (double)SCREEN_W - 1;
	p->rayDirX = mystruct->dirX + mystruct->planeX * p->cameraX;
	p->rayDirY = mystruct->dirY + mystruct->planeY * p->cameraX;
	p->mapX = (int)mystruct->posX;
	p->mapY = (int)mystruct->posY;
	if (p->rayDirX == 0)
		p->deltaDistX = INFINITY;
	else
		p->deltaDistX = fabs(1 / p->rayDirX);
	if (p->rayDirY == 0)
		p->deltaDistY = INFINITY;
	else
		p->deltaDistY = fabs(1 / p->rayDirY);
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

// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe
void	calculate_distance(t_wall_cast_params *p)
{
	if (p->side == 0)
		p->perpWallDist = (p->sideDistX - p->deltaDistX);
	else
		p->perpWallDist = (p->sideDistY - p->deltaDistY);
	p->lineHeight = (int)(SCREEN_H / p->perpWallDist);
	p->drawStart = -p->lineHeight / 2 + SCREEN_H / 2;
	if (p->drawStart < 0)
		p->drawStart = 0;
	p->drawEnd = p->lineHeight / 2 + SCREEN_H / 2;
	if (p->drawEnd >= SCREEN_H)
		p->drawEnd = SCREEN_H - 1;
}

// Calculate where the wall was hit (wallX)
// X coordinate of the texture (texX)
// How much to increase the texture coordinate per screen pixel (step)
// Starting texture coordinate (texPos)
// Each iteration:
// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow (texY)
// Get color from the texture and draw the pixel
// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// if (p->side == 1)
// 	color = (color >> 1) & 8355711;
void	draw_wall(t_cub3D *mystruct, int current_column, t_wall_cast_params *p)
{
	t_draw_wall_params	w;

	if (p->side == 0)
		w.wallX = mystruct->posY + p->perpWallDist * p->rayDirY;
	else
		w.wallX = mystruct->posX + p->perpWallDist * p->rayDirX;
	w.wallX -= floor(w.wallX);
	w.texX = (int)(w.wallX * (double)TEXTURE_W);
	if (p->side == 0 && p->rayDirX > 0)
		w.texX = TEXTURE_W - w.texX - 1;
	if (p->side == 1 && p->rayDirY < 0)
		w.texX = TEXTURE_W - w.texX - 1;
	w.step = 1.0 * TEXTURE_H / p->lineHeight;
	w.texPos = (p->drawStart - SCREEN_H / 2 + p->lineHeight / 2) * w.step;
	verLine(mystruct, current_column, 0, SCREEN_H - 1, BLACK);
	for (int y = p->drawStart; y < p->drawEnd; ++y)
	{
		w.texY = (int)w.texPos & (TEXTURE_H - 1);
		w.texPos += w.step;
		w.color = get_color(&mystruct->textures[mystruct->map[p->mapY][p->mapX] - '0' - 1], w.texX, w.texY);
		if (p->side == 1)
			w.color = (w.color >> 1) & 8355711;
		my_mlx_pixel_put(&mystruct->img, current_column, y, w.color);
	}
}