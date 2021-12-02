#ifndef SPRITE_CASTING_H
# define SPRITE_CASTING_H

# include "struct.h"

typedef struct s_sprite_cast_params
{
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		vMoveScreen;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		texX;
	int		texY;
	int		d;
}	t_sprite_cast_params;

void	sprite_casting(t_cub3D *mystruct);

#endif /* SPRITE_CASING_H */
