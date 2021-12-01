#include "main.h"

void	ft_print_linked_list(t_cub3D *mystruct)
{
	t_map	*temporary;

	temporary = mystruct->parse.map;
	while (temporary != NULL)
	{
		printf("%s\n", temporary->map_line);
		temporary = temporary->next;
	}
	printf("\n");
}

void	ft_struct_printer(t_cub3D *mystruct)
{
	printf("NO: %s\n", mystruct->parse.NO);
	printf("SO: %s\n", mystruct->parse.SO);
	printf("WE: %s\n", mystruct->parse.WE);
	printf("EA: %s\n\n", mystruct->parse.EA);
	printf("F: %d\n", mystruct->parse.F);
	printf("C: %d\n\n", mystruct->parse.C);
	printf("Map Width: %d\n", mystruct->parse.map_width);
	printf("Map Height: %d\n\n", mystruct->parse.map_height);
	printf("Full: %d\n", mystruct->parse.full);
	printf("2D Array: %s\n\n", mystruct->map[13]);
	ft_print_linked_list(mystruct);
}

void	ft_error_message(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	ft_digit_finder(char *line)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line) && line[i] != '\0')
	{
		if (ft_isdigit((int)line[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_last_x_finder(char *line, char x)
{
	int	i;

	i = (int)ft_strlen(line);
	while (i > 0)
	{
		if (line[i] == x)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_first_x_finder(char *line, char x)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line) && line[i] != '\0')
	{
		if (line[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_map_checker2(t_cub3D *mystruct)
{
	int	i;

	i = 0;
	while (i < mystruct->parse.map_width)
	{
		if (mystruct->map[0][i] != '*'
			&& mystruct->map[0][i] != '1')
			ft_error_message("Wrong input\n");
		if (mystruct->map[mystruct->parse.map_height - 1][i] != '*'
			&& mystruct->map[mystruct->parse.map_height - 1][i] != '1')
			ft_error_message("Wrong input\n");
		i++;
	}
	i = 0;
	while (i < mystruct->parse.map_height)
	{
		if (mystruct->map[i][0] != '*'
			&& mystruct->map[i][0] != '1')
			ft_error_message("Wrong input\n");
		if (mystruct->map[i][mystruct->parse.map_width - 1] != '*'
			&& mystruct->map[i][mystruct->parse.map_width - 1] != '1')
			ft_error_message("Wrong input\n");
		i++;
	}
}

void	ft_map_checker(t_cub3D *mystruct)
{
	ft_map_checker2(mystruct);
	while (mystruct->parse.row < mystruct->parse.map_height)
	{
		mystruct->parse.col = 0;
		while (mystruct->parse.col < mystruct->parse.map_width)
		{
			if (mystruct->map[mystruct->parse.row][mystruct->parse.col] == '*')
			{
				if (mystruct->parse.row != 0)
					ft_element_check(mystruct, -1, 0);
				if (mystruct->parse.row != mystruct->parse.map_height - 1)
					ft_element_check(mystruct, 1, 0);
				if (mystruct->parse.col != 0)
					ft_element_check(mystruct, 0, -1);
				if (mystruct->parse.col != mystruct->parse.map_width - 1)
					ft_element_check(mystruct, 0, 1);
			}
			mystruct->parse.col += 1;
		}
		mystruct->parse.row += 1;
	}
}

void	ft_color_error_checker(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (!(line[i] == ',' || ft_isdigit(line[i])))
			ft_error_message("Wrong input\n");
		i++;
	}
}

void	ft_rgb_to_dec(char *line, int *f_or_c)
{
	int	i;

	ft_color_error_checker(line);
	i = ft_digit_finder(line);
	if (ft_atoi(&line[i]) > 255)
		ft_error_message("Wrong input\n");
	*f_or_c += ft_atoi(&line[i]) << 16;
	i += ft_intlen(ft_atoi(&line[i])) + 1;
	if (ft_isdigit((int)line[i]))
	{
		if (ft_atoi(&line[i]) > 255)
			ft_error_message("Wrong input\n");
		*f_or_c += ft_atoi(&line[i]) << 8;
	}
	i = ft_last_x_finder(line, ',') + 1;
	if (ft_isdigit((int)line[i]))
	{
		if (ft_atoi(&line[i]) > 255)
			ft_error_message("Wrong input\n");
		*f_or_c += ft_atoi(&line[i]);
	}
}

void	ft_color_parser(char *line, t_cub3D *mystruct)
{
	if (line[0] == 'F' && mystruct->parse.f_full == 1)
		ft_error_message("Wrong input\n");
	if (line[0] == 'F' && mystruct->parse.f_full == 0)
	{
		ft_rgb_to_dec(line, &mystruct->parse.F);
		mystruct->parse.f_full = 1;
	}
	if (line[0] == 'C' && mystruct->parse.c_full == 1)
		ft_error_message("Wrong input\n");
	if (line[0] == 'C' && mystruct->parse.c_full == 0)
	{
		ft_rgb_to_dec(line, &mystruct->parse.C);
		mystruct->parse.c_full = 1;
	}
}

void	ft_texture_parser(char *line, t_cub3D *mystruct)
{
	if (ft_first_x_finder(line, '.') != -1)
	{
		if (line[0] == 'N' && line[1] == 'O' && mystruct->parse.no_full == 0)
		{
			mystruct->parse.NO = &line[ft_first_x_finder(line, '.')];
			mystruct->parse.no_full = 1;
		}
		if (line[0] == 'S' && line[1] == 'O' && mystruct->parse.so_full == 0)
		{
			mystruct->parse.SO = &line[ft_first_x_finder(line, '.')];
			mystruct->parse.so_full = 1;
		}
		if (line[0] == 'W' && line[1] == 'E' && mystruct->parse.we_full == 0)
		{
			mystruct->parse.WE = &line[ft_first_x_finder(line, '.')];
			mystruct->parse.we_full = 1;
		}
		if (line[0] == 'E' && line[1] == 'A' && mystruct->parse.ea_full == 0)
		{
			mystruct->parse.EA = &line[ft_first_x_finder(line, '.')];
			mystruct->parse.ea_full = 1;
		}
	}
}

void	ft_different_line_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
		&& str[i] != 'E' && str[i] != 'F' && str[i] != 'C'
		&& str[i] != '\n' && str[i] != '\0')
		ft_error_message("Wrong input\n");
}

void	ft_texture_color_parse(t_cub3D *mystruct)
{
	ft_different_line_checker(mystruct->parse.line);
	ft_texture_parser(mystruct->parse.line, mystruct);
	ft_color_parser(mystruct->parse.line, mystruct);
	if (mystruct->parse.NO != NULL && mystruct->parse.SO != NULL
		&& mystruct->parse.WE != NULL && mystruct->parse.EA != NULL
		&& mystruct->parse.c_full == 1 && mystruct->parse.f_full == 1)
		mystruct->parse.full = 1;
}

void	ft_map_char_checker(t_cub3D *mystruct, char *str)
{
	int	i;

	i = 0;
	while (i < mystruct->parse.map_width && str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != '0' && str[i] != 'T' && str[i] != 'o'
			&& str[i] != 'd' && str[i] != '\t' && str[i] != '\n')
			ft_error_message("Wrong input\n");
		i++;
	}
}

void	ft_element_check(t_cub3D *mystruct, int y, int x)
{
	if (mystruct->map[mystruct->parse.row + y][mystruct->parse.col + x] != '*'
		&& mystruct->map[mystruct->parse.row + y]
				[mystruct->parse.col + x] != '1')
		ft_error_message("Wrong input\n");
}

void	ft_one_line_2d(t_cub3D *mystruct, char *map_line)
{
	int	i;
	int	j;
	int	index;

	j = 0;
	mystruct->map[mystruct->parse.i] = malloc((mystruct->parse.map_width + 1)
			* sizeof(char));
	index = 0;
	while (j < (int)ft_strlen(map_line))
	{
		if (map_line[j] == '\t')
		{
			i = -1;
			while (++i < 4)
				mystruct->map[mystruct->parse.i][index++] = '*';
		}
		else if (map_line[j] == ' ')
			mystruct->map[mystruct->parse.i][index++] = '*';
		else
			mystruct->map[mystruct->parse.i][index++] = map_line[j];
		++j;
	}
	while (index < mystruct->parse.map_width)
		mystruct->map[mystruct->parse.i][index++] = '*';
	mystruct->map[mystruct->parse.i][index] = '\0';
}

void	ft_ll_to_2d(t_cub3D *mystruct)
{
	t_map	*temporary;

	mystruct->map = malloc((mystruct->parse.map_height + 1) * sizeof(char *));
	temporary = mystruct->parse.map;
	mystruct->parse.i = mystruct->parse.map_height;
	mystruct->map[mystruct->parse.i] = NULL;
	while (temporary != NULL)
	{
		mystruct->parse.i -= 1;
		ft_one_line_2d(mystruct, temporary->map_line);
		temporary = temporary->next;
	}
}

t_map	*ft_map_to_ll(t_cub3D *mystruct)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->map_line = mystruct->parse.line;
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
	}
	if (ft_strlen(mystruct->parse.line) == 0)
		ft_error_message("Wrong input\n");
	else
		ft_gnl_to_ll(mystruct);
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
		ft_texture_color_parse(mystruct);
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
	//ft_struct_printer(mystruct);
	//exit(1);
	//Double line containing NO SO WE EA -> error
}
