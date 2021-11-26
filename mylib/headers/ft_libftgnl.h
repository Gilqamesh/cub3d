#ifndef FT_LIBFTGNL_H
# define FT_LIBFTGNL_H

# include <stdlib.h>

int		contains_newline(char *str, size_t n);
char	*ft_strdup_v2(const char *s, int n);
// NEEDS DOCUMENTATION ON FUNCTIONALITY, ESPECIALLY RETURN VALUE
int		get_next_line(int fd, char **line);

#endif /* FT_LIBFTGNL_H */
