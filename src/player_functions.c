/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:04:10 by frocha            #+#    #+#             */
/*   Updated: 2025/03/31 22:04:11 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_player(t_player *player)
{
    player->rotation_angle += player->turn_direction * player->turn_speed;

    float moveStep = player->walk_direction * player->walk_speed;

    float new_player_x = player->x + cos(player->rotation_angle) * moveStep;
    float new_player_y = player->y + sin(player->rotation_angle) * moveStep;

    if (!check_obstacle_blocks(new_player_x, new_player_y, player))
    {
        player->x = new_player_x;
        player->y = new_player_y;
    }
}
