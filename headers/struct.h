#ifndef STRUCT_H
# define STRUCT_H

struct Point
{
	int	x;
	int	y;
};

enum color
{
	RED,
	GREEN,
	BLUE,
	YELLOW
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
}	t_cub3D;

#endif /* STRUCT_H */
