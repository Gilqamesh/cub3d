#ifndef FT_LIBFTPUT_H
# define FT_LIBFTPUT_H

// Outputs the character 'c' to the given file descriptor.
void	ft_putchar_fd(char c, int fd);
// Outputs the string 's' to the given file descriptor, followed by a newline.
void	ft_putendl_fd(char *s, int fd);
// Outputs the integer 'n' to the given file descriptor.
void	ft_putnbr_fd(int n, int fd);
// Writes string 's' up to 'n' characters to 'fd' file descriptor
void	ft_putnstr_fd(char *s, int n, int fd);
// Outputs the string 's' to the given file descriptor.
void	ft_putstr_fd(char *s, int fd);

#endif /* FT_LIBFTPUT_H */
