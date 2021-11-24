#include "mylib.h"
#include "mlx.h"
#include "struct.h"
#include "definitions.h"
#include "initialize.h"
#include "hook.h"
#include <stdio.h>
#include "utils.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_cub3D	mystruct;
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <map_name.cub>", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	init_struct(&mystruct);
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
			mystruct.map[i][j] = worldMap[i][j] + '0';
	mlx_loop_hook(mystruct.vars.mlx, render_frame, &mystruct);
	mlx_hook(mystruct.vars.win, 02, 1L << 0, key_hook, &mystruct);
	// my_mlx_pixel_put(&mystruct.img, 0, 0, YELLOW);
	// mlx_put_image_to_window(mystruct.vars.mlx, mystruct.vars.win,
	// 	mystruct.img.img, 0, 0);
	// for (int i = 0; i < 8; ++i)
	// 	mlx_put_image_to_window(mystruct.vars.mlx, mystruct.vars.win,
	// 		mystruct.textures[i].img, i * (TEXTURE_W + 10), 10);
	mlx_loop(mystruct.vars.mlx);
	// parsing();
	// build_tree();
	// hook_install();
	// mlx_loop();
	// destroy_struct();
}
// (struct Point){1, 2},
// (struct Point){7, 8},
// (1, 7)
// t = (1 - 7) / (1 - 7) = 1
// t = (7 - 8) / (2 - 8) = -1 / -6
// t = (x - x2) / (x1 - x2)
// t = (y - y2) / (y1 - y2)