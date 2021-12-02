#include "main.h"

static int	get_wall_texture(t_wall_cast_params *p)
{
	if (p->side == VERTICAL_SIDE)
	{
		if (p->stepY == 1)
			return (TEXT_N_WALL);
		else
			return (TEXT_S_WALL);
	}
	if (p->stepX == 1)
		return (TEXT_E_WALL);
	else
		return (TEXT_W_WALL);
}

// Calculate where the wall was hit (wallX)
// X coordinate of the texture (texX)
// How much to increase the texture coordinate per screen pixel (step)
// Starting texture coordinate (texPos)
// Each iteration:
// Cast the texture coordinate to integer, and mask with (texHeight - 1)
//		in case of overflow (texY)
// Get color from the texture and draw the pixel
// make color darker for y-sides: R, G and B byte each divided through two
//		with a "shift" and an "and"
// if (p->side == 1)
// 	color = (color >> 1) & 8355711;
void	draw_wall(t_cub3D *mystruct, int current_column, t_wall_cast_params *p)
{
	t_draw_wall_params	w;
	int					texture_index;

	if (p->side == 0)
		w.wallX = mystruct->posY + p->perpWallDist * p->rayDirY;
	else
		w.wallX = mystruct->posX + p->perpWallDist * p->rayDirX;
	w.wallX -= floor(w.wallX);
	w.texX = (int)(w.wallX * TEXT_W);
	if ((p->side == HORIZONTAL_SIDE && p->rayDirX > 0)
		|| (p->side == VERTICAL_SIDE && p->rayDirY < 0))
		w.texX = TEXT_W - w.texX - 1;
	w.step = (double)TEXT_H / p->lineHeight;
	w.texPos = (p->drawStart + (p->lineHeight - SCREEN_H) / 2.0) * w.step;
	texture_index = TEXTURE_DOOR;
	if (p->hit == WALL_CHAR)
		texture_index = get_wall_texture(p);
	for (int y = p->drawStart; y < p->drawEnd; ++y)
	{
		w.texY = (int)w.texPos & (TEXT_H - 1);
		w.texPos += w.step;
		w.color = get_color(&mystruct->textures[texture_index], w.texX, w.texY);
		mystruct->draw_buffer[y][current_column] = w.color;
	}
}
