#include "main.h"

void	init_struct(t_cub3D *mystruct)
{
	init_parameters(mystruct);
	mystruct->vars.mlx = mlx_init();
	mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, TITLE);
	init_images(mystruct);
}

void	init_hooks(t_cub3D *mystruct)
{
	mlx_do_key_autorepeatoff(mystruct->vars.mlx);
	mlx_hook(mystruct->vars.win, 2, 1, key_press, mystruct);
	mlx_hook(mystruct->vars.win, 3, 1 << 1, key_release, mystruct);
	mlx_hook(mystruct->vars.win, 4, 1 << 2, mouse_press, mystruct);
	mlx_hook(mystruct->vars.win, 5, 1 << 3, mouse_release, mystruct);
	mlx_hook(mystruct->vars.win, 17, 1 << 17, exit_program, mystruct);
	mlx_loop_hook(mystruct->vars.mlx, render_frame, mystruct);
}

static void	init_minimap_img_helper(t_cub3D *mystruct, t_data *img, const t_point *coords)
{
	t_point	i;

	i.y = -1;
	while (++i.y < MINIMAP_CELL_Y)
	{
		i.x = -1;
		while (++i.x < MINIMAP_CELL_X)
			my_mlx_pixel_put(&mystruct->minimap_img, coords->x * MINIMAP_CELL_X + i.x,
				coords->y * MINIMAP_CELL_Y + i.y, get_color(img, i.x, i.y));
	}
}

