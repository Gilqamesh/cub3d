#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include "definitions.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

enum e_color
{
	RED = 0x00ff0000,
	INV_RED = 0xff00ffff,
	GREEN = 0x0000ff00,
	INV_GREEN = 0xffff00ff,
	BLUE = 0x000000ff,
	INV_BLUE = 0xffffff00,
	YELLOW = 0x00ffff00,
	WHITE = 0x00ffffff,
	BLACK = 0x00000000,
	BLANK = 0xff000000
};

typedef struct s_line_segment
{
	t_point			A;
	t_point			B;
	unsigned int	color;
}	t_line_segment;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

enum e_texture_name
{
	TEXTURE_DOOR,
	TEXTURE_LAMP,
	TEXT_N_WALL,
	TEXT_W_WALL,
	TEXT_S_WALL,
	TEXT_E_WALL,
	TEXTURE_N_OF_WALL,
	N_OF_TEXTURES
};

# define FLOOR_TEXTURE		WHITE_BRICK
# define CEILING_TEXTURE	WOOD

enum e_sprite_name
{
	SPRITE_LAMP,
	SPRITE_GOGGLE,
	SPRITE_AMBER,
	N_OF_SPRITES
};

// index_of_sprite for sprites where img holds multiple sprites
// uDiv		shrink sprite's width by this much
// vDiv		shrink sprite's height by this much
// vMove	move sprite down in the vertical direction (it might be necessary
//				after shrinking)
// translucency_factor	how transparent the sprite is:
//							1	opaque
//							2	half transparent
//							4 	quarter transparent
//							etc.
typedef struct s_sprite
{
	t_data				*img;
	int					index_of_sprite;
	int					distance;
	enum e_sprite_name	name;
	double				posX;
	double				posY;
	double				uDiv;
	double				vDiv;
	int					vMove;
	double				translucency_factor;
}	t_sprite;

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}			t_map;

typedef struct s_input_parse
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;

	int		F;
	int		C;

	int		map_width;
	int		map_height;

	int		no_full;
	int		so_full;
	int		we_full;
	int		ea_full;

	int		c_full;
	int		f_full;
	int		full;
	int		fd;
	int		i;

	int		row;
	int		col;

	char	*line;
	char	**two_d_array;

	t_map	*map;

}	t_input_parse;

typedef struct s_door
{
	t_point	coordinates;
	bool	opened;
	double	dist;
}	t_door;

typedef struct s_cub3D
{
	char				**map;
	int					map_height;
	int					map_width;
	struct line_segment	*walls;
	t_data				canvas;
	t_vars				vars;
	double				posX;
	double				posY;
	double				posZ;
	double				dirX;
	double				dirY;
	double				planeX;
	double				planeY;
	t_data				*textures;
	bool				is_w_held;
	bool				is_a_held;
	bool				is_s_held;
	bool				is_d_held;
	bool				is_left_held;
	bool				is_right_held;
	bool				is_paused;
	t_data				*goggles;
	t_data				*amber_sprites;
	t_data				pause_img;
	t_data				minimap_img;
	t_data				minimap_wall_img;
	t_data				minimap_blank_img;
	t_data				real_time_minimap_img;
	t_data				brush_img;
	long int			prev_timestamp;
	int					n_of_sprites_on_map;
	t_sprite			*sprites;
	double				*ZBuffer;
	t_input_parse		parse;
	bool				at_door;
	t_door				door_ahaed;
	t_data				minimap_door_closed_img;
	t_data				minimap_door_open_img;
	int					n_of_renders;
	t_data				crosshair_img;
	int					n_of_spaces_on_map;
	int					n_of_lamps_on_map;
	unsigned int		draw_buffer[SCREEN_H][SCREEN_W];
}	t_cub3D;

typedef struct s_extract_img_args
{
	t_point		*A;
	t_point		*B;
	t_point		*cell_size;
}	t_extract_img_args;

typedef struct s_point_p
{
	int	*x;
	int	*y;
}	t_point_p;

#endif /* STRUCT_H */
