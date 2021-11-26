#include "headers.h"

void	init_struct(t_cub3D *mystruct)
{
	mystruct->map = malloc(mapHeight * sizeof(*mystruct->map));
	for (int i = 0; i < mapHeight; ++i)
		mystruct->map[i] = malloc(mapWidth * sizeof(*mystruct->map[i]));
	PRINT_HERE();
	PRINT_HERE();
	mystruct->vars.mlx = mlx_init();
	PRINT_HERE();
	mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, TITLE);
	PRINT_HERE();
	mystruct->img.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
	PRINT_HERE();
	mystruct->img.addr = mlx_get_data_addr(mystruct->img.img, &mystruct->img.bits_per_pixel,
		&mystruct->img.line_length, &mystruct->img.endian);
	mystruct->posX = 1.0;
	mystruct->posY = 1.0;
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
	mystruct->textures = malloc(8 * sizeof(*mystruct->textures));
	PRINT_HERE();
	for (int i = 0; i < 8; ++i)
		extract_image(&mystruct->textures[i], (t_args1){
			(t_point){i * TEXTURE_W, TEXTURE_H - 1}, (t_point){(i + 1) * TEXTURE_W - 1, 0}, "assets/wolftextures.xpm",
			&mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
}

void	install_hooks(t_cub3D *mystruct)
{
	mlx_loop_hook(mystruct->vars.mlx, render_frame, mystruct);
	mlx_key_hook(mystruct->vars.win, key_hook, mystruct);
}
