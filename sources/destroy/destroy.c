#include "main.h"

void	destroy_struct(t_cub3D *mystruct)
{
	int	i;

	i = -1;
	while (++i < mystruct->map_height)
		free(mystruct->map[i]);
	free(mystruct->map);
}
