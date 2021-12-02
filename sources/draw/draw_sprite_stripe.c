#include "main.h"

static void	draw_stripe(t_cub3D *mystruct, t_point i_y, int stripe,
t_sprite_cast_params *p)
{
	unsigned int	color;

	p->d = (i_y.y - p->vMoveScreen) * 256 - SCREEN_H * 128
		+ p->spriteHeight * 128;
	p->texY = (p->d * TEXT_H / p->spriteHeight) / 256;
	color = get_color(&mystruct->sprites[i_y.x].img[mystruct->sprites[i_y.x]
			.index_of_sprite], p->texX, p->texY);
	if (color != BLANK)
	{
		if (mystruct->sprites[i_y.x].translucency_factor > 1.0)
			mystruct->draw_buffer[i_y.y][stripe] = divide_color(
					mystruct->draw_buffer[i_y.y][stripe],
					mystruct->sprites[i_y.x].translucency_factor
					/ (mystruct->sprites[i_y.x].translucency_factor - 1.0))
				+ divide_color(color, mystruct->sprites[i_y.x]
					.translucency_factor);
		else
			mystruct->draw_buffer[i_y.y][stripe] = color;
	}
}

// The conditions in the if are:
// 	1) it's in front of camera plane so you don't see things behind you
// 	2) it's on the screen (left)
// 	3) it's on the screen (right)
// 	4) ZBuffer, with perpendicular distance
// Then for every pixel of the current stripe:
//	256 and 128 factors to avoid floats
//	get current color from the texture
//	draw colors that aren't transparent
void	draw_sprite_stripe(t_cub3D *mystruct, int i, int stripe,
t_sprite_cast_params *p)
{
	int				y;

	p->texX = (int)(256 * (stripe - (-p->spriteWidth / 2 + p->spriteScreenX))
			* TEXT_W / p->spriteWidth) / 256;
	if (p->transformY > 0 && stripe > 0 && stripe < SCREEN_W
		&& p->transformY < mystruct->ZBuffer[stripe])
	{
		y = p->drawStartY - 1;
		while (++y < p->drawEndY)
			draw_stripe(mystruct, (t_point){i, y}, stripe, p);
	}
}
