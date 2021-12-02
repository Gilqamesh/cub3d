#include "main.h"

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
	unsigned int	color;

	p->texX = (int)(256 * (stripe - (-p->spriteWidth / 2 + p->spriteScreenX)) * TEXT_W / p->spriteWidth) / 256;
	if (p->transformY > 0 && stripe > 0 && stripe < SCREEN_W && p->transformY < mystruct->ZBuffer[stripe])
	{
		y = p->drawStartY - 1;
		// For every pixel of the current stripe
		while (++y < p->drawEndY)
		{
			// 256 and 128 factors to avoid floats
			p->d = (y - p->vMoveScreen) * 256 - SCREEN_H * 128 + p->spriteHeight * 128;
			p->texY = (p->d * TEXT_H / p->spriteHeight) / 256;
			// Get current color from the texture
			color = get_color(&mystruct->sprites[i].img[mystruct->sprites[i].index_of_sprite],
				p->texX, p->texY);
			if (color != BLANK)
			{
				if (mystruct->sprites[i].translucency_factor > 1.0)
					mystruct->draw_buffer[y][stripe] = divide_color(
						mystruct->draw_buffer[y][stripe],
						mystruct->sprites[i].translucency_factor
						/ (mystruct->sprites[i].translucency_factor - 1.0))
						+ divide_color(color, mystruct->sprites[i]
						.translucency_factor);
				else
					mystruct->draw_buffer[y][stripe] = color;
			}
		}
	}
}
