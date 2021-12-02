#include "main.h"

t_map	*ft_map_to_ll(t_cub3D *mystruct)
{
	t_map	*map;
	char	*temp;

	map = malloc(sizeof(t_map));
	temp = ft_strdup(mystruct->parse.line);
	if (map == NULL)
		ft_error_message("Malloc Failed\n");
	map->map_line = temp;
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
		ft_error_message("Wrong input\n");
	else
		ft_gnl_to_ll(mystruct);
	free(mystruct->parse.line);
}

void	ft_extension_checker(int argc, char **argv)
{
	if (argc != 2)
		ft_error_message("Wrong input\n");
	else if (ft_strlen(argv[1]) < 4)
		ft_error_message("Wrong input\n");
	else if (!(argv[1][ft_strlen(argv[1]) - 4] == '.'
		&& argv[1][ft_strlen(argv[1]) - 3] == 'c'
		&& argv[1][ft_strlen(argv[1]) - 2] == 'u'
		&& argv[1][ft_strlen(argv[1]) - 1] == 'b'))
		ft_error_message("Wrong input\n");
}

void	ft_input_parse(int argc, char **argv, t_cub3D *mystruct)
{
	ft_extension_checker(argc, argv);
	ft_bzero(mystruct, sizeof(*mystruct));
	mystruct->parse.fd = open(argv[1], O_RDONLY);
	if (mystruct->parse.fd == -1)
		exit(EXIT_FAILURE);
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
		ft_error_message("Wrong input\n");
	}
	ft_map_parse(mystruct);
	ft_ll_to_2d(mystruct);
	ft_map_checker(mystruct);
	mystruct->map_width = mystruct->parse.map_width;
	mystruct->map_height = mystruct->parse.map_height;
	close(mystruct->parse.fd);
}
