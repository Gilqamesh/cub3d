#include "headers.h"

void	init_struct(t_cub3D *mystruct)
{
	mystruct->map = malloc(mapHeight * sizeof(*mystruct->map));
	for (int i = 0; i < mapHeight; ++i)
		mystruct->map[i] = malloc(mapWidth * sizeof(*mystruct->map[i]));
	init_map(mystruct);
	mystruct->vars.mlx = mlx_init();
	mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, TITLE);
	mystruct->canvas.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
	mystruct->canvas.addr = mlx_get_data_addr(mystruct->canvas.img, &mystruct->canvas.bits_per_pixel,
		&mystruct->canvas.line_length, &mystruct->canvas.endian);
	mystruct->posX = 1.5;
	mystruct->posY = 1.5;
	mystruct->posZ = 0.5 * SCREEN_H;
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
	mystruct->moveSpeed = 1.0 / FPS * 2.0;
	mystruct->rotSpeed = 1.0 / FPS;
	mlx_mouse_hide();
	mlx_mouse_move(mystruct->vars.win, SCREEN_W / 2, SCREEN_H / 2);
	mystruct->textures = malloc(8 * sizeof(*mystruct->textures));
	for (int i = 0; i < 8; ++i)
		extract_image(&mystruct->textures[i], (t_args1){
			(t_point){i * TEXTURE_W, TEXTURE_H}, (t_point){(i + 1) * TEXTURE_W, 0},
			"assets/wolftextures.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
	extract_image(&mystruct->pause_img, (t_args1){
		(t_point){0, 681}, (t_point){1007, 0}, "assets/pause.xpm", &mystruct->vars, (t_point){SCREEN_W, SCREEN_H}});
	make_image_transparent(&mystruct->pause_img, SCREEN_W, SCREEN_H, 120);
	init_minimap_img(mystruct);
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

	extract_image(&mystruct->minimap_wall_img, (t_args1){
		(t_point){0, 320}, (t_point){320, 0}, "assets/minimap_wall.xpm", &mystruct->vars,
		(t_point){MINIMAP_CELL_X, MINIMAP_CELL_Y}});
	extract_image(&mystruct->minimap_blank_img, (t_args1){
		(t_point){0, 320}, (t_point){320, 0}, "assets/minimap_blank.xpm", &mystruct->vars,
		(t_point){MINIMAP_CELL_X, MINIMAP_CELL_Y}});
	mystruct->minimap_img.img = mlx_new_image(mystruct->vars.mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	mystruct->minimap_img.addr = mlx_get_data_addr(mystruct->minimap_img.img, &mystruct->minimap_img.bits_per_pixel,
		&mystruct->minimap_img.line_length, &mystruct->minimap_img.endian);
	y = -1;
	while (++y < mapHeight)
	{
		x = -1;
		while (++x < mapWidth)
		{
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
		}
	}
	make_image_transparent(&mystruct->minimap_img, MINIMAP_WIDTH, MINIMAP_HEIGHT, 150);
	mystruct->real_time_minimap_img.img = mlx_new_image(mystruct->vars.mlx, REALTIME_MINIMAP_W, REALTIME_MINIMAP_H);
	mystruct->real_time_minimap_img.addr = mlx_get_data_addr(mystruct->real_time_minimap_img.img, &mystruct->real_time_minimap_img.bits_per_pixel,
		&mystruct->real_time_minimap_img.line_length, &mystruct->real_time_minimap_img.endian);
}

void	init_map(t_cub3D *mystruct)
{
	int	worldMap[mapWidth][mapHeight] =
	{
		{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
		{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
		{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
		{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
		{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
		{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
		{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
		{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
		{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
		{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
		{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
		{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
		{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
		{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
		{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
		{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
		{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
		{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
		{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
		{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
		{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
	};
	for (int i = 0; i < mapHeight; ++i)
		for (int j = 0; j < mapWidth; ++j)
			mystruct->map[i][j] = worldMap[i][j] + '0';
}
