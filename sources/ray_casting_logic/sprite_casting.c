#include "main.h"

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

static void	init_sprite_distances(t_cub3D *mystruct)
{
	int	i;

	i = -1;
	while (++i < mystruct->n_of_sprites_on_map)
		mystruct->sprites[i].distance = (mystruct->posX - mystruct->sprites[i].posX)
			* (mystruct->posX - mystruct->sprites[i].posX) + (mystruct->posY
			- mystruct->sprites[i].posY) * (mystruct->posY - mystruct->sprites[i].posY);
}

void	sprite_casting(t_cub3D *mystruct)
{
	int						i;
	t_sprite_cast_params	p;
	int						stripe;

	init_sprite_distances(mystruct);
	sort_sprites(mystruct);
	i = -1;
	while (++i < mystruct->n_of_sprites_on_map)
	{
		if (mystruct->n_of_renders == 0)
			update_state_of_sprites(mystruct, i);
		ft_bzero(&p, sizeof(p));
		initialize_sprite_draw(mystruct, i, &p);
		// Loop through every vertical stripe of the sprite on screen
		stripe = p.drawStartX - 1;
		while (++stripe < p.drawEndX)
			draw_sprite_stripe(mystruct, i, stripe, &p);
	}
}
