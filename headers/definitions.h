#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define SCREEN_W	640
# define SCREEN_H	480
# define TITLE		"cub3D"
# define mapWidth	24
# define mapHeight	24
// Redefined macro from <math.h>
// # define INFINITY	1e30
# define KEY_LEFT	123
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_W		13
# define KEY_A		0
# define KEY_D		2
# define KEY_S		1
# define PI			3.1415
# define FPS		30.0
# define TEXTURE_W  64
# define TEXTURE_H  64
# define EPSILON	0.0000001

// debugging
# include <stdio.h>
# define PRINT_HERE() (printf("file: %s, line: %d\n", __FILE__, __LINE__))

#endif /* DEFINITIONS_H */
