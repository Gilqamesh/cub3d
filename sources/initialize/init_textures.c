#include "main.h"

void	init_wall_images(t_cub3D *mystruct)
{
	extract_image(&mystruct->textures[TEXT_N_WALL], &mystruct->vars,
		mystruct->parse.NO, &(t_extract_img_args){NULL, NULL,
		&(t_point){TEXT_W, TEXT_H}});
	extract_image(&mystruct->textures[TEXT_E_WALL], &mystruct->vars,
		mystruct->parse.EA, &(t_extract_img_args){NULL, NULL,
		&(t_point){TEXT_W, TEXT_H}});
	extract_image(&mystruct->textures[TEXT_S_WALL], &mystruct->vars,
		mystruct->parse.SO, &(t_extract_img_args){NULL, NULL,
		&(t_point){TEXT_W, TEXT_H}});
	extract_image(&mystruct->textures[TEXT_W_WALL], &mystruct->vars,
		mystruct->parse.WE, &(t_extract_img_args){NULL, NULL,
		&(t_point){TEXT_W, TEXT_H}});
}

static void	init_textures_helper(t_cub3D *mystruct)
{
	extract_image(&mystruct->minimap_door_closed_img, &mystruct->vars,
		"assets/minimap_door_closed.xpm", &(t_extract_img_args){NULL, NULL,
		&(t_point){TEXT_W, TEXT_H}});
	extract_image(&mystruct->minimap_door_open_img, &mystruct->vars,
		"assets/minimap_door_open.xpm", &(t_extract_img_args){NULL, NULL,
		&(t_point){TEXT_W, TEXT_H}});
	extract_image(&mystruct->textures[TEXTURE_LAMP], &mystruct->vars,
		"assets/wolftextures.xpm", &(t_extract_img_args){&(t_point){640,
		64}, &(t_point){682, 0}, &(t_point){TEXT_W, TEXT_H}});
	extract_image(&mystruct->pause_img, &mystruct->vars, "assets/pause.xpm",
		&(t_extract_img_args){NULL, NULL,&(t_point){SCREEN_W, SCREEN_H}});
}

static void	init_textures_helper2(t_cub3D *mystruct)
{
	static char	*amber_textures[AMBER_SPRITES_N] = {
		"assets/AMBER_E.xpm", "assets/AMBER_N.xpm", "assets/AMBER_S.xpm",
		"assets/AMBER_W.xpm", "assets/AMBER_W2.xpm"};
	int					i;

	i = -1;
	while (++i < AMBER_SPRITES_N)
		extract_image(&mystruct->amber_sprites[i], &mystruct->vars,
			amber_textures[i], &(t_extract_img_args){NULL, NULL,
			&(t_point){TEXT_W, TEXT_H}});
}

void	init_textures(t_cub3D *mystruct)
{
	int	i;

	i = -1;
	while (++i < 8)
		extract_image(&mystruct->goggles[i], &mystruct->vars,
		"assets/goggles.xpm", &(t_extract_img_args){&(t_point){i * 64, 64},
		&(t_point){(i + 1) * 64, 0}, &(t_point){64, 64}});
	extract_image(&mystruct->brush_img, &mystruct->vars, "assets/brush.xpm",
		&(t_extract_img_args){NULL, NULL, &(t_point){320, 320}});
	extract_image(&mystruct->crosshair_img, &mystruct->vars,
		"assets/crosshair.xpm", &(t_extract_img_args){NULL, NULL,
		&(t_point){CROSSHAIR_SIZE, CROSSHAIR_SIZE}});
	mystruct->textures = malloc(N_OF_TEXTURES * sizeof(*mystruct->textures));
	extract_image(&mystruct->textures[TEXTURE_DOOR], &mystruct->vars,
		"assets/door.xpm", &(t_extract_img_args){NULL, NULL, &(t_point){
			TEXT_W, TEXT_H}});
	init_textures_helper(mystruct);
	init_textures_helper2(mystruct);
}
