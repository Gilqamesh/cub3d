#include "headers.h"

void	init_struct(t_cub3D *mystruct, t_input_parse *parse)
{
	init_map(mystruct, parse);
	mystruct->ZBuffer = malloc(SCREEN_W * sizeof(*mystruct->ZBuffer));
	mystruct->vars.mlx = mlx_init();
	mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, TITLE);
	mystruct->canvas.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
	mystruct->canvas.addr = mlx_get_data_addr(mystruct->canvas.img, &mystruct->canvas.bits_per_pixel,
		&mystruct->canvas.line_length, &mystruct->canvas.endian);
	init_position(mystruct);
	mystruct->posZ = 0.5 * SCREEN_H;
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
	mystruct->textures = malloc(N_OF_TEXTURES * sizeof(*mystruct->textures));
	for (int i = 0; i < LAMP; ++i)
		extract_image(&mystruct->textures[i], (t_args1){
			(t_point){i * TEXTURE_W, TEXTURE_H}, (t_point){(i + 1) * TEXTURE_W, 0},
			"assets/wolftextures.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->textures[LAMP], (t_args1){
		(t_point){640, TEXTURE_H}, (t_point){682, 0}, "assets/wolftextures.xpm",
		&mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->pause_img, (t_args1){
		(t_point){0, 681}, (t_point){1007, 0}, "assets/pause.xpm", &mystruct->vars, (t_point){SCREEN_W, SCREEN_H}});
	make_image_transparent(&mystruct->pause_img, SCREEN_W, SCREEN_H, 120);
	extract_image(&mystruct->wall_textures[NORTH_WALL_TEXTURE], (t_args1){
			(t_point){0, 320}, (t_point){320, 0}, "assets/NORTH_WALL.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->wall_textures[EAST_WALL_TEXTURE], (t_args1){
			(t_point){0, 320}, (t_point){320, 0}, "assets/EAST_WALL.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->wall_textures[SOUTH_WALL_TEXTURE], (t_args1){
			(t_point){0, 320}, (t_point){320, 0}, "assets/SOUTH_WALL.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->wall_textures[WEST_WALL_TEXTURE], (t_args1){
			(t_point){0, 320}, (t_point){320, 0}, "assets/WEST_WALL.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	PRINT_HERE();
	init_minimap_img(mystruct);
	PRINT_HERE();
	init_sprites(mystruct);
	PRINT_HERE();
	mystruct->prev_timestamp = get_current_timestamp();
}

void	install_hooks(t_cub3D *mystruct)
{
	mlx_do_key_autorepeatoff(mystruct->vars.mlx);
	mlx_hook(mystruct->vars.win, 2, 1, key_press, mystruct);
	mlx_hook(mystruct->vars.win, 3, 1 << 1, key_release, mystruct);
	mlx_hook(mystruct->vars.win, 17, 1 << 17, exit_program, mystruct);
	mlx_loop_hook(mystruct->vars.mlx, render_frame, mystruct);
}

void	init_minimap_img(t_cub3D *mystruct)
{
	int		x;
	int		y;
	t_point	i;

	PRINT_HERE();
	extract_image(&mystruct->minimap_wall_img, (t_args1){
		(t_point){0, 320}, (t_point){320, 0}, "assets/minimap_wall.xpm", &mystruct->vars,
		(t_point){MINIMAP_CELL_X, MINIMAP_CELL_Y}});
	PRINT_HERE();
	extract_image(&mystruct->minimap_blank_img, (t_args1){
		(t_point){0, 320}, (t_point){320, 0}, "assets/minimap_blank.xpm", &mystruct->vars,
		(t_point){MINIMAP_CELL_X, MINIMAP_CELL_Y}});
	PRINT_HERE();
	mystruct->minimap_img.img = mlx_new_image(mystruct->vars.mlx, MINIMAP_CELL_X * mystruct->map_width,
		MINIMAP_CELL_Y * mystruct->map_height);
	PRINT_HERE();
	mystruct->minimap_img.addr = mlx_get_data_addr(mystruct->minimap_img.img, &mystruct->minimap_img.bits_per_pixel,
		&mystruct->minimap_img.line_length, &mystruct->minimap_img.endian);
	PRINT_HERE();
	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
		{
			PRINT_HERE();
			printf("x: %d y: %d\n", x, y);
			ft_printf("%p\n", mystruct->map);
			ft_printf("%s\n", mystruct->map[y]);
			printf("%c\n", mystruct->map[y][x]);
			PRINT_HERE();
			if (mystruct->map[y][x] == '0')
			{
				i.y = -1;
				while (++i.y < MINIMAP_CELL_Y)
				{
					i.x = -1;
					while (++i.x < MINIMAP_CELL_X)
						my_mlx_pixel_put(&mystruct->minimap_img, x * MINIMAP_CELL_X + i.x, y * MINIMAP_CELL_Y + i.y,
							get_color(&mystruct->minimap_blank_img, i.x, i.y));
				}
			}
			else
			{
				i.y = -1;
				while (++i.y < MINIMAP_CELL_Y)
				{
					i.x = -1;
					while (++i.x < MINIMAP_CELL_X)
						my_mlx_pixel_put(&mystruct->minimap_img, x * MINIMAP_CELL_X + i.x, y * MINIMAP_CELL_Y + i.y,
							get_color(&mystruct->minimap_wall_img, i.x, i.y));
				}
			}
			PRINT_HERE();
		}
	}
	PRINT_HERE();
	make_image_transparent(&mystruct->minimap_img, MINIMAP_CELL_X * mystruct->map_width, MINIMAP_CELL_Y * mystruct->map_height, 150);
	PRINT_HERE();
	mystruct->real_time_minimap_img.img = mlx_new_image(mystruct->vars.mlx, REALTIME_MINIMAP_W, REALTIME_MINIMAP_H);
	PRINT_HERE();
	mystruct->real_time_minimap_img.addr = mlx_get_data_addr(mystruct->real_time_minimap_img.img, &mystruct->real_time_minimap_img.bits_per_pixel,
		&mystruct->real_time_minimap_img.line_length, &mystruct->real_time_minimap_img.endian);
	PRINT_HERE();
}

void	init_map(t_cub3D *mystruct, t_input_parse *parse)
{
	mystruct->map = parse->two_d_array;
	ft_printf("Map addresses: %p %p\n", mystruct->map, parse->two_d_array);
	for (int i = 0; i < parse->map_height; ++i)
	{
		for (int j = 0; j < parse->map_width; ++j)
			ft_printf("%c ", parse->two_d_array[i][j]);
		ft_printf("\n");
	}
	mystruct->map_height = parse->map_height;
	mystruct->map_width = parse->map_width;
}

void	init_position(t_cub3D *mystruct)
{
	char	c;

	for (int y = 0; y < mystruct->map_height; ++y)
	{
		for (int x = 0; x < mystruct->map_width; ++x)
		{
			c = mystruct->map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				mystruct->map[y][x] = '0';
				mystruct->posX = x + 0.5;
				mystruct->posY = y + 0.5;
				return ;
			}
		}
	}
}

void	init_sprites(t_cub3D *mystruct)
{
	int	sprite_index;

	mystruct->n_of_sprites_on_map = 20;
	mystruct->sprites = ft_calloc(mystruct->n_of_sprites_on_map, sizeof(*mystruct->sprites));
	for (int i = 0; i < mystruct->n_of_sprites_on_map; ++i)
		mystruct->sprites[i].img = &mystruct->textures[LAMP];
	sprite_index = 0;
	for (int y = 0; y < mystruct->map_height; ++y)
	{
		for (int x = 0; x < mystruct->map_width; ++x)
		{
			if (mystruct->map[y][x] == '0')
			{
				mystruct->sprites[sprite_index].posX = x + 0.5;
				mystruct->sprites[sprite_index].posY = y + 0.5;
				if (++sprite_index == mystruct->n_of_sprites_on_map)
					return ;
			}
		}
	}
}
