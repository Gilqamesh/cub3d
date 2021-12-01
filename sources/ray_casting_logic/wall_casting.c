#include "main.h"

// After wall is drawn, set the ZBuffer for the sprite casting
void	wall_casting(t_cub3D *mystruct)
{
	t_wall_cast_params	p;

	mystruct->looking_at_door = false;
	for (int x = 0; x < SCREEN_W; ++x)
    {
		ft_bzero(&p, sizeof(p));
		initialize_wall_ray(mystruct, x, &p);
		perform_dda(mystruct, x, &p);
		calculate_distance(&p);
		draw_wall(mystruct, x, &p);
		mystruct->ZBuffer[x] = p.perpWallDist;
	}
}

// initialize x-coordinate in camera space (cameraX)
// calculate ray position and direction (rayDir vector)
// initialize which box of the map we're in (mapX, mapY)
// initialize length of ray from one x or y-side to next x or y-side (deltaDist vector)
// calculate step and initialize sideDist
void	initialize_wall_ray(t_cub3D *mystruct, int current_column, t_wall_cast_params *p)
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

// Jump to next map square, either in x-direction, or in y-direction
// Each iteration check if the ray has hit a wall
void	perform_dda(t_cub3D *mystruct, int current_column, t_wall_cast_params *p)
{
	p->hit = '\0';
	while (!p->hit)
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
		if (mystruct->map[p->mapY][p->mapX] == WALL_CHAR
			|| mystruct->map[p->mapY][p->mapX] == DOOR_CLOSED_CHAR)
			p->hit = mystruct->map[p->mapY][p->mapX];
		if (current_column == SCREEN_W / 2 && (mystruct->map[p->mapY][p->mapX] == DOOR_OPEN_CHAR
			|| mystruct->map[p->mapY][p->mapX] == DOOR_CLOSED_CHAR))
		{
			mystruct->looking_at_door = true;
			if (mystruct->map[p->mapY][p->mapX] == DOOR_CLOSED_CHAR)
				mystruct->door_to_interact_with.opened = false;
			else
				mystruct->door_to_interact_with.opened = true;
			if (p->side == 0)
				mystruct->door_to_interact_with.distance_from_player = p->sideDistX - p->deltaDistX;
			else
				mystruct->door_to_interact_with.distance_from_player = p->sideDistY - p->deltaDistY;
			mystruct->door_to_interact_with.coordinates.x = p->mapX;
			mystruct->door_to_interact_with.coordinates.y = p->mapY;
		}
	}
}

// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe
void	calculate_distance(t_wall_cast_params *p)
{
	if (p->side == 0)
		p->perpWallDist = p->sideDistX - p->deltaDistX;
	else
		p->perpWallDist = p->sideDistY - p->deltaDistY;
	p->lineHeight = (int)(SCREEN_H / p->perpWallDist);
	p->drawStart = -p->lineHeight / 2.0 + SCREEN_H / 2.0;
	if (p->drawStart < 0)
		p->drawStart = 0;
	p->drawEnd = p->lineHeight / 2.0 + SCREEN_H / 2.0;
	if (p->drawEnd >= SCREEN_H)
		p->drawEnd = SCREEN_H - 1;
}

static int	get_wall_texture(t_wall_cast_params *p)
{
	if (p->stepX == 1)
	{
		if (p->stepY == 1) // NE
		{
			if (p->side == 0) // vertical wall hit
				return (TEXT_E_WALL);
			else // horizontal hit
				return (TEXT_N_WALL);
		}
		else // SE
		{
			if (p->side == 0)
				return (TEXT_E_WALL);
			else
				return (TEXT_S_WALL);
		}
	}
	else
	{
		if (p->stepY == 1) // NW
		{
			if (p->side == 0)
				return (TEXT_W_WALL);
			else
				return (TEXT_N_WALL);
		}
		else // SW
		{
			if (p->side == 0)
				return (TEXT_W_WALL);
			else
				return (TEXT_S_WALL);
		}
	}
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
	int					texture_index;

	if (p->side == 0)
		w.wallX = mystruct->posY + p->perpWallDist * p->rayDirY;
	else
		w.wallX = mystruct->posX + p->perpWallDist * p->rayDirX;
	w.wallX -= floor(w.wallX);
	w.texX = (int)(w.wallX * TEXT_W);
	if (p->side == 0 && p->rayDirX > 0)
		w.texX = TEXT_W - w.texX - 1;
	else if (p->side == 1 && p->rayDirY < 0)
		w.texX = TEXT_W - w.texX - 1;
	w.step = (double)TEXT_H / p->lineHeight;
	w.texPos = (p->drawStart + (p->lineHeight - SCREEN_H) / 2.0) * w.step;
	if (p->hit == WALL_CHAR)
		texture_index = get_wall_texture(p);
	else
		texture_index = TEXTURE_DOOR;
	for (int y = p->drawStart; y < p->drawEnd; ++y)
	{
		w.texY = (int)w.texPos & (TEXT_H - 1);
		w.texPos += w.step;
		w.color = get_color(&mystruct->textures[texture_index], w.texX, w.texY);
		if (p->side == 1)
			w.color = (w.color >> 1) & 8355711;
		my_mlx_pixel_put(&mystruct->canvas, current_column, y, w.color);
	}
}
