#ifndef STRUCT_H
# define STRUCT_H

struct Point
{
	int	x;
	int	y;
};

enum color
{
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
	YELLOW = 0x00ffff00,
	WHITE = 0x00ffffff,
	BLACK = 0x00000000
};

struct line_segment
{
	struct Point	A;
	struct Point	B;
	enum color		color;
};

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
	long int			time; // time of current frame
	long int			oldTime; // time of previous frame
	double				moveSpeed;
	double				rotSpeed;
}	t_cub3D;

#endif /* STRUCT_H */
