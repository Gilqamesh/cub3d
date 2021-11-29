#include "headers.h"

int	main(int argc, char **argv)
{
	t_cub3D			mystruct;
	t_input_parse 	parse;

	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <map_name.cub>", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_bzero(&mystruct, sizeof(mystruct));
	// ft_input_parse(argc, argv, &parse);
	init_struct(&mystruct, &parse);
	// build_tree();
	install_hooks(&mystruct);
	mlx_loop(mystruct.vars.mlx);
	destroy_struct(&mystruct);
}
