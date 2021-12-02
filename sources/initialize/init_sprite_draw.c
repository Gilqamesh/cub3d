#include "main.h"

void	initialize_sprite_draw(t_cub3D *mystruct, int i,
t_sprite_cast_params *p)
{
	// Translate sprite position to relative to camera
	p->spriteX = mystruct->sprites[i].posX - mystruct->posX;
	p->spriteY = mystruct->sprites[i].posY - mystruct->posY;

	// Transform sprite with the inverse camera matrix
	// Required for correct matrix multiplication
	p->invDet = 1.0 / (mystruct->planeX * mystruct->dirY - mystruct->dirX * mystruct->planeY);

	// This is actually the depth inside the screen, that what Z is in 3D
	p->transformX = p->invDet * (mystruct->dirY * p->spriteX - mystruct->dirX * p->spriteY);
	p->transformY = p->invDet * (-mystruct->planeY * p->spriteX + mystruct->planeX * p->spriteY);

	p->spriteScreenX = (int)(SCREEN_W / 2 * (1 + p->transformX / p->transformY));

	// Calculate height of the sprite on screen
	// Using 'transformY' instead of the real distance prevents fisheye
	p->spriteHeight = ft_fabs((int)(SCREEN_H / p->transformY)) / mystruct->sprites[i].vDiv;

	// Calculate lowest and highest pixel to fill in current stripe
	p->vMoveScreen = mystruct->sprites[i].vMove / p->transformY;
	p->drawStartY = -p->spriteHeight / 2 + SCREEN_H / 2 + p->vMoveScreen;
	if (p->drawStartY < 0)
		p->drawStartY = 0;
	p->drawEndY = p->spriteHeight / 2 + SCREEN_H / 2 + p->vMoveScreen;
	if (p->drawEndY >= SCREEN_H)
		p->drawEndY = SCREEN_H - 1;

	// Calculate width of the sprite
	p->spriteWidth = ft_fabs((int)(SCREEN_H / p->transformY)) / mystruct->sprites[i].uDiv;
	p->drawStartX = -p->spriteWidth / 2 + p->spriteScreenX;
	if (p->drawStartX < 0)
		p->drawStartX = 0;
	p->drawEndX = p->spriteWidth / 2 + p->spriteScreenX;
	if (p->drawEndX >= SCREEN_W)
		p->drawEndX = SCREEN_W - 1;
}
