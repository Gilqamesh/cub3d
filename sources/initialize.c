#include "initialize.h"
#include "definitions.h"
#include "mlx.h"
#include <stdlib.h>
#include "utils.h"

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
	mystruct->posX = 22;
	mystruct->posY = 12;
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
}
