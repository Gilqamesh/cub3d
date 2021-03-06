#include "main.h"

static void	destroy_images_helper(t_cub3D *mystruct)
{
	if (mystruct->canvas.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->canvas.img);
	if (mystruct->pause_img.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->pause_img.img);
	if (mystruct->minimap_img.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->minimap_img.img);
	if (mystruct->minimap_wall_img.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->minimap_wall_img.img);
	if (mystruct->minimap_blank_img.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->minimap_blank_img.img);
	if (mystruct->real_time_minimap_img.img)
		mlx_destroy_image(mystruct->vars.mlx,
			mystruct->real_time_minimap_img.img);
	if (mystruct->brush_img.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->brush_img.img);
	if (mystruct->minimap_door_closed_img.img)
		mlx_destroy_image(mystruct->vars.mlx,
			mystruct->minimap_door_closed_img.img);
	if (mystruct->minimap_door_open_img.img)
		mlx_destroy_image(mystruct->vars.mlx,
			mystruct->minimap_door_open_img.img);
	if (mystruct->crosshair_img.img)
		mlx_destroy_image(mystruct->vars.mlx, mystruct->crosshair_img.img);
}

static void	destroy_images(t_cub3D *mystruct)
{
	int	i;

	i = -1;
	while (++i < N_OF_TEXTURES)
		if (mystruct->textures && mystruct->textures[i].img)
			if (mystruct->textures[i].img)
				mlx_destroy_image(mystruct->vars.mlx,
					mystruct->textures[i].img);
	i = -1;
	while (++i < 8)
		if (mystruct->goggles && mystruct->goggles[i].img)
			if (mystruct->goggles[i].img)
				mlx_destroy_image(mystruct->vars.mlx, mystruct->goggles[i].img);
	i = -1;
	while (++i < AMBER_SPRITES_N)
		if (mystruct->amber_sprites && mystruct->amber_sprites[i].img)
			mlx_destroy_image(mystruct->vars.mlx,
				mystruct->amber_sprites[i].img);
	destroy_images_helper(mystruct);
}

int	exit_program(int fd, const char *msg, ...)
{
	t_cub3D	*mystruct;
	va_list	ap;

	mystruct = ft_get_ptr(NULL);
	if (fd == STDERR_FILENO)
		ft_dprintf(STDERR_FILENO, "ERROR\n");
	va_start(ap, msg);
	ft_vdprintf(fd, msg, ap);
	va_end(ap);
	destroy_images(mystruct);
	ft_lstmallocfree(&mystruct->alloced_memory);
	if (fd == STDERR_FILENO)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
