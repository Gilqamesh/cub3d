#include "headers.h"

// The mask only works here if TEXTURE_W and TEXTURE_H is a power of 2
// (color >> 1) & 8355711
// The above code halves each color (RGB) by shifting to the right by 1 and then
// Setting the leftmost digit of each byte to 0
// Essentially shifting each byte by 1 to the right as a result
void	floor_casting(t_cub3D *mystruct)
{
	t_floor_cast_params	p;
	unsigned int	color;

	for (int y = 0; y < SCREEN_H; ++y)
	{
		initialize_floor_ray(mystruct, y, &p);
		for (int x = 0; x < SCREEN_W; ++x)
		{
			p.tx = (int)(TEXTURE_W * (p.floorX - (int)p.floorX)) & (TEXTURE_W - 1);
			p.ty = (int)(TEXTURE_H * (p.floorY - (int)p.floorY)) & (TEXTURE_H - 1);
			p.floorX += p.floorStepX;
			p.floorY += p.floorStepY;
			color = get_color(&mystruct->textures[FLOOR_TEXTURE], p.tx, p.ty);
			color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&mystruct->canvas, x, y, color);
			color = get_color(&mystruct->textures[CEILING_TEXTURE], p.tx, p.ty);
			color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&mystruct->canvas, x, SCREEN_H - y - 1, color);
		}
	}
}

void	initialize_floor_ray(t_cub3D *mystruct, int current_row, t_floor_cast_params *p)
{
	p->rowDistance = (mystruct->posZ) / (current_row - SCREEN_H / 2);
	p->floorStepX = p->rowDistance * 2.0 * mystruct->planeX / SCREEN_W;
	p->floorStepY = p->rowDistance * 2.0 * mystruct->planeY / SCREEN_W;
	p->floorX = mystruct->posX + p->rowDistance * mystruct->dirX - mystruct->planeX;
	p->floorY = mystruct->posY + p->rowDistance * mystruct->dirY - mystruct->planeY;
}
