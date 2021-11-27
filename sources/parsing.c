#include "headers.h"

void	ft_result_tester(t_input_parse *parse)
{
	printf("NO: %s\n", parse->NO);
	printf("SO: %s\n", parse->SO);
	printf("WE: %s\n", parse->WE);
	printf("EA: %s\n\n", parse->EA);
	printf("F: %d\n", parse->F);
	printf("C: %d\n\n", parse->C);
	printf("Full: %d\n", parse->full);
	printf("Len one_dim: %zu\n", ft_strlen(parse->one_dim));
	printf("one_dim: %s\n", parse->one_dim);
}

void	ft_single_free(char **string)
{
	if (!string)
		return ;
	free(*string);
	*string = 0;
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

void	ft_map_parse(t_input_parse *parse)
{
	parse->one_dim = ft_strdup("");
	while (get_next_line(parse->fd, &parse->line) != 0)
	{
		parse->temp = parse->one_dim;
		parse->one_dim = ft_strjoin(parse->temp, parse->line);
		ft_single_free(&parse->temp);
		ft_single_free(&parse->line);
	}
	parse->temp = parse->one_dim;
	parse->one_dim = ft_strjoin(parse->temp, parse->line);
	ft_single_free(&parse->temp);
	ft_single_free(&parse->line);
}

void	ft_input_parse(char **argv, t_input_parse *parse)
{
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
		return (1);
	}
	ft_map_parse(parse);
	close (parse->fd);
	ft_result_tester(parse);
}

int	ft_extension_checker(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error_message("Wrong input\n");
		return (1);
	}
	else if (!(argv[1][ft_strlen(argv[1]) - 4] == '.'
		&& argv[1][ft_strlen(argv[1]) - 3] == 'c'
		&& argv[1][ft_strlen(argv[1]) - 2] == 'u'
		&& argv[1][ft_strlen(argv[1]) - 1] == 'b')) //why not segfault with 1.cu
	{
		ft_error_message("Wrong input\n");
		return (1);
	}
	return (0);
}
