#ifndef WALL_CASTING_H
# define WALL_CASTING_H

# include "struct.h"

// cameraX		x-coordinate in camera space
// rayDir		ray vector
// map			which box of the map we're in
// sideDist		length of ray from current position to next x or y-side
// deltaDist	length of ray from one x or y-side to next x or y-side
// perpWallDist	distance projected on camera plane
// step			what direction to step in x or y-direction (either +1 or -1)
// side			was a NS or a EW wall hit?
// lineHeight	height of line to draw on screen
// drawStart	lowest pixel to fill in current stripe
// drawEnd		highest pixel to fill in current stripe
typedef struct s_wall_cast_params
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	char	hit;
}	t_wall_cast_params;

// wallX		where the wall was hit
// tex			coordinates of the texture
// step			how much to increase the texture coordinate per screen pixel
// texPos		starting texture coordinate
// color		color taken from the texture
typedef struct s_draw_wall_params
{
	double			wallX;
	int				texX;
	int				texY;
	double			step;
	double			texPos;
	unsigned int	color;
}	t_draw_wall_params;

void	wall_casting(t_cub3D *mystruct);
void	perform_dda(t_cub3D *mystruct, int current_column,
			t_wall_cast_params *p);
void	calculate_distance(t_wall_cast_params *p);

#endif /* WALL_CASTING_H */
