#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "struct.h"
# include "../ray_casting_logic/wall_casting.h"

void	init_struct(t_cub3D *mystruct);
void	init_hooks(t_cub3D *mystruct);
void	init_minimap_img(t_cub3D *mystruct);
void	init_sprites(t_cub3D *mystruct);
void	init_images(t_cub3D *mystruct);
void	init_parameters(t_cub3D *mystruct);
void	init_wall_images(t_cub3D *mystruct);
void	init_textures(t_cub3D *mystruct);
void	initialize_wall_ray(t_cub3D *mystruct, int current_column,
			t_wall_cast_params *p);

#endif /* INITIALIZE_H */
