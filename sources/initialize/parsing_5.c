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
