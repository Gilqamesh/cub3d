#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define SCREEN_W				640
# define SCREEN_H				480
# define TITLE					"cub3D"
# define KEY_LEFT				123
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_RIGHT				124
# define KEY_W					13
# define KEY_A					0
# define KEY_D					2
# define KEY_S					1
# define KEY_ESC				53
# define KEY_P					35
# define PI						3.1415
# define MOVE_SPEED				(1.0 / 15.0)
# define ROTATE_SPEED			(1.0 / 30.0)
# define TEXTURE_W  			64
# define TEXTURE_H  			64
# define EPSILON				0.0000001
# define MAX_X_DELTA			SCREEN_W
# define MINIMAP_CELL_X			SCREEN_W / 40
# define MINIMAP_CELL_Y			SCREEN_H / 40
# define MINIMAP_N_OF_CELL_X	10
# define MINIMAP_N_OF_CELL_Y	10
# define REALTIME_MINIMAP_W		(MINIMAP_CELL_X * MINIMAP_N_OF_CELL_X)
# define REALTIME_MINIMAP_H		(MINIMAP_CELL_Y * MINIMAP_N_OF_CELL_Y)

#endif /* DEFINITIONS_H */
