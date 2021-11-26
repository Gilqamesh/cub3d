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
	BLACK = 0x00000000
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

typedef struct s_cub3D
{
	char				**map;
	int					map_height;
	int					map_width;
	struct line_segment	*walls;
	t_data				img;
	t_vars				vars;
	double				posX; // x and y start position
	double				posY;
	double				dirX; // initial direction vector
	double				dirY;
	double				planeX; // the 2d raycaster version of camera plane
	double				planeY;
	double				moveSpeed;
	double				rotSpeed;
	t_data				*textures;
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
