#include "main.h"

static int	init_sprites_helper(t_cub3D *mystruct)
{
	int	x;
	int	y;
	int	n_of_treasures;

	n_of_treasures = 0;
	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
			if (mystruct->map[y][x] == TREASURE_CHAR)
				++n_of_treasures;
	}
	mystruct->n_of_lamps_on_map = mystruct->n_of_spaces_on_map * SPRITE_DENSITY_FACTOR;
	mystruct->n_of_sprites_on_map = mystruct->n_of_lamps_on_map + n_of_treasures;
	mystruct->sprites = ft_calloc(mystruct->n_of_sprites_on_map, sizeof(*mystruct->sprites));
	return (n_of_treasures);
}

static int	init_sprites_helper3(t_cub3D *mystruct, int *n_of_treasures,
t_point_p sindex_nspaces, t_point iter)
{
	if (mystruct->map[iter.y][iter.x] == TREASURE_CHAR)
	{
		--*n_of_treasures;
		mystruct->sprites[mystruct->n_of_lamps_on_map + *n_of_treasures].posX
			= iter.x + 0.5;
		mystruct->sprites[mystruct->n_of_lamps_on_map + *n_of_treasures].posY
			= iter.y + 0.5;
		mystruct->map[iter.y][iter.x] = SPACE_CHAR;
	}
	else if (mystruct->map[iter.y][iter.x] == SPACE_CHAR)
	{
		if (++*sindex_nspaces.y % (int)(1 / SPRITE_DENSITY_FACTOR) == 0)
		{
			mystruct->sprites[*sindex_nspaces.x].posX = iter.x + 0.5;
			mystruct->sprites[*sindex_nspaces.x].posY = iter.y + 0.5;
			if (++*sindex_nspaces.x == mystruct->n_of_lamps_on_map)
				return (1);
		}
	}
	return (0);
}

static void	init_sprites_helper2(t_cub3D *mystruct, int *n_of_treasures)
{
	int	sprite_index;
	int	cur_n_of_spaces;
	int	x;
	int	y;

	sprite_index = 0;
	cur_n_of_spaces = 0;
	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
			if (init_sprites_helper3(mystruct, n_of_treasures,
				(t_point_p){&sprite_index, &cur_n_of_spaces}, (t_point){x, y}))
					return ;
	}
}

void	init_sprites(t_cub3D *mystruct)
{
	int	n_of_treasures;
	int	i;

	n_of_treasures = init_sprites_helper(mystruct);
	i = -1;
	while (++i < mystruct->n_of_sprites_on_map)
	{
		if (i < mystruct->n_of_lamps_on_map)
		{
			mystruct->sprites[i].img = &mystruct->textures[TEXTURE_LAMP];
			mystruct->sprites[i].name = SPRITE_LAMP;
		}
		else
		{
			mystruct->sprites[i].img = mystruct->goggles;
			mystruct->sprites[i].name = SPRITE_GOGGLE;
		}
	}
	init_sprites_helper2(mystruct, &n_of_treasures);
}
