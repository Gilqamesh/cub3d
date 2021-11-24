#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define SCREEN_W	640
# define SCREEN_H	480
# define TITLE		"cub3D"
# define mapWidth	24
# define mapHeight	24
# define INFINITY	1e30
# define KEY_LEFT	65361
# define KEY_UP	    65362
# define KEY_DOWN   65364
# define KEY_RIGHT	65363
# define KEY_W		119
# define KEY_A		97
# define KEY_D		100
# define KEY_S		115
# define PI			3.1415
# define FPS		30.0
# define TEXTURE_W  64
# define TEXTURE_H  64

// debugging
# include <stdio.h>
# define PRINT_HERE() (printf("file: %s, line: %d\n", __FILE__, __LINE__))

#endif /* DEFINITIONS_H */
