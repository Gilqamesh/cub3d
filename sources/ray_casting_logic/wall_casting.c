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

static void	check_if_ray_hit(t_cub3D *mystruct, int current_column,
t_wall_cast_params *p)
{
	if (mystruct->map[p->mapY][p->mapX] == WALL_CHAR
		|| mystruct->map[p->mapY][p->mapX] == DOOR_CLOSED_CHAR)
		p->hit = mystruct->map[p->mapY][p->mapX];
	if (current_column == SCREEN_W / 2 && (mystruct->map[p->mapY][p->mapX]
		== DOOR_OPEN_CHAR || mystruct->map[p->mapY][p->mapX]
		== DOOR_CLOSED_CHAR))
	{
		mystruct->looking_at_door = true;
		if (mystruct->map[p->mapY][p->mapX] == DOOR_CLOSED_CHAR)
			mystruct->door_to_interact_with.opened = false;
		else
			mystruct->door_to_interact_with.opened = true;
		if (p->side == HORIZONTAL_SIDE)
			mystruct->door_to_interact_with.distance_from_player = p->sideDistX
				- p->deltaDistX;
		else
			mystruct->door_to_interact_with.distance_from_player = p->sideDistY
				- p->deltaDistY;
		mystruct->door_to_interact_with.coordinates.x = p->mapX;
		mystruct->door_to_interact_with.coordinates.y = p->mapY;
	}
}

// Jump to next map square, either in x-direction, or in y-direction
// Each iteration check if the ray has hit a wall
void	perform_dda(t_cub3D *mystruct, int current_column,
t_wall_cast_params *p)
{
	p->hit = '\0';
	while (!p->hit)
	{
		if (p->sideDistX < p->sideDistY)
		{
			p->sideDistX += p->deltaDistX;
			p->mapX += p->stepX;
			p->side = HORIZONTAL_SIDE;
		}
		else
		{
			p->sideDistY += p->deltaDistY;
			p->mapY += p->stepY;
			p->side = VERTICAL_SIDE;
		}
		check_if_ray_hit(mystruct, current_column, p);
	}
}

// Calculate distance projected on camera direction
//		(Euclidean distance would give fisheye effect!)
// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe
void	calculate_distance(t_wall_cast_params *p)
{
	if (p->side == HORIZONTAL_SIDE)
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
