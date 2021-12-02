#ifndef DRAW_H
# define DRAW_H

# include "struct.h"
# include "../ray_casting_logic/wall_casting.h"
# include "../ray_casting_logic/sprite_casting.h"

void	draw_crosshair(t_cub3D *mystruct);
void	draw_pause_screen(t_cub3D *mystruct);
void	draw_minimap(t_cub3D *mystruct);
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, unsigned int color);
void	draw_line(t_data *data, t_point A, t_point B, unsigned int color);
void	draw_filled_circle(t_data *data, t_point center, int radius, unsigned int color);
void	draw_brush(t_cub3D *mystruct);
void	draw_wall(t_cub3D *mystruct, int current_column, t_wall_cast_params *p);
void	draw_sprite_stripe(t_cub3D *mystruct, int i, int stripe,
			t_sprite_cast_params *p);

#endif /* DRAW_H */
