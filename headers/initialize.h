#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "struct.h"

void	init_struct(t_cub3D *mystruct, t_input_parse *parse);
void	install_hooks(t_cub3D *mystruct);
void	init_minimap_img(t_cub3D *mystruct);
void	init_map(t_cub3D *mystruct, t_input_parse *parse);
void	init_position(t_cub3D *mystruct);
void	init_sprites(t_cub3D *mystruct);

#endif /* INITIALIZE_H */
