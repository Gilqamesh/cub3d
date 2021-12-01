#ifndef DEBUGGING_H
# define DEBUGGING_H

# include "struct.h"
# include <stdio.h>
# define OWNFILE (ft_substr(__FILE__, ft_last_x_finder(__FILE__, '/') + 1, 30))
# define PRINT_HERE() ({char *tmpasd = OWNFILE;\
	printf("file: %s, line: %d\n", tmpasd, __LINE__);\
	free(tmpasd);})
# include <sys/time.h>

long int	get_current_timestamp(void);
long int	timval_to_microseconds(struct timeval *t);
void		print_debug(t_cub3D *mystruct);

#endif /* DEBUGGING_H */
