#include "headers.h"

void	destroy_struct(t_cub3D *mystruct)
{
	int	i;

	i = -1;
	while (++i < mapHeight)
		free(mystruct->map[i]);
	free(mystruct->map);
}
