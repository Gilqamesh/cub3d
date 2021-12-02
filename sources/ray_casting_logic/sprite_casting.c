#include "main.h"

static void	init_sprite_distances(t_cub3D *mystruct)
{
	int	i;

	i = -1;
	while (++i < mystruct->n_of_sprites_on_map)
		mystruct->sprites[i].distance
			= (mystruct->posX - mystruct->sprites[i].posX)
			* (mystruct->posX - mystruct->sprites[i].posX)
			+ (mystruct->posY - mystruct->sprites[i].posY)
			* (mystruct->posY - mystruct->sprites[i].posY);
}

// Loop through every vertical stripe of the sprite on screen
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
		stripe = p.drawStartX - 1;
		while (++stripe < p.drawEndX)
			draw_sprite_stripe(mystruct, i, stripe, &p);
	}
}
