#include "main.h"

void	ft_we_ae(char *line, t_cub3D *mystruct)
{
	char	*temp;

	if (line[0] == 'W' && line[1] == 'E' && mystruct->parse.we_full == 1)
		ft_error_message("Wrong input\n");
	if (line[0] == 'W' && line[1] == 'E' && mystruct->parse.we_full == 0)
	{
		temp = ft_strdup(line);
		mystruct->parse.WE = &temp[ft_first_x_finder(line, '.')];
		mystruct->parse.we_full = 1;
	}
	if (line[0] == 'E' && line[1] == 'A' && mystruct->parse.ea_full == 1)
		ft_error_message("Wrong input\n");
	if (line[0] == 'E' && line[1] == 'A' && mystruct->parse.ea_full == 0)
	{
		temp = ft_strdup(line);
		mystruct->parse.EA = &temp[ft_first_x_finder(line, '.')];
		mystruct->parse.ea_full = 1;
	}
}

void	ft_no_so(char *line, t_cub3D *mystruct)
{
	char	*temp;

	if (line[0] == 'N' && line[1] == 'O' && mystruct->parse.no_full == 1)
		ft_error_message("Wrong input\n");
	if (line[0] == 'N' && line[1] == 'O' && mystruct->parse.no_full == 0)
	{
		temp = ft_strdup(line);
		mystruct->parse.NO = &temp[ft_first_x_finder(line, '.')];
		mystruct->parse.no_full = 1;
	}
	if (line[0] == 'S' && line[1] == 'O' && mystruct->parse.so_full == 1)
		ft_error_message("Wrong input\n");
	if (line[0] == 'S' && line[1] == 'O' && mystruct->parse.so_full == 0)
	{
		temp = ft_strdup(line);
		mystruct->parse.SO = &temp[ft_first_x_finder(line, '.')];
		mystruct->parse.so_full = 1;
	}
}

void	ft_texture_parser(char *line, t_cub3D *mystruct)
{
	if (ft_first_x_finder(line, '.') != -1)
	{
		ft_no_so(line, mystruct);
		ft_we_ae(line, mystruct);
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