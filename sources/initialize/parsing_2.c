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
			exit_program(STDERR_FILENO, "map contains other characters than "\
			"'0' '1' 'N' 'S' 'E' 'W' 'T' 'o' 'd': %c\n", str[i]);
		i++;
	}
}

void	ft_element_check(t_cub3D *mystruct, int y, int x)
{
	if (mystruct->map[mystruct->parse.row + y][mystruct->parse.col + x] != '*'
		&& mystruct->map[mystruct->parse.row + y]
				[mystruct->parse.col + x] != '1')
		exit_program(STDERR_FILENO, "map is not surrounded by 1's");
}

void	ft_line_saver(t_cub3D *mystruct, int index)
{
	while (index < mystruct->parse.map_width)
		mystruct->map[mystruct->parse.i][index++] = '*';
	mystruct->map[mystruct->parse.i][index] = '\0';
}

void	ft_one_line_2d(t_cub3D *mystruct, char *map_line)
{
	t_point	iter;
	int		index;

	mystruct->map[mystruct->parse.i] = ft_lstmallocwrapper(
			&mystruct->alloced_memory, (mystruct->parse.map_width + 1)
			* sizeof(char), false);
	if (mystruct->map[mystruct->parse.i] == NULL)
		exit_program(STDERR_FILENO, "malloc failed in file %s in function "\
		"ft_one_line_2d\n", __FILE__);
	iter.y = 0;
	index = 0;
	while (iter.y < (int)ft_strlen(map_line))
	{
		if (map_line[iter.y] == '\t')
		{
			iter.x = -1;
			while (++iter.x < 4)
				mystruct->map[mystruct->parse.i][index++] = '*';
		}
		else if (map_line[iter.y] == ' ')
			mystruct->map[mystruct->parse.i][index++] = '*';
		else
			mystruct->map[mystruct->parse.i][index++] = map_line[iter.y];
		++iter.y;
	}
	ft_line_saver(mystruct, index);
}

void	ft_ll_to_2d(t_cub3D *mystruct)
{
	t_map	*temporary;

	mystruct->map = ft_lstmallocwrapper(&mystruct->alloced_memory,
			(mystruct->parse.map_height + 1) * sizeof(char *), false);
	if (mystruct->map == NULL)
		exit_program(STDERR_FILENO, "malloc failed in file %s in function "\
		"ft_ll_to_2d\n", __FILE__);
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
