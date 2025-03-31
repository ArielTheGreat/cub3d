/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:03:24 by frocha            #+#    #+#             */
/*   Updated: 2025/03/31 22:03:26 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_line(t_player *player, t_game *game, float dest_x, float dest_y) {
    int origin_x = (int)player->x;
    int origin_y = (int)player->y;
    int dest_x_int = (int)dest_x;
    int dest_y_int = (int)dest_y;

    int dx = abs(dest_x_int - origin_x);
    int dy = -abs(dest_y_int - origin_y);
    int sx = (origin_x < dest_x_int) ? 1 : -1;
    int sy = (origin_y < dest_y_int) ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1) {
        if (origin_x >= 0 && origin_x < (int)game->dynamic_layer->width &&
            origin_y >= 0 && origin_y < (int)game->dynamic_layer->height) {
            mlx_put_pixel(game->dynamic_layer, origin_x, origin_y, 0xFF0000FF);
        }

        if (origin_x == dest_x_int && origin_y == dest_y_int) {
            break;
        }

        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            origin_x += sx;
        }
        if (e2 <= dx) {
            err += dx;
            origin_y += sy;
        }
    }
}
