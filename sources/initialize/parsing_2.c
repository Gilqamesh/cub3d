#include "main.h"

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

void	ft_line_saver(t_cub3D *mystruct, int index)
{
	while (index < mystruct->parse.map_width)
		mystruct->map[mystruct->parse.i][index++] = '*';
	mystruct->map[mystruct->parse.i][index] = '\0';
}

void	ft_one_line_2d(t_cub3D *mystruct, char *map_line)
{
	int	i;
	int	j;
	int	index;

	mystruct->map[mystruct->parse.i] = malloc((mystruct->parse.map_width + 1)
			* sizeof(char));
	if (mystruct->map[mystruct->parse.i] == NULL)
		ft_error_message("Malloc Failed\n");
	j = 0;
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
	ft_line_saver(mystruct, index);
}

void	ft_ll_to_2d(t_cub3D *mystruct)
{
	t_map	*temporary;

	mystruct->map = malloc((mystruct->parse.map_height + 1) * sizeof(char *));
	if (mystruct->map == NULL)
		ft_error_message("Malloc Failed\n");
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
