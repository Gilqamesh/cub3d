#include "main.h"

// The mask only works here if TEXT_W and TEXT_H is a power of 2
// (color >> 1) & 8355711
// The above code halves each color (RGB) by shifting to the right by 1 and then
// Setting the leftmost digit of each byte to 0
// Essentially shifting each byte by 1 to the right as a result
void	floor_casting(t_cub3D *mystruct)
{
	t_floor_cast_params	p;

	for (int y = 0; y < SCREEN_H; ++y)
	{
		initialize_floor_ray(mystruct, y, &p);
		for (int x = 0; x < SCREEN_W; ++x)
		{
			p.tx = (int)(TEXT_W * (p.floorX - (int)p.floorX)) & (TEXT_W - 1);
			p.ty = (int)(TEXT_H * (p.floorY - (int)p.floorY)) & (TEXT_H - 1);
			p.floorX += p.floorStepX;
			p.floorY += p.floorStepY;
			mystruct->draw_buffer[y][x] = mystruct->parse.F;
			mystruct->draw_buffer[SCREEN_H - y - 1][x] = mystruct->parse.C;
		}
	}
}

void	initialize_floor_ray(t_cub3D *mystruct, int current_row, t_floor_cast_params *p)
{
	p->rowDistance = current_row == SCREEN_H / 2 ? INFINITY
		: (mystruct->posZ) / (current_row - SCREEN_H / 2);
	p->floorStepX = p->rowDistance * 2.0 * mystruct->planeX / SCREEN_W;
	p->floorStepY = p->rowDistance * 2.0 * mystruct->planeY / SCREEN_W;
	p->floorX = mystruct->posX + p->rowDistance * (mystruct->dirX - mystruct->planeX);
	p->floorY = mystruct->posY + p->rowDistance * (mystruct->dirY - mystruct->planeY);
}
