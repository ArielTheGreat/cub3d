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
    player->rotationAngle += player->turnDirection * player->turnSpeed;

    float moveStep = player->walkDirection * player->walkSpeed;

    float newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
    float newPlayerY = player->y + sin(player->rotationAngle) * moveStep;

    if (!check_obstacle_blocks(newPlayerX, newPlayerY, player))
    {
        player->x = newPlayerX;
        player->y = newPlayerY;
    }
}
