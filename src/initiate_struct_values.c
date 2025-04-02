/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_struct_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:03:49 by frocha            #+#    #+#             */
/*   Updated: 2025/03/31 22:03:51 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initiate_map(t_map *map)
{
	map->grid = malloc(sizeof(char *) * 7);
	map->grid[0] = ft_strdup("111111111111111");
	map->grid[1] = ft_strdup("100000000000001");
	map->grid[2] = ft_strdup("1001000S0000001");
	map->grid[3] = ft_strdup("100000001100001");
	map->grid[4] = ft_strdup("100000001100001");
	map->grid[5] = ft_strdup("111111111111111");
	map->grid[6] = NULL;
	map->map_height = 5;
}

void	initiate_player(t_player *player, t_game *game)
{
	player->x = 0;
	player->y = 0;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = PI / 2;
	player->walk_speed = 2;
	player->turn_speed = 2 * (PI / 180);
	player->game = game;
}

void	initiate_str_access_values(t_str_access *str_access)
{
	str_access->game = malloc(sizeof(t_game));
	str_access->map = malloc(sizeof(t_map));
	str_access->player = malloc(sizeof(t_player));
	str_access->game->ceiling = malloc(sizeof(t_color));
	str_access->game->floor = malloc(sizeof(t_color));
}

void	set_player_rotation_angle(t_player *player, char letter)
{
	if (letter == 'N')
	{
		player->rotation_angle = PI * 1.5;
	}
	else if (letter == 'S')
	{
		player->rotation_angle = PI / 2;
	}
	else if (letter == 'E')
	{
		player->rotation_angle = 0;
	}
	else if (letter == 'W')
	{
		player->rotation_angle = PI;
	}
}
