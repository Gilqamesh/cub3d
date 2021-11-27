#include "headers.h"

void	init_struct(t_cub3D *mystruct)
{
	mystruct->map = malloc(mapHeight * sizeof(*mystruct->map));
	for (int i = 0; i < mapHeight; ++i)
		mystruct->map[i] = malloc(mapWidth * sizeof(*mystruct->map[i]));
	mystruct->vars.mlx = mlx_init();
	mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H, TITLE);
	mystruct->img.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W, SCREEN_H);
	mystruct->img.addr = mlx_get_data_addr(mystruct->img.img, &mystruct->img.bits_per_pixel,
		&mystruct->img.line_length, &mystruct->img.endian);
	mystruct->posX = 1.5;
	mystruct->posY = 1.5;
	mystruct->posZ = 0.5 * SCREEN_H;
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
	mystruct->moveSpeed = 1.0 / FPS * 4.0;
	mystruct->rotSpeed = 1.0 / FPS * 3.0;
	mlx_mouse_hide();
	mlx_mouse_move(mystruct->vars.win, SCREEN_W / 2, SCREEN_H / 2);
	mystruct->textures = malloc(8 * sizeof(*mystruct->textures));
	for (int i = 0; i < 8; ++i)
		extract_image(&mystruct->textures[i], (t_args1){
			(t_point){i * TEXTURE_W, TEXTURE_H - 1}, (t_point){(i + 1) * TEXTURE_W - 1, 0},
			"assets/wolftextures.xpm", &mystruct->vars, (t_point){TEXTURE_W, TEXTURE_H}});
}

void	install_hooks(t_cub3D *mystruct)
{
	mlx_do_key_autorepeatoff(mystruct->vars.mlx);
	mlx_hook(mystruct->vars.win, 2, 1, key_press, mystruct);
	mlx_hook(mystruct->vars.win, 3, 1 << 1, key_release, mystruct);
	mlx_hook(mystruct->vars.win, 17, 1 << 17, exit_program, mystruct);
	mlx_loop_hook(mystruct->vars.mlx, render_frame, mystruct);
}
