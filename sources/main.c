#include "main.h"

int	main(int argc, char **argv)
{
	t_cub3D	mystruct;

	ft_get_ptr(&mystruct);
	ft_input_parse(argc, argv, &mystruct);
	init_struct(&mystruct);
	init_hooks(&mystruct);
	mlx_loop(mystruct.vars.mlx);
	return (exit_program(STDOUT_FILENO, "Program terminated naturally"));
}
