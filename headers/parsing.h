#ifndef PARSING_H
# define PARSING_H

# include "struct.h"
# include <fcntl.h>	

int		ft_extension_checker(int argc, char **argv);
void	ft_input_parse(char **argv, t_input_parse *parse);
void	ft_map_parse(t_input_parse *parse);
void	ft_gnl_to_one_dim(t_input_parse *parse);
void	ft_texture_parser(char *line, t_input_parse *parse);
void	ft_color_parser(char *line, t_input_parse *parse);
void	ft_rgb_to_dec(char *line, int *f_or_c);
int		ft_first_x_finder(char *line, char x);
int		ft_last_x_finder(char *line, char x);
int		ft_digit_finder(char *line);
void	ft_error_message(char *str);
void	ft_single_free(char **string);

#endif /* PARSING_H */
