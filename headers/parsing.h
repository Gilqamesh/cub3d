#ifndef PARSING_H
# define PARSING_H

# include "struct.h"
# include <fcntl.h>	

void	ft_input_parse(int argc, char **argv, t_input_parse *parse);
void	ft_extension_checker(int argc, char **argv);
void	ft_map_parse(t_input_parse *parse);
void	ft_gnl_to_ll(t_input_parse *parse);
t_map	*ft_map_to_ll(t_input_parse *parse);
void	ft_ll_to_2d(t_input_parse *parse);
void	ft_one_line_2d(t_input_parse *parse, char *map_line);
void	ft_map_checker(t_input_parse *parse);
void	ft_element_check(t_input_parse *parse, int y, int x);
void	ft_map_checker2(t_input_parse *parse);
void	ft_texture_parser(char *line, t_input_parse *parse);
void	ft_color_parser(char *line, t_input_parse *parse);
void	ft_rgb_to_dec(char *line, int *f_or_c);
int		ft_first_x_finder(char *line, char x);
int		ft_last_x_finder(char *line, char x);
int		ft_digit_finder(char *line);
void	ft_error_message(char *str);

#endif /* PARSING_H */
