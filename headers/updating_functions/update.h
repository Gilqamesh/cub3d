#ifndef UPDATE_H
# define UPDATE_H

# include "struct.h"

void	update_position_by_key(t_cub3D *mystruct, int key);
void	update_position(t_cub3D *mystruct);
void	update_mouse(t_cub3D *mystruct);
void	update_canvas(t_cub3D *mystruct);
int		render_frame(void *param);
void	update_state_of_sprites(t_cub3D *mystruct, int i);
void	handle_forward_backward(int key, t_cub3D *mystruct, double x,
			double y);
void	handle_left_right_strafe(int key, t_cub3D *mystruct, double x,
			double y);

#endif /* UPDATE_H */
