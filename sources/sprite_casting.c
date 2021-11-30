#include "headers.h"

static void	merge_sort_sprite_copy(t_sprite *in, t_2_int start_end_indexes,
t_sprite *out)
{
	int	i;

	i = start_end_indexes.a - 1;
	while (++i < start_end_indexes.b)
		out[i] = in[i];
}

static void	merge_sort_sprite_comb(t_sprite *in, t_3_int start_mid_end_indexes, t_sprite *out)
{
	int	i;
	int	j;
	int	k;

	i = start_mid_end_indexes.a;
	j = start_mid_end_indexes.b;
	k = i - 1;
	while (++k < start_mid_end_indexes.c)
	{
		if (i < start_mid_end_indexes.b && (j >= start_mid_end_indexes.c
				|| in[i].distance <= in[j].distance))
		{
			out[k] = in[i];
			i++;
		}
		else
		{
			out[k] = in[j];
			j++;
		}
	}
}

static void	merge_sort_sprite(t_sprite *array, t_2_int start_end_indexes,
t_sprite *helper_array)
{
	int	middle;

	if (start_end_indexes.b - start_end_indexes.a < 2)
		return ;
	middle = (start_end_indexes.a + start_end_indexes.b) / 2;
	merge_sort_sprite(array, (t_2_int){start_end_indexes.a, middle},
		helper_array);
	merge_sort_sprite(array, (t_2_int){middle, start_end_indexes.b},
		helper_array);
	merge_sort_sprite_comb(array, (t_3_int){start_end_indexes.a, middle,
		start_end_indexes.b}, helper_array);
	merge_sort_sprite_copy(helper_array, (t_2_int){start_end_indexes.a,
		start_end_indexes.b}, array);
}


static void	sort_sprites(t_cub3D *mystruct)
{
	t_sprite	*helper;

	helper = malloc(mystruct->n_of_sprites_on_map * sizeof(*helper));
	merge_sort_sprite(mystruct->sprites, (t_2_int){0, mystruct->n_of_sprites_on_map}, helper);
	free(helper);
}

void	sprite_casting(t_cub3D *mystruct)
{
	for (int i = 0; i < mystruct->n_of_sprites_on_map; ++i)
	{
		mystruct->sprites[i].distance = (mystruct->posX - mystruct->sprites[i].posX)
			* (mystruct->posX - mystruct->sprites[i].posX) + (mystruct->posY
			- mystruct->sprites[i].posY) * (mystruct->posY - mystruct->sprites[i].posY);
	}
	sort_sprites(mystruct);

	for (int i = 0; i < mystruct->n_of_sprites_on_map; ++i)
	{
		// Change state of sprites for animation
		if (mystruct->n_of_renders == 0 && mystruct->sprites[i].name == SPRITE_GOGGLE)
			if (++mystruct->sprites[i].index_of_sprite == 8)
				mystruct->sprites[i].index_of_sprite = 0;

		// Translate sprite position to relative to camera
		double	spriteX = mystruct->sprites[i].posX - mystruct->posX;
		double	spriteY = mystruct->sprites[i].posY - mystruct->posY;

		// Transform sprite with the inverse camera matrix
		// Required for correct matrix multiplication
		double	invDet = 1.0 / (mystruct->planeX * mystruct->dirY - mystruct->dirX * mystruct->planeY);

		// This is actually the depth inside the screen, that what Z is in 3D
		double	transformX = invDet * (mystruct->dirY * spriteX - mystruct->dirX * spriteY);
		double	transformY = invDet * (-mystruct->planeY * spriteX + mystruct->planeX * spriteY);

		int		spriteScreenX = (int)(SCREEN_W / 2.0 * (1 + transformX / transformY));

		// Calculate height of the sprite on screen
		// Using 'transformY' instead of the real distance prevents fisheye
		int		spriteHeight = ft_fabs((int)(SCREEN_H / transformY));
		// Calculate lowest and highest pixel to fill in current stripe
		int		drawStartY = -spriteHeight / 2.0 + SCREEN_H / 2.0;
		if (drawStartY < 0)
			drawStartY = 0;
		int		drawEndY = spriteHeight / 2.0 + SCREEN_H / 2.0;
		if (drawEndY >= SCREEN_H)
			drawEndY = SCREEN_H - 1;

		// Calculate width of the sprite
		int		spriteWidth = ft_fabs((int)(SCREEN_H) / transformY);
		int		drawStartX = -spriteWidth / 2.0 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		int		drawEndX = spriteWidth / 2.0 + spriteScreenX;
		if (drawEndX >= SCREEN_W)
			drawEndX = SCREEN_W - 1;

		// Loop through every vertical stripe of the sprite on screen
		for (int stripe = drawStartX; stripe < drawEndX; ++stripe)
		{
			int	texX = (int)(256 * (stripe - (-spriteWidth / 2.0 + spriteScreenX)) * TEXTURE_W / spriteWidth) / 256;
			// The conditions in the if are:
			// 1) it's in front of camera plane so you don't see things behind you
			// 2) it's on the screen (left)
			// 3) it's on the screen (right)
			// 4) ZBuffer, with perpendicular distance
			if (transformY > 0 && stripe > 0 && stripe < SCREEN_W && transformY < mystruct->ZBuffer[stripe])
			{
				// For every pixel of the current stripe
				for (int y = drawStartY; y < drawEndY; ++y)
				{
					// 256 and 128 factors to avoid floats
					int				d = y * 256 - SCREEN_H * 128 + spriteHeight * 128;
					int				texY = (d * TEXTURE_H / (double)spriteHeight) / 256;
					// Get current color from the texture
					unsigned int	color = get_color(&mystruct->sprites[i].img[mystruct->sprites[i].index_of_sprite],
						texX, texY);
					if ((color & 0x00ffffff) != 0)
						my_mlx_pixel_put(&mystruct->canvas, stripe, y, color);
				}
			}
		}
	}
}
