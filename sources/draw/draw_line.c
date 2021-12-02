#include "main.h"

static void	low_slope_logic_helper(t_point p, t_point *delta,
t_point *tmp, int *decision_var)
{
	if (*decision_var < 0)
	{
		if (delta->y >= 0)
			*decision_var += 2 * delta->y;
		else
			*decision_var -= 2 * delta->y;
	}
	else
	{
		if (p.x > p.y)
			++tmp->y;
		else
			--tmp->y;
		if (delta->y >= 0)
			*decision_var += 2 * (delta->y - delta->x);
		else
			*decision_var -= 2 * (delta->y + delta->x);
	}
	++tmp->x;
}

static void	low_slope_logic(t_data *data, t_line_segment s, t_point delta)
{
	t_point	tmp;
	int		decision_var;

	if (s.B.x < s.A.x)
		swap_t_point(&s.A, &s.B);
	if (delta.y >= 0)
		decision_var = 2 * delta.y - delta.x;
	else
		decision_var = -delta.x;
	tmp = s.A;
	while (tmp.x <= s.B.x)
	{
		my_mlx_pixel_put(data, tmp.x, tmp.y, s.color);
		low_slope_logic_helper((t_point){s.B.y, s.A.y}, &delta, &tmp,
			&decision_var);
	}
}

static void	high_slope_logic_helper(t_point p, t_point *delta,
t_point *tmp, int *decision_var)
{
	if (*decision_var < 0)
	{
		if (delta->y > delta->x)
			*decision_var += 2 * delta->x;
		else
			*decision_var -= 2 * delta->x;
	}
	else
	{
		if (p.x > p.y)
			++tmp->x;
		else
			--tmp->x;
		if (delta->y > delta->x)
			*decision_var += 2 * (delta->x - delta->y);
		else
			*decision_var -= 2 * (delta->x + delta->y);
	}
	++tmp->y;
}

static void	high_slope_logic(t_data *data, t_line_segment s, t_point delta)
{
	t_point	tmp;
	int		decision_var;

	if (s.B.y < s.A.y)
		swap_t_point(&s.A, &s.B);
	decision_var = -delta.y;
	tmp = s.A;
	while (tmp.y <= s.B.y)
	{
		my_mlx_pixel_put(data, tmp.x, tmp.y, s.color);
		high_slope_logic_helper((t_point){s.B.x, s.A.x}, &delta, &tmp,
			&decision_var);
	}
}

// Based on Bresenham's algorithm
void	draw_line(t_data *data, t_point A, t_point B, unsigned int color)
{
	t_point	delta;

	delta.x = ft_abs_int(B.x - A.x);
	delta.y = ft_abs_int(B.y - A.y);
	if (delta.y <= delta.x && delta.y >= -delta.x)
		low_slope_logic(data, (t_line_segment){A, B, color}, delta);
	else
		high_slope_logic(data, (t_line_segment){A, B, color}, delta);
}
