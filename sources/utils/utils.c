#include "main.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, unsigned int color)
{
	char	*dst;
	int		a;
	int		b;

	a = ft_round_to_nearest_int(x);
	b = ft_round_to_nearest_int(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_data *data, double x, double y)
{
	char	*dst;
	int		a;
	int		b;

	a = ft_round_to_nearest_int(x);
	b = ft_round_to_nearest_int(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

double	euclidean_distance(double a, double b)
{
	return (sqrt(a * a + b * b));
}

unsigned int	divide_color(unsigned int color, double divisor)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	alpha = (unsigned int)(((color & BLANK) >> 24) / divisor) << 24;
	red = (unsigned int)(((color & RED) >> 16) / divisor) << 16;
	green = (unsigned int)(((color & GREEN) >> 8) / divisor) << 8;
	blue = (unsigned int)((color & BLUE) / divisor);
	return (alpha | red | green | blue);
}

void	swap_t_point(t_point *p, t_point *q)
{
	t_point	tmp;

	tmp.x = p->x;
	tmp.y = p->y;
	p->x = q->x;
	p->y = q->y;
	q->x = tmp.x;
	q->y = tmp.y;
}
