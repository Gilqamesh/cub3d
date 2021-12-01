#include "main.h"

int	main(int argc, char **argv)
{
	t_cub3D			mystruct;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <map_name.cub>", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_input_parse(argc, argv, &mystruct);
	init_struct(&mystruct);
	// build_tree();
	install_hooks(&mystruct);
	mlx_loop(mystruct.vars.mlx);
	destroy_struct(&mystruct);
}
