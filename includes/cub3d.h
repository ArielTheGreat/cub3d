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

# define SCREEN_WIDTH		1300
# define SCREEN_HEIGHT		800
# define CUBE_SIZE  16
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
    mlx_image_t *view_layer;
    uint32_t *colorBuffer;
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
    float ray_angle;
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

void draw_line(t_player *player, t_game *game, float dest_x, float dest_y);

/* initiate_struct_values.c */
void initiate_map(t_map *map);
void initiate_player(t_player *player, t_game *game);
void initiate_str_access_values(t_str_access *str_access);
void set_player_rotation_angle(t_player *player, char letter);

/* player_functions.c */
void move_player(t_player *player);

/* map_wall_functions.c */
void add_static_pixels(t_str_access *str_access);
void process_map_row(t_str_access *str_access, int i, int *base_x_mult, int *base_y_mult);
void draw_walls(t_game *game, int base_x_mult, int base_y_mult);
int check_obstacle_blocks(float newPlayerX, float newPlayerY, t_player *player);
int is_wall(float x,float y, t_player *player);

/* draw_rays.c */
void cast_all_rays(t_player *player, t_rays *rays);
void render_rays(t_player *player, t_rays *rays);
int distance_ray2wall(float origin_x, float origin_y, float destination_x, float destination_y);

/* ray_wall_hit.c */
void find_horz_ray_wall_hit(t_horz_wall_hit_data *horz_wall_hit_data, float ray_angle, t_player *player, t_ray_directin_data  *ray_directin_data);
void find_vert_ray_wall_hit(t_vert_wall_hit_data *vert_wall_hit_data, float ray_angle, t_player *player, t_ray_directin_data  *ray_directin_data);
void inititate_ray_direction_data(t_ray_directin_data *ray_directin_data, float ray_angle);
void set_values_ray(t_rays *rays, float ray_angle, t_ray_directin_data  *ray_directin_data, int counter);
void set_vert_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_vert_wall_hit_data *vert_wall_hit_data, int counter);
void set_horz_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, int counter);
void find_distance(t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data, t_player *player);
void initiate_wall_hit_data_structs_values(t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data);

/* set_values_each_ray.c */
void set_values_ray(t_rays *rays, float ray_angle, t_ray_directin_data  *ray_directin_data, int counter);
void set_vert_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_vert_wall_hit_data *vert_wall_hit_data, int counter);
void set_horz_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, int counter);

#endif