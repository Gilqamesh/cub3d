#ifndef STRUCT_H
# define STRUCT_H

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
	enum color		color;
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
	FLAG,
	RED_BRICK,
	PURPLE_BRICK,
	WHITE_BRICK,
	BLUE_BRICK,
	MOSS_BRICK,
	WOOD,
	COBBLE_STONE
};

# define FLOOR_TEXTURE WHITE_BRICK
# define CEILING_TEXTURE WOOD

# include <stdbool.h>

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
	double				moveSpeed;
	double				rotSpeed;
	t_data				*textures;
	bool				is_w_held;
	bool				is_a_held;
	bool				is_s_held;
	bool				is_d_held;
	bool				is_left_held;
	bool				is_right_held;
	bool				is_paused;
	t_data				pause_img;
	t_data				minimap_img;
	t_data				minimap_wall_img;
	t_data				minimap_blank_img;
	t_data				real_time_minimap_img;
	long int			prev_timestamp;
}	t_cub3D;

typedef struct s_args1
{
	t_point	A;
	t_point	B;
	char	*filePath;
	t_vars	*vars;
	t_point	cell_size;
}	t_args1;

typedef struct s_input_parse
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;

	int		F;
	int		C;

	char	*one_dim_map;
	char	*two_dim_map;

	int		map_width;
	int		map_height;

	int		fd;
	int		full;
	char	*line;
	char	*temp;
	char	*one_dim;
}	t_input_parse;

#endif /* STRUCT_H */
