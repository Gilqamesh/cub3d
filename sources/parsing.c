#include "headers.h"

void	ft_print_linked_list(t_input_parse *parse)
{
	t_map	*temporary;

	temporary = parse->map;
	while (temporary != NULL)
	{
		printf("%s\n", temporary->map_line);
		temporary = temporary->next;
	}
	printf("\n");
}

void	ft_struct_printer(t_input_parse *parse)
{
	printf("NO: %s\n", parse->NO);
	printf("SO: %s\n", parse->SO);
	printf("WE: %s\n", parse->WE);
	printf("EA: %s\n\n", parse->EA);
	printf("F: %d\n", parse->F);
	printf("C: %d\n\n", parse->C);
	printf("Map Width: %d\n", parse->map_width);
	printf("Map Height: %d\n\n", parse->map_height);
	printf("Full: %d\n", parse->full);
	printf("2D Array: %s\n\n", parse->two_d_array[13]);
	ft_print_linked_list(parse);
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

void	ft_rgb_to_dec(char *line, int *f_or_c)
{
	int	i;

	i = ft_digit_finder(line);
	*f_or_c += ft_atoi(&line[i]) << 16;
	i += ft_intlen(ft_atoi(&line[i])) + 1;
	if (ft_isdigit((int)line[i]))
		*f_or_c += ft_atoi(&line[i]) << 8;
	i = line[ft_last_x_finder(line, ',') + 1];
	if (ft_isdigit((int)line[i]))
		*f_or_c += ft_atoi(&line[i]);
}

void	ft_color_parser(char *line, t_input_parse *parse)
{
	if (line[0] == 'F')
		ft_rgb_to_dec(line, &parse->F);
	if (line[0] == 'C')
		ft_rgb_to_dec(line, &parse->C);
}

void	ft_texture_parser(char *line, t_input_parse *parse)
{
	if (ft_first_x_finder(line, '.') != -1)
	{
		if (line[0] == 'N' && line[1] == 'O')
			parse->NO = &line[ft_first_x_finder(line, '.')];
		if (line[0] == 'S' && line[1] == 'O')
			parse->SO = &line[ft_first_x_finder(line, '.')];
		if (line[0] == 'W' && line[1] == 'E')
			parse->WE = &line[ft_first_x_finder(line, '.')];
		if (line[0] == 'E' && line[1] == 'A')
			parse->EA = &line[ft_first_x_finder(line, '.')];
	}
}

void	ft_map_checker2(t_input_parse *parse)
{
	int	i;

	i = 0;
	while (i < parse->map_width)
	{
		if (parse->two_d_array[0][i] != '*'
			&& parse->two_d_array[0][i] != '1')
				ft_error_message("Wrong input\n");
		if (parse->two_d_array[parse->map_height - 1][i] != '*'
			&& parse->two_d_array[parse->map_height - 1][i] != '1')
				ft_error_message("Wrong input\n");
		i++;
	}
	i = 0;
	while (i < parse->map_height)
	{
		if (parse->two_d_array[i][0] != '*'
			&& parse->two_d_array[i][0] != '1')
				ft_error_message("Wrong input\n");
		if (parse->two_d_array[i][parse->map_width - 1] != '*'
			&& parse->two_d_array[i][parse->map_width - 1] != '1')
				ft_error_message("Wrong input\n");
		i++;
	}
}

void	ft_element_check(t_input_parse *parse, int y, int x)
{
	if (parse->two_d_array[parse->row + y][parse->col + x] != '*'
		&& parse->two_d_array[parse->row + y][parse->col + x] != '1')
			ft_error_message("Wrong input\n");
}

void	ft_map_checker(t_input_parse *parse)
{
	ft_map_checker2(parse);
	while (parse->row < parse->map_height)
	{
		parse->col = 0;
		while (parse->col < parse->map_width)
		{
			if (parse->two_d_array[parse->row][parse->col] == '*')
			{
				if (parse->row != 0)
					ft_element_check(parse, -1, 0);
				if (parse->row != parse->map_height - 1)
					ft_element_check(parse, 1, 0);
				if (parse->col != 0)
					ft_element_check(parse, 0, -1);
				if (parse->col != parse->map_width - 1)
					ft_element_check(parse, 0, 1);
			}
			parse->col += 1;
		}
		parse->row += 1;
	}
}

void	ft_one_line_2d(t_input_parse *parse, char *map_line)
{
	int	i;
	int	j;
	int	index;

	j = 0;
	parse->two_d_array[parse->i] = malloc((parse->map_width + 1)
			* sizeof(char));
	index = 0;
	while (j < (int)ft_strlen(map_line))
	{
		if (map_line[j] == '\t')
		{
			i = -1;
			while (++i < 4)
				parse->two_d_array[parse->i][index++] = '*';
		}
		else if (map_line[j] == ' ')
			parse->two_d_array[parse->i][index++] = '*';
		else
			parse->two_d_array[parse->i][index++] = map_line[j];
		++j;
	}
	while (index < parse->map_width)
		parse->two_d_array[parse->i][index++] = '*';
	parse->two_d_array[parse->i][index] = '\0';
}

void	ft_ll_to_2d(t_input_parse *parse)
{
	t_map	*temporary;

	parse->two_d_array = malloc((parse->map_height + 1) * sizeof(char *));
	temporary = parse->map;
	parse->i = parse->map_height;
	parse->two_d_array[parse->i] = NULL;
	while (temporary != NULL)
	{
		parse->i -= 1;
		ft_one_line_2d(parse, temporary->map_line);
		temporary = temporary->next;
	}
}

t_map	*ft_map_to_ll(t_input_parse *parse)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->map_line = parse->line;
	map->next = NULL;
	return (map);
}

void	ft_gnl_to_ll(t_input_parse *parse)
{
	t_map	*tmp;

	if (parse->map_width < (int)ft_strlen(parse->line))
		parse->map_width = (int)ft_strlen(parse->line);
	parse->map_height += 1;
	tmp = ft_map_to_ll(parse);
	tmp->next = parse->map;
	parse->map = tmp;
}

void	ft_map_parse(t_input_parse *parse)
{
	while (get_next_line(parse->fd, &parse->line) != 0)
		ft_gnl_to_ll(parse);
	if (ft_strlen(parse->line) == 0)
		ft_error_message("Wrong input\n");
	else
		ft_gnl_to_ll(parse);
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

void	ft_input_parse(int argc, char **argv, t_input_parse *parse)
{
	ft_extension_checker(argc, argv);
	ft_bzero(parse, sizeof(*parse));
	parse->fd = open(argv[1], O_RDONLY);
	if (parse->fd == -1)
		exit(EXIT_FAILURE);
	while (get_next_line(parse->fd, &parse->line) != 0 && parse->full == 0)
	{
		ft_texture_parser(parse->line, parse);
		ft_color_parser(parse->line, parse);
		if (parse->NO != NULL && parse->NO != NULL && parse->WE != NULL
			&& parse->EA != NULL && parse->F != 0 && parse->C != 0)
			parse->full = 1;
		free(parse->line);
	}
	if (parse->full != 1)
	{
		close (parse->fd);
		ft_error_message("Wrong input\n");
	}
	ft_map_parse(parse);
	ft_ll_to_2d(parse);
	ft_map_checker(parse);
	close (parse->fd);
	//ft_struct_printer(parse);
}
