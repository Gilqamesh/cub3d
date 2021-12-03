#include "main.h"

void	init_struct(t_cub3D *mystruct)
{
	init_parameters(mystruct);
	mystruct->vars.mlx = mlx_init();
	mystruct->vars.win = mlx_new_window(mystruct->vars.mlx, SCREEN_W, SCREEN_H,
			TITLE);
	init_images(mystruct);
}

void	init_hooks(t_cub3D *mystruct)
{
	mlx_do_key_autorepeatoff(mystruct->vars.mlx);
	mlx_hook(mystruct->vars.win, 2, 1, key_press, mystruct);
	mlx_hook(mystruct->vars.win, 3, 1 << 1, key_release, mystruct);
	mlx_hook(mystruct->vars.win, 4, 1 << 2, mouse_press, mystruct);
	mlx_hook(mystruct->vars.win, 5, 1 << 3, mouse_release, mystruct);
	mlx_hook(mystruct->vars.win, 17, 1 << 17, destroy_window, mystruct);
	mlx_loop_hook(mystruct->vars.mlx, render_frame, mystruct);
}

void	init_images(t_cub3D *mystruct)
{
	mystruct->canvas.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W,
			SCREEN_H);
	if (mystruct->canvas.img == NULL)
		exit_program(STDERR_FILENO, "mlx_new_image failed in file %s\n",
			__FILE__);
	mystruct->canvas.addr = mlx_get_data_addr(mystruct->canvas.img,
			&mystruct->canvas.bits_per_pixel, &mystruct->canvas.line_length,
			&mystruct->canvas.endian);
	mystruct->goggles = ft_lstmallocwrapper(&mystruct->alloced_memory,
			8 * sizeof(*mystruct->goggles), false);
	if (mystruct->goggles == NULL)
		exit_program(STDERR_FILENO, "malloc failed in init_images in file %s\n",
			__FILE__);
	mystruct->amber_sprites = ft_lstmallocwrapper(&mystruct->alloced_memory,
			AMBER_SPRITES_N * sizeof(*mystruct->amber_sprites), false);
	if (mystruct->amber_sprites == NULL)
		exit_program(STDERR_FILENO, "malloc failed in init_images in file %s\n",
			__FILE__);
	init_textures(mystruct);
	init_wall_images(mystruct);
	make_image_transparent(&mystruct->pause_img, SCREEN_W, SCREEN_H, 120);
	init_sprites(mystruct);
	init_minimap_img(mystruct);
}

static void	init_parameters_helper(t_cub3D *mystruct)
{
	t_point	iter;

	iter.y = -1;
	while (++iter.y < mystruct->map_height)
	{
		iter.x = -1;
		while (++iter.x < mystruct->map_width)
		{
			if (mystruct->map[iter.y][iter.x] == SPACE_CHAR)
				++mystruct->n_of_spaces_on_map;
			if (mystruct->map[iter.y][iter.x] == 'N' || mystruct->map[iter.y]
				[iter.x] == 'S' || mystruct->map[iter.y][iter.x] == 'W'
				|| mystruct->map[iter.y][iter.x] == 'E')
			{
				mystruct->map[iter.y][iter.x] = SPACE_CHAR;
				mystruct->posX = iter.x + 0.5;
				mystruct->posY = iter.y + 0.5;
			}
		}
	}
}

void	init_parameters(t_cub3D *mystruct)
{
	init_parameters_helper(mystruct);
	mystruct->posZ = 0.5 * SCREEN_H;
	mystruct->ZBuffer = ft_lstmallocwrapper(&mystruct->alloced_memory,
			SCREEN_W * sizeof(*mystruct->ZBuffer), false);
	if (mystruct->ZBuffer == NULL)
		exit_program(STDERR_FILENO, "malloc failed in init_parameters in file "\
			"%s\n", __FILE__);
	mystruct->dirX = -1;
	mystruct->dirY = 0;
	mystruct->planeX = 0;
	mystruct->planeY = 0.66;
}
