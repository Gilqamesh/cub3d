#ifndef DEBUGGING_H
# define DEBUGGING_H

# include "struct.h"
# include <stdio.h>
# define PRINT_HERE() (printf("file: %s, line: %d\n", __FILE__, __LINE__))
# include <sys/time.h>

long int	get_current_timestamp(void);
long int	timval_to_microseconds(struct timeval *t);
void		print_debug(t_cub3D *mystruct);

#endif /* DEBUGGING_H */
