#include "../includes/cub3d.h"

void draw_walls(t_game *game, int base_x_mult, int base_y_mult)
{
    int x;
    int y;

    y = 0;
    while (y < CUBE_SIZE)
    {
        x = 0;
        while (x < CUBE_SIZE)
        {
            mlx_put_pixel(game->static_layer, base_x_mult + x, base_y_mult + y, 0xFFFFFFFF); // White color
            x++;
        }
        y++;
    }
}

void process_map_row(t_str_access *str_access, int i, int *base_x_mult, int *base_y_mult)
{
    int x;
    t_player *player;
    t_map *map;
    t_game *game;

    player = str_access->player;
    map = str_access->map;
    game = str_access->game;
    x = 0;
    while (map->grid[i][x])
    {
        if (map->grid[i][x] == '1')
        {
            draw_walls(game, *base_x_mult, *base_y_mult);
        }else if (map->grid[i][x] == 'N' || map->grid[i][x] == 'S' || map->grid[i][x] == 'E'
            || map->grid[i][x] == 'W')
        {
            player->x = *base_x_mult;
            player->y = *base_y_mult;
        }
        *base_x_mult += CUBE_SIZE;
        x++;
    }
}

void add_static_pixels(t_str_access *str_access)
{
    int add_y;
    int base_x_mult;
    int base_y_mult;
    int i;

    add_y = 1;
    base_x_mult = CUBE_SIZE;
    base_y_mult = CUBE_SIZE;
    i = 0;
    while (i <= str_access->map->map_height)
    {
        process_map_row(str_access, i, &base_x_mult, &base_y_mult);
        add_y++;
        base_x_mult = CUBE_SIZE;
        base_y_mult = CUBE_SIZE * add_y;
        i++;
    }
    mlx_image_to_window(str_access->game->mlx, str_access->game->static_layer, 0, 0);
}

int check_obstacle_blocks(float newPlayerX, float newPlayerY, t_player *player)
{
    t_map *map;
    int column_block = (newPlayerX / CUBE_SIZE) - 1;
    int row_block = (newPlayerY / CUBE_SIZE) - 1;

    map = player->map;
    if (map->grid[row_block][column_block] == '1')
    {
        return (1);
    }
    return (0);
}

int is_wall(int y_to_check,int x_to_check, t_player *player)
{
    if (player->map->grid[y_to_check][x_to_check] == '1')
    {   
        return (1);
    }
    return 0;
}