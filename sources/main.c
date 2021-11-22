#include "mylib.h"
#include "mlx.h"
#include "struct.h"
#include "definitions.h"
#include <stdio.h>
#include <math.h>

int	round_to_nearest(double a)
{
	if ((int)(a * 10) % 10 < 5)
		return ((int)a);
	return ((int)(a + 1));
}

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;
	int		a;
	int		b;

	a = round_to_nearest(x);
	b = round_to_nearest(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_cub3D	mystruct;
	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <map_name.cub>", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	init_struct(&mystruct);
	mystruct.map = malloc(10 * sizeof(char *));
	for (int i = 0; i < 10; ++i)
		mystruct.map[i] = malloc(10);
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			mystruct.map[i][j] = '0';
	struct line_segment	line = {
		(struct Point){1, 2},
		(struct Point){7, 8},
		GREEN
	};
	t_data	img;
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SCREEN_W, SCREEN_H, TITLE);
	img.img = mlx_new_image(vars.mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int x = 0; x < 10; ++x)
	{
		for (int y = 0; y < 10; ++y)
		{
			bool draw = false;
			float t = (x - line.B.x) / (float)(line.A.x - line.B.x);
			if (line.A.x != line.B.x)
			{
				if (t >= 0.0f && t <= 1.0f)
					draw = true;
				printf("%f\n", t);
			}
			if (line.A.y != line.B.y)
			{
				float t2 = (y - line.B.y) / (float)(line.A.y - line.B.y);
				if (t2 >= 0.0f && t2 <= 1.0f && fabs(t2 - t) < 0.3f)
					draw = true;
				else
					draw = false;
				printf("%f\n", t);
			}
			if (draw)
			{
				mystruct.map[y][x] = '1';
				my_mlx_pixel_put(&img, x * 10, y * 10, 0x00ff0000);
			}
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
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