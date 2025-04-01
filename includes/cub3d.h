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
    uint32_t *color_buffer;
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
    int turn_direction;
    int walk_direction;
    float rotation_angle;
    float walk_speed;
    float turn_speed;
    t_game *game;
    t_map  *map;
} t_player;

typedef struct Ray
{
    float ray_angle;
    float wall_hit_x;
    float wall_hit_y;
    float distance;
    int was_hit_vertical;
    int is_ray_facing_up;
    int is_ray_facing_down;
    int is_ray_facing_left;
    int is_ray_facing_right;
} t_rays[NUM_RAYS];

typedef struct s_str_access
{
	t_player *player;
    t_map    *map;
    t_game   *game;
} t_str_access;

typedef struct s_horz_wall_hit_data
{
    int found_horz_hit;
    float horz_hit_x;
    float horz_hit_y;
} t_horz_wall_hit_data;

typedef struct s_vert_wall_hit_data
{
    int found_vert_hit;
    float vert_hit_x;
    float vert_hit_y;
} t_vert_wall_hit_data;

typedef struct s_ray_facing_data
{
    int is_ray_facing_down;
    int is_ray_facing_up;
    int is_ray_facing_right;
    int is_ray_facing_left;
} t_ray_facing_data;

typedef struct s_hit_distance_wall
{
    float horz;
    float vert;
} t_hit_distance_wall;

typedef struct s_ray_wall_hit_horz
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;
    float next_horz_touch_wall_x;
    float next_horz_touch_wall_y;
    float x_to_check;
    float y_to_check;
} t_ray_wall_hit_horz;

typedef struct s_ray_wall_hit_vert
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;
    float next_vert_touch_wall_x;
    float next_vert_touch_wall_y;
    float y_to_check;
    float x_to_check;
} t_ray_wall_hit_vert;

typedef struct s_draw_line_variables
{
    int	init_x;
	int	init_y;
	int	dest_x;
	int	dest_y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
} t_draw_line_variables;

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
int check_obstacle_blocks(float new_player_x, float new_player_y, t_player *player);
int is_wall(float x,float y, t_player *player);

/* draw_rays.c */
void cast_all_rays(t_player *player, t_rays *rays);
void render_rays(t_player *player, t_rays *rays);
int distance_ray2wall(float origin_x, float origin_y, float destination_x, float destination_y);

/* ray_wall_hit.c */
void find_horz_ray_wall_hit(t_horz_wall_hit_data *horz_wall_hit_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data);
void find_vert_ray_wall_hit(t_vert_wall_hit_data *vert_wall_hit_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data);
void inititate_ray_direction_data(t_ray_facing_data *ray_facing_data, float ray_angle);
void find_distance(t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data, t_player *player);
void init_wall_hit_data_values(t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data);

/* set_values_each_ray.c */
void set_values_ray(t_rays *rays, float ray_angle, t_ray_facing_data  *ray_facing_data, int counter);
void set_vert_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_vert_wall_hit_data *vert_wall_hit_data, int counter);
void set_horz_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, int counter);

/* find_intercepts_steps.c */
void find_horz_intercepts(t_ray_wall_hit_horz *horz_ray_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data);
void find_horz_steps(t_ray_wall_hit_horz *horz_ray_data, float ray_angle, t_ray_facing_data  *ray_facing_data);
void find_vert_intercepts(t_ray_wall_hit_vert *vert_ray_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data);
void find_vert_steps(t_ray_wall_hit_vert *vert_ray_data, float ray_angle, t_ray_facing_data  *ray_facing_data);

/* check_ray_between_limits.c */
bool check_limits_horz_ray(t_ray_wall_hit_horz	*horz_ray_data);
bool check_limits_vert_ray(t_ray_wall_hit_vert	*vert_ray_data);

#endif