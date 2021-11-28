#include "headers.h"

/*
** Returns the current timestamp in microseconds compared to start.
*/
long int	get_current_timestamp(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (timval_to_microseconds(&cur));
}

/*
** Returns in microseconds the sum value in 't'.
*/
long int	timval_to_microseconds(struct timeval *t)
{
	if (t == NULL)
		return (-1);
	return (t->tv_sec * 1000000 + t->tv_usec);
}

void	display_fps(t_cub3D *mystruct)
{
	long int	timestamp = get_current_timestamp();
	printf("FPS: %f\n", 1000000.0 / (timestamp - mystruct->prev_timestamp));
	mystruct->prev_timestamp = timestamp;
}
