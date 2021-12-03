#include "main.h"

static void	init_minimap_img_helper(t_cub3D *mystruct, t_data *img,
const t_point *coords)
{
	t_point	i;

	i.y = -1;
	while (++i.y < SCREEN_H / 40)
	{
		i.x = -1;
		while (++i.x < SCREEN_W / 40)
			my_mlx_pixel_put(&mystruct->minimap_img,
				coords->x * SCREEN_W / 40 + i.x,
				coords->y * SCREEN_H / 40 + i.y, get_color(img, i.x, i.y));
	}
}

static void	init_minimap_img_helper2(t_cub3D *mystruct)
{
	extract_image(&mystruct->minimap_wall_img, &mystruct->vars,
		"assets/minimap_wall.xpm", &(t_extract_img_args){NULL, NULL,
		&(t_point){SCREEN_W / 40, SCREEN_H / 40}});
	extract_image(&mystruct->minimap_blank_img, &mystruct->vars,
		"assets/minimap_blank.xpm", &(t_extract_img_args){NULL, NULL,
		&(t_point){SCREEN_W / 40, SCREEN_H / 40}});
	mystruct->minimap_img.img = mlx_new_image(mystruct->vars.mlx, SCREEN_W / 40
			* mystruct->map_width, SCREEN_H / 40 * mystruct->map_height);
	if (mystruct->minimap_blank_img.img == NULL)
		exit_program(STDERR_FILENO, "mlx_new_image failed in file %s\n",
			__FILE__);
	mystruct->minimap_img.addr = mlx_get_data_addr(mystruct->minimap_img.img,
			&mystruct->minimap_img.bits_per_pixel,
			&mystruct->minimap_img.line_length, &mystruct->minimap_img.endian);
}

static void	init_minimap_img_helper3(t_cub3D *mystruct)
{
	make_image_transparent(&mystruct->minimap_img, SCREEN_W / 40
		* mystruct->map_width, SCREEN_H / 40 * mystruct->map_height, 150);
	mystruct->real_time_minimap_img.img = mlx_new_image(mystruct->vars.mlx,
			SCREEN_W / 40 * MINIMAP_N_OF_CELL_X,
			SCREEN_H / 40 * MINIMAP_N_OF_CELL_Y);
	if (mystruct->real_time_minimap_img.img == NULL)
		exit_program(STDERR_FILENO, "mlx_new_image failed in file %s\n",
			__FILE__);
	mystruct->real_time_minimap_img.addr = mlx_get_data_addr(
			mystruct->real_time_minimap_img.img,
			&mystruct->real_time_minimap_img.bits_per_pixel,
			&mystruct->real_time_minimap_img.line_length,
			&mystruct->real_time_minimap_img.endian);
}

void	init_minimap_img(t_cub3D *mystruct)
{
	int		x;
	int		y;

	init_minimap_img_helper2(mystruct);
	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
		{
			if (mystruct->map[y][x] == SPACE_CHAR)
				init_minimap_img_helper(mystruct, &mystruct->minimap_blank_img,
					&(t_point){x, y});
			else if (mystruct->map[y][x] == DOOR_CLOSED_C
				|| mystruct->map[y][x] == DOOR_OPEN_C)
				init_minimap_img_helper(mystruct,
					&mystruct->minimap_door_closed_img, &(t_point){x, y});
			else
				init_minimap_img_helper(mystruct, &mystruct->minimap_wall_img,
					&(t_point){x, y});
		}
	}
	init_minimap_img_helper3(mystruct);
}
