#include "main.h"

static void	merge_sort_sprite_copy(t_sprite *in, t_2_int start_end_indexes,
t_sprite *out)
{
	int	i;

	i = start_end_indexes.a - 1;
	while (++i < start_end_indexes.b)
		out[i] = in[i];
}

static void	merge_sort_sprite_comb(t_sprite *in, t_3_int start_mid_end_indexes,
t_sprite *out)
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

void	sort_sprites(t_cub3D *mystruct)
{
	t_sprite	*helper;

	helper = malloc(mystruct->n_of_sprites_on_map * sizeof(*helper));
	if (helper == NULL)
		exit_program(mystruct);
	merge_sort_sprite(mystruct->sprites,
		(t_2_int){0, mystruct->n_of_sprites_on_map}, helper);
	free(helper);
}
