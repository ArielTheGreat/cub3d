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

void	draw_line(t_player *player, t_game *game, float dest_x, float dest_y)
{
	int	origin_x;
	int	origin_y;
	int	dest_x_int;
	int	dest_y_int;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	origin_x = (int)player->x;
	origin_y = (int)player->y;
	dest_x_int = (int)dest_x;
	dest_y_int = (int)dest_y;
	dx = abs(dest_x_int - origin_x);
	dy = -abs(dest_y_int - origin_y);
	sx = -1;
	sy = -1;
	if (origin_x < dest_x_int)
		sx = 1;
	if (origin_y < dest_y_int)
		sy = 1;
	err = dx + dy;
	while (1)
	{
		if (origin_x >= 0 && origin_x < (int)game->dynamic_layer->width
			&& origin_y >= 0 && origin_y < (int)game->dynamic_layer->height)
		{
			mlx_put_pixel(game->dynamic_layer, origin_x, origin_y, 0xFF0000FF);
		}
		if (origin_x == dest_x_int && origin_y == dest_y_int)
		{
			break ;
		}
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			origin_x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			origin_y += sy;
		}
	}
}
