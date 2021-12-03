#include "main.h"

t_map	*ft_map_to_ll(t_cub3D *mystruct)
{
	t_map	*map;

	map = ft_lstmallocwrapper(&mystruct->alloced_memory, sizeof(t_map), false);
	if (map == NULL)
		exit_program(STDERR_FILENO, "malloc failed in file %s in function "\
		"ft_map_to_ll\n", __FILE__);
	map->map_line = ft_strdup(mystruct->parse.line);
	ft_lstadd_front(&mystruct->alloced_memory, ft_lstnew(map->map_line));
	map->next = NULL;
	return (map);
}

void	ft_gnl_to_ll(t_cub3D *mystruct)
{
	t_map	*tmp;

	if (mystruct->parse.map_width < (int)ft_strlen(mystruct->parse.line))
		mystruct->parse.map_width = (int)ft_strlen(mystruct->parse.line);
	mystruct->parse.map_height += 1;
	tmp = ft_map_to_ll(mystruct);
	tmp->next = mystruct->parse.map;
	mystruct->parse.map = tmp;
}

void	ft_map_parse(t_cub3D *mystruct)
{
	while (get_next_line(mystruct->parse.fd, &mystruct->parse.line) != 0)
	{
		ft_map_char_checker(mystruct, mystruct->parse.line);
		ft_gnl_to_ll(mystruct);
		free(mystruct->parse.line);
	}
	if (ft_strlen(mystruct->parse.line) == 0)
		exit_program(STDERR_FILENO, "map should not end with a newline\n");
	else
		ft_gnl_to_ll(mystruct);
	free(mystruct->parse.line);
}

void	ft_extension_checker(int argc, char **argv)
{
	if (argc != 2)
		exit_program(STDERR_FILENO, "run program by entering <./cub3D "\
		"./map/map.cub>\n", __FILE__);
	else if (ft_strlen(argv[1]) < 4)
		exit_program(STDERR_FILENO, "%s is not a valid map(path) \n",
			argv[1]);
	else if (!(argv[1][ft_strlen(argv[1]) - 4] == '.'
		&& argv[1][ft_strlen(argv[1]) - 3] == 'c'
		&& argv[1][ft_strlen(argv[1]) - 2] == 'u'
		&& argv[1][ft_strlen(argv[1]) - 1] == 'b'))
		exit_program(STDERR_FILENO, "%s should have .cub as extension\n",
			argv[1]);
}

void	ft_input_parse(int argc, char **argv, t_cub3D *mystruct)
{
	ft_extension_checker(argc, argv);
	ft_bzero(mystruct, sizeof(*mystruct));
	mystruct->parse.fd = open(argv[1], O_RDONLY);
	if (mystruct->parse.fd == -1)
		exit_program(STDERR_FILENO, "error opening map file %d\n",
			argv[1]);
	while (get_next_line(mystruct->parse.fd, &mystruct->parse.line)
		> 0 && mystruct->parse.full == 0)
	{
		ft_texture_color_parse(mystruct);
		free(mystruct->parse.line);
	}
	free(mystruct->parse.line);
	if (mystruct->parse.full != 1)
	{
		close (mystruct->parse.fd);
		exit_program(STDERR_FILENO, "map file does not contain \n"
			"NO, SO, WE, EA, F and C\n");
	}
	ft_map_parse(mystruct);
	ft_ll_to_2d(mystruct);
	ft_map_checker(mystruct);
	mystruct->map_width = mystruct->parse.map_width;
	mystruct->map_height = mystruct->parse.map_height;
	close(mystruct->parse.fd);
}
