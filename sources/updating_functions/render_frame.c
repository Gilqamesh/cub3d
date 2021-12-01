#include "main.h"

static void	render_pipeline(t_cub3D *mystruct)
{
	floor_casting(mystruct);
	wall_casting(mystruct);
	sprite_casting(mystruct);
	update_canvas(mystruct);
	draw_brush(mystruct);
	draw_crosshair(mystruct);
	draw_minimap(mystruct);
	update_position(mystruct);
	update_mouse(mystruct);
	// print_debug(mystruct);
	mlx_do_sync(mystruct->vars.mlx);
}

int	render_frame(void *param)
{
	static t_cub3D	*mystruct = NULL;
	static bool		first_time = true;

	if (first_time == true)
	{
		first_time = false;
		mystruct = (t_cub3D *)param;
		mlx_mouse_hide();
		mlx_mouse_move(mystruct->vars.win, SCREEN_W / 2, SCREEN_H / 2);
		mystruct->prev_timestamp = get_current_timestamp();
	}
	if (mystruct->is_paused == true)
	{
		draw_pause_screen(mystruct);
		return (0);
	}
	if (++mystruct->n_of_renders == 30 / 4)
		mystruct->n_of_renders = 0;
	render_pipeline(mystruct);
	return (0);
}
