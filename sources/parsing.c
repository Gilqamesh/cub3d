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

void	ft_one_line_2d(t_input_parse *parse, char *map_line)
{
	int	j;

	j = 0;
	while (j < parse->map_width)
	{
		if (j > ((int)ft_strlen(map_line) - 1))
			parse->two_d_array[parse->i][j] = '*';
		else if (map_line[j] == ' ')
			parse->two_d_array[parse->i][j] = '*';
		else if (map_line[j] == '\t')
		{
			parse->two_d_array[parse->i][j] = '*';
			parse->two_d_array[parse->i][j] = '*';
			parse->two_d_array[parse->i][j] = '*';
			parse->two_d_array[parse->i][j] = '*';
			j += 3;
		}
		else
			parse->two_d_array[parse->i][j] = map_line[j];
		j++;
	}
}

void	ft_ll_to_2d(t_input_parse *parse)
{
	t_map	*temporary;

	parse->two_d_array = malloc(parse->map_height * parse->map_width + 1);
	temporary = parse->map;
	parse->i = parse->map_height;
	parse->two_d_array[parse->i] = NULL;
	while (temporary != NULL)
	{
		parse->i -= 1;
		//ft_one_line_2d(parse, temporary->map_line);
		//parse->two_d_array[parse->i] = temporary->map_line;
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
	}
	if (parse->full != 1)
	{
		ft_error_message("Wrong input\n");
		close (parse->fd);
		return ;
	}
	ft_map_parse(parse);
	ft_ll_to_2d(parse);
	close (parse->fd);
	//ft_struct_printer(parse);
}
