#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

void	draw_crosshair(t_cub3D *mystruct);
void	draw_pause_screen(t_cub3D *mystruct);
void	draw_minimap(t_cub3D *mystruct);
void	verLine(t_cub3D *mystruct, int x, int y_start, int y_end, int color);
void	draw_line(t_data *data, t_point A, t_point B, unsigned int color);
void	draw_filled_circle(t_data *data, t_point center, int radius, int color);

#endif /* DRAW_H */
