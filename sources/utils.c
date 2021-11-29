#include "headers.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;
	int		a;
	int		b;

	a = ft_round_to_nearest_int(x);
	b = ft_round_to_nearest_int(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_data *data, double x, double y)
{
	char	*dst;
	int		a;
	int		b;

	a = ft_round_to_nearest_int(x);
	b = ft_round_to_nearest_int(y);
	dst = data->addr + (b * data->line_length + a * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