void	init_minimap_img(t_cub3D *mystruct)
{
	int		x;
	int		y;

	extract_image(&mystruct->minimap_wall_img, &mystruct->vars, "assets/minimap_wall.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){MINIMAP_CELL_X, MINIMAP_CELL_Y}});
	extract_image(&mystruct->minimap_blank_img, &mystruct->vars, "assets/minimap_blank.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){MINIMAP_CELL_X, MINIMAP_CELL_Y}});
	mystruct->minimap_img.img = mlx_new_image(mystruct->vars.mlx, MINIMAP_CELL_X * mystruct->map_width,
		MINIMAP_CELL_Y * mystruct->map_height);
	mystruct->minimap_img.addr = mlx_get_data_addr(mystruct->minimap_img.img, &mystruct->minimap_img.bits_per_pixel,
		&mystruct->minimap_img.line_length, &mystruct->minimap_img.endian);
	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
		{
			if (mystruct->map[y][x] == SPACE_CHAR)
				init_minimap_img_helper(mystruct, &mystruct->minimap_blank_img, &(t_point){x, y});
			else if (mystruct->map[y][x] == DOOR_CLOSED_CHAR || mystruct->map[y][x] == DOOR_OPEN_CHAR)
				init_minimap_img_helper(mystruct, &mystruct->minimap_door_closed_img, &(t_point){x, y});
			else
				init_minimap_img_helper(mystruct, &mystruct->minimap_wall_img, &(t_point){x, y});
		}
	}
	make_image_transparent(&mystruct->minimap_img, MINIMAP_CELL_X * mystruct->map_width, MINIMAP_CELL_Y * mystruct->map_height, 150);
	mystruct->real_time_minimap_img.img = mlx_new_image(mystruct->vars.mlx, REALTIME_MINIMAP_W, REALTIME_MINIMAP_H);
	mystruct->real_time_minimap_img.addr = mlx_get_data_addr(mystruct->real_time_minimap_img.img, &mystruct->real_time_minimap_img.bits_per_pixel,
		&mystruct->real_time_minimap_img.line_length, &mystruct->real_time_minimap_img.endian);
}

void	init_sprites(t_cub3D *mystruct)
{
	int	sprite_index;
	int	n_of_treasures;
	int	cur_n_of_spaces;

	n_of_treasures = 0;
	for (int y = 0; y < mystruct->map_height; ++y)
		for (int x = 0; x < mystruct->map_width; ++x)
			if (mystruct->map[y][x] == TREASURE_CHAR)
				++n_of_treasures;
	mystruct->n_of_lamps_on_map = mystruct->n_of_spaces_on_map * SPRITE_DENSITY_FACTOR;
	mystruct->n_of_sprites_on_map = mystruct->n_of_lamps_on_map + n_of_treasures;
	mystruct->sprites = ft_calloc(mystruct->n_of_sprites_on_map, sizeof(*mystruct->sprites));
	for (int i = 0; i < mystruct->n_of_sprites_on_map; ++i)
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
	sprite_index = 0;
	cur_n_of_spaces = 0;
	for (int y = 0; y < mystruct->map_height; ++y)
	{
		for (int x = 0; x < mystruct->map_width; ++x)
		{
			if (mystruct->map[y][x] == TREASURE_CHAR)
			{
				--n_of_treasures;
				mystruct->sprites[mystruct->n_of_lamps_on_map + n_of_treasures].posX = x + 0.5;
				mystruct->sprites[mystruct->n_of_lamps_on_map + n_of_treasures].posY = y + 0.5;
				mystruct->map[y][x] = SPACE_CHAR;
			}
			else if (mystruct->map[y][x] == SPACE_CHAR)
			{
				if (++cur_n_of_spaces % (int)(1 / SPRITE_DENSITY_FACTOR) == 0)
				{
					mystruct->sprites[sprite_index].posX = x + 0.5;
					mystruct->sprites[sprite_index].posY = y + 0.5;
					if (++sprite_index == mystruct->n_of_lamps_on_map)
						return ;
				}
			}
		}
	}
}

void	init_images(t_cub3D *mystruct)
{
	mystruct->canvas.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
	mystruct->canvas.addr = mlx_get_data_addr(mystruct->canvas.img, &mystruct->canvas.bits_per_pixel,
		&mystruct->canvas.line_length, &mystruct->canvas.endian);
	mystruct->goggles = malloc(8 * sizeof(*mystruct->goggles));
	for (int i = 0; i < 8; ++i)
		extract_image(&mystruct->goggles[i], &mystruct->vars, "assets/goggles.xpm", &(t_extract_img_args){
			&(t_point){i * 64, 64}, &(t_point){(i + 1) * 64, 0}, &(t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->brush_img, &mystruct->vars, "assets/brush.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){320, 320}});
	extract_image(&mystruct->crosshair_img, &mystruct->vars, "assets/crosshair.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){CROSSHAIR_SIZE, CROSSHAIR_SIZE}});
	mystruct->textures = malloc(N_OF_TEXTURES * sizeof(*mystruct->textures));
	extract_image(&mystruct->textures[TEXTURE_DOOR], &mystruct->vars, "assets/door.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->minimap_door_closed_img, &mystruct->vars, "assets/minimap_door_closed.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->minimap_door_open_img, &mystruct->vars, "assets/minimap_door_open.xpm", &(t_extract_img_args){
		NULL, NULL, &(t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->textures[TEXTURE_LAMP], &mystruct->vars, "assets/wolftextures.xpm", &(t_extract_img_args){
		&(t_point){640, TEXTURE_H}, &(t_point){682, 0}, &(t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->pause_img, &mystruct->vars, "assets/pause.xpm", &(t_extract_img_args){NULL, NULL,
		&(t_point){SCREEN_W, SCREEN_H}});
	extract_image(&mystruct->textures[TEXTURE_NORTH_WALL], &mystruct->vars, mystruct->parse.NO, &(t_extract_img_args){
		NULL, NULL, &(t_point){WALL_TEXTURE_W, WALL_TEXTURE_H}});
	extract_image(&mystruct->textures[TEXTURE_EAST_WALL], &mystruct->vars, mystruct->parse.EA, &(t_extract_img_args){
		NULL, NULL, &(t_point){WALL_TEXTURE_W, WALL_TEXTURE_H}});
	extract_image(&mystruct->textures[TEXTURE_SOUTH_WALL], &mystruct->vars, mystruct->parse.SO, &(t_extract_img_args){
		NULL, NULL, &(t_point){WALL_TEXTURE_W, WALL_TEXTURE_H}});
	extract_image(&mystruct->textures[TEXTURE_WEST_WALL], &mystruct->vars, mystruct->parse.WE, &(t_extract_img_args){
		NULL, NULL, &(t_point){WALL_TEXTURE_W, WALL_TEXTURE_H}});
	make_image_transparent(&mystruct->pause_img, SCREEN_W, SCREEN_H, 120);
	init_sprites(mystruct);
	init_minimap_img(mystruct);
}

void	init_parameters(t_cub3D *mystruct)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
		{
			c = mystruct->map[y][x];
			if (c == SPACE_CHAR)
				++mystruct->n_of_spaces_on_map;
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				mystruct->map[y][x] = SPACE_CHAR;
				mystruct->posX = x + 0.5;
				mystruct->posY = y + 0.5;
			}
		}
	}
	mystruct->posZ = 0.5 * SCREEN_H;
	mystruct->ZBuffer = malloc(SCREEN_W * sizeof(*mystruct->ZBuffer));
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
}
