#include "main.h"

static void	limit_iterators(t_sprite_cast_params *p)
{
	if (p->drawStartY < 0)
		p->drawStartY = 0;
	if (p->drawEndY >= SCREEN_H)
		p->drawEndY = SCREEN_H - 1;
	if (p->drawStartX < 0)
		p->drawStartX = 0;
	if (p->drawEndX >= SCREEN_W)
		p->drawEndX = SCREEN_W - 1;
}

// 1) Translate sprite position to relative to camera
// 2) Transform sprite with the inverse camera matrix
//		invDet is required for correct matrix multiplication
// 3) transformX and Y is the depth inside the screen, that's what Z is in 3D
// 4) Calculate height of the sprite on screen
//		using 'transformY' instead of the real distance prevents fisheye
// 5) drawStart/End calculate lowest and highest pixel to fill in current stripe
// 6) spriteWidth calculate width of the sprite
void	initialize_sprite_draw(t_cub3D *mystruct, int i,
t_sprite_cast_params *p)
{
	p->spriteX = mystruct->sprites[i].posX - mystruct->posX;
	p->spriteY = mystruct->sprites[i].posY - mystruct->posY;
	p->invDet = 1.0 / (mystruct->planeX * mystruct->dirY
			- mystruct->dirX * mystruct->planeY);
	p->transformX = p->invDet * (mystruct->dirY * p->spriteX
			- mystruct->dirX * p->spriteY);
	p->transformY = p->invDet * (-mystruct->planeY * p->spriteX
			+ mystruct->planeX * p->spriteY);
	p->spriteHeight = ft_fabs((int)(SCREEN_H / p->transformY))
		/ mystruct->sprites[i].vDiv;
	p->vMoveScreen = mystruct->sprites[i].vMove / p->transformY;
	p->drawStartY = -p->spriteHeight / 2 + SCREEN_H / 2 + p->vMoveScreen;
	p->drawEndY = p->spriteHeight / 2 + SCREEN_H / 2 + p->vMoveScreen;
	p->spriteWidth = ft_fabs((int)(SCREEN_H / p->transformY))
		/ mystruct->sprites[i].uDiv;
	p->spriteScreenX = (int)(SCREEN_W / 2
			* (1 + p->transformX / p->transformY));
	p->drawStartX = -p->spriteWidth / 2 + p->spriteScreenX;
	p->drawEndX = p->spriteWidth / 2 + p->spriteScreenX;
	limit_iterators(p);
}
