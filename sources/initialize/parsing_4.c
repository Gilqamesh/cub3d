#include "main.h"

void	ft_map_checker2(t_cub3D *mystruct)
{
	int	i;

	i = 0;
	while (i < mystruct->parse.map_width)
	{
		if (mystruct->map[0][i] != '*'
			&& mystruct->map[0][i] != '1')
			exit_program(STDERR_FILENO, "Map is not enclosed by * or 1"\
				" from the top: %c\n", mystruct->map[0][i]);
		if (mystruct->map[mystruct->parse.map_height - 1][i] != '*'
			&& mystruct->map[mystruct->parse.map_height - 1][i] != '1')
			exit_program(STDERR_FILENO, "Map is not enclosed by * or 1"\
				" from the bot: %c\n",
				mystruct->map[mystruct->parse.map_height - 1][i]);
		i++;
	}
	i = 0;
	while (i < mystruct->parse.map_height)
	{
		if (mystruct->map[i][0] != '*'
			&& mystruct->map[i][0] != '1')
			exit_program(STDERR_FILENO, "Map is not enclosed by * or 1"\
				" from the left: %c\n", mystruct->map[i][0]);
		if (mystruct->map[i][mystruct->parse.map_width - 1] != '*'
			&& mystruct->map[i][mystruct->parse.map_width - 1] != '1')
			exit_program(STDERR_FILENO, "Map is not enclosed by * or 1"\
				" from the right: %c\n",
				mystruct->map[i][mystruct->parse.map_width - 1]);
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
			exit_program(STDERR_FILENO, "did not find ',' or digit in color"\
				" format in: %s\n", line);
		i++;
	}
}

void	ft_rgb_to_dec(char *line, int *f_or_c)
{
	int	i;

	ft_color_error_checker(line);
	i = ft_digit_finder(line);
	if (ft_atoi(&line[i]) > 255)
		exit_program(STDERR_FILENO, "color %d must be in between 0 and 255: "\
		"%s\n", ft_atoi(&line[i]), line);
	*f_or_c += ft_atoi(&line[i]) << 16;
	i += ft_intlen(ft_atoi(&line[i])) + 1;
	if (ft_isdigit((int)line[i]))
	{
		if (ft_atoi(&line[i]) > 255)
			exit_program(STDERR_FILENO, "color %d must be in between 0 and 255"\
			": %s\n", ft_atoi(&line[i]), line);
		*f_or_c += ft_atoi(&line[i]) << 8;
	}
	i = ft_last_x_finder(line, ',') + 1;
	if (ft_isdigit((int)line[i]))
	{
		if (ft_atoi(&line[i]) > 255)
			exit_program(STDERR_FILENO, "color %d must be in between 0 and 255"\
			": %s\n", ft_atoi(&line[i]), line);
		*f_or_c += ft_atoi(&line[i]);
	}
}

void	ft_color_parser(char *line, t_cub3D *mystruct)
{
	if (line[0] == 'F' && mystruct->parse.f_full == 1)
		exit_program(STDERR_FILENO, "Floor color has already been parsed\n");
	if (line[0] == 'F' && mystruct->parse.f_full == 0)
	{
		ft_rgb_to_dec(line, &mystruct->parse.F);
		mystruct->parse.f_full = 1;
	}
	if (line[0] == 'C' && mystruct->parse.c_full == 1)
		exit_program(STDERR_FILENO, "Ceiling color has already been parsed\n");
	if (line[0] == 'C' && mystruct->parse.c_full == 0)
	{
		ft_rgb_to_dec(line, &mystruct->parse.C);
		mystruct->parse.c_full = 1;
	}
}
