#include "../includes/cub3d.h"

void initiate_map(t_map *map)
{
    map->grid = malloc(sizeof(char *) * 7);
    map->grid[0] = ft_strdup("111111111111111");
    map->grid[1] = ft_strdup("100000000000001");
    map->grid[2] = ft_strdup("1001000N0000001");
    map->grid[3] = ft_strdup("100000001100001");
    map->grid[4] = ft_strdup("100000001100001");
    map->grid[5] = ft_strdup("111111111111111");
    map->grid[6] = NULL;
    
    map->map_height = 5;
}

void initiate_player(t_player *player, t_game *game)
{
    player->x = 0;
    player->y = 0;
    player->turnDirection = 0;
    player->walkDirection = 0;
    player->rotationAngle = PI / 2;
    player->walkSpeed = 2;
    player->turnSpeed = 2 * (PI / 180);
    player->game = game;
}

void initiate_str_access_values(t_str_access *str_access)
{
    str_access->game = malloc(sizeof(t_game));
    str_access->map = malloc(sizeof(t_map));
    str_access->player = malloc(sizeof(t_player));
}