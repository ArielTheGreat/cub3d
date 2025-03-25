#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../MLX42/include/MLX42/MLX42.h" // MLX42 header
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

# define SCREEN_WIDTH		2580
# define SCREEN_HEIGHT		1960
# define CUBE_SIZE  32
# define MOVING_OBJECT_SIZE 5
# define PI 3.14159265358979323846

typedef struct s_game
{
	char **map;
    mlx_t *mlx;
    int map_height;
    int player_position_x;
    int player_position_y;
    mlx_image_t *static_layer;
	mlx_image_t *dynamic_layer;
} t_game;

#endif