#ifndef FLOOR_CASTING_H
# define FLOOR_CASTING_H

# include "struct.h"

// rowDistance	horizontal distance from the camera to the floor
// floorStep	real world step vector we have to add for each x (parallel to camera plane)
// 				adding step by step avoids multiplications with a weight in the loop
// floor		real world coordinates of the leftmost column. This will be updated
//				as we step to the right.
// tx, ty		texture coordinates
typedef struct s_floor_cast_params
{
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;
	int		tx;
	int		ty;
}	t_floor_cast_params;

void	floor_casting(t_cub3D *mystruct);
void	initialize_floor_ray(t_cub3D *mystruct, int current_row, t_floor_cast_params *p);

#endif /* FLOOR_CASTING_H */
