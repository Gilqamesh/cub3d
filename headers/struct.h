#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

enum color
{
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
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

enum texture_name
{
	TEXTURE_DOOR,
	TEXTURE_BARREL,
	TEXTURE_PILLAR,
	TEXTURE_LAMP,
	TEXTURE_NORTH_WALL,
	TEXTURE_WEST_WALL,
	TEXTURE_SOUTH_WALL,
	TEXTURE_EAST_WALL,
	TEXTURE_N_OF_WALL,
	N_OF_TEXTURES
};

# define FLOOR_TEXTURE		WHITE_BRICK
# define CEILING_TEXTURE	WOOD

enum sprite_name
{
	SPRITE_LAMP,
	SPRITE_GOGGLE,
	N_OF_SPRITES
};

// index_of_sprite for sprites where img holds multiple sprites
typedef struct s_sprite
{
	t_data				*img;
	int					index_of_sprite;
	int					distance;
	enum sprite_name	name;
	double				posX;
	double				posY;
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

	int		fd;
	int		full;
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
	double	distance_from_player;
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
	bool				looking_at_door;
	t_door				door_to_interact_with;
	t_data				minimap_door_closed_img;
	t_data				minimap_door_open_img;
	int					n_of_renders;
	t_data				crosshair_img;
	int					n_of_spaces_on_map;
	int					n_of_lamps_on_map;
}	t_cub3D;

typedef struct s_args1
{
	t_point	A;
	t_point	B;
	char	*filePath;
	t_vars	*vars;
	t_point	cell_size;
}	t_args1;

#endif /* STRUCT_H */
