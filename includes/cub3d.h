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
    mlx_t *mlx;
    mlx_image_t *static_layer;
	mlx_image_t *dynamic_layer;
} t_game;

typedef struct s_map
{
	char **grid;
    int map_height;
} t_map;


typedef struct s_player
{
    float x;
    float y;
    int turnDirection;
    int walkDirection;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
    t_game *game;
} t_player;

typedef struct s_str_access
{
	t_player *player;
    t_map    *map;
    t_game   *game;
} t_str_access;

void initiate_map(t_map *map);
void initiate_player(t_player *player, t_game *game);

#endif