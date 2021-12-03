#include "main.h"

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

void	ft_check_for_player(t_cub3D *mystruct)
{
	int		x;
	int		y;
	bool	already_seen;

	already_seen = false;
	y = -1;
	while (++y < mystruct->map_height)
	{
		x = -1;
		while (++x < mystruct->map_width)
		{
			if (mystruct->map[y][x] == 'N' || mystruct->map[y][x] == 'E'
				|| mystruct->map[y][x] == 'W' || mystruct->map[y][x] == 'S')
			{
				if (already_seen == false)
					already_seen = true;
				else
					exit_program(STDERR_FILENO,
						"Too many players set on map\n");
			}
		}
	}
	if (already_seen == false)
		exit_program(STDERR_FILENO, "No player has been set on the map\n");
}
