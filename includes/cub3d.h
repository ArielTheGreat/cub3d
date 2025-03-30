#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../MLX42/include/MLX42/MLX42.h" // MLX42 header
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>

# define SCREEN_WIDTH		2580
# define SCREEN_HEIGHT		1960
# define CUBE_SIZE  32
# define MOVING_OBJECT_SIZE 1
# define FOV_ANGLE (60 * (PI / 180))
# define PI 3.14159265
# define TWO_PI 6.28318530
# define NUM_RAYS 30
# define MAP_NUM_ROWS 6
# define MAP_NUM_COLS 15
# define WINDOW_WIDTH (MAP_NUM_COLS * CUBE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * CUBE_SIZE)

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
    t_map  *map;
} t_player;

typedef struct Ray
{
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
} t_rays[NUM_RAYS];

typedef struct s_str_access
{
	t_player *player;
    t_map    *map;
    t_game   *game;
} t_str_access;

typedef struct s_horz_wall_hit_data
{
    int foundHorizontalHit;
    float horzWallHitX;
    float horzWallHitY;
} t_horz_wall_hit_data;

typedef struct s_vert_wall_hit_data
{
    int foundVertWallHit;
    float vertWallHitX;
    float vertWallHitY;
} t_vert_wall_hit_data;

typedef struct s_ray_directin_data
{
    int isRayFacingDown;
    int isRayFacingUp;
    int isRayFacingRight;
    int isRayFacingLeft;
} t_ray_directin_data;

typedef struct s_hit_distance_wall
{
    float horz;
    float vert;
} t_hit_distance_wall;

void initiate_map(t_map *map);
void initiate_player(t_player *player, t_game *game);
void initiate_str_access_values(t_str_access *str_access);
void draw_line(t_player *player, t_game *game, float dest_x, float dest_y);

/* player_functions.c */
void movePlayer(t_player *player);
void draw_circle(t_player *player, t_game *game);

/* map_wall_functions.c */
void add_static_pixels(t_str_access *str_access);
void process_map_row(t_str_access *str_access, int i, int *base_x_mult, int *base_y_mult);
void draw_walls(t_game *game, int base_x_mult, int base_y_mult);
int check_obstacle_blocks(float newPlayerX, float newPlayerY, t_player *player);
int is_wall(float x,float y, t_player *player);

/* draw_rays.c */
void castAllRays(t_player *player, t_rays *rays);
void renderRays(t_player *player, t_rays *rays);

/* ray_wall_hit.c */
void findHorzRayWallHit(t_horz_wall_hit_data *horzWallHitData, float rayAngle, t_player *player, t_ray_directin_data  *ray_directin_data);
void findVertRayWallHit(t_vert_wall_hit_data *vertWallHitData, float rayAngle, t_player *player, t_ray_directin_data  *ray_directin_data);
void inititate_ray_direction_data(t_ray_directin_data *ray_directin_data, float rayAngle);

#endif