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
	t_draw_line_variables vars;

	vars.init_x = (int)player->x;
	vars.init_y = (int)player->y;
	vars.dest_x = (int)dest_x;
	vars.dest_y = (int)dest_y;
	vars.dx = abs(vars.dest_x - vars.init_x);
	vars.dy = -abs(vars.dest_y - vars.init_y);
	vars.sx = -1;
	vars.sy = -1;
	if (vars.init_x < vars.dest_x)
    vars.sx = 1;
	if (vars.init_y < vars.dest_y)
    vars.sy = 1;
	vars.err = vars.dx + vars.dy;
	while (1)
	{
		if (vars.init_x >= 0 && vars.init_x < (int)game->dynamic_layer->width
			&& vars.init_y >= 0 && vars.init_y < (int)game->dynamic_layer->height)
		{
			mlx_put_pixel(game->dynamic_layer, vars.init_x, vars.init_y, 0xFF0000FF);
		}
		if (vars.init_x == vars.dest_x && vars.init_y == vars.dest_y)
			break ;
            vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			vars.init_x += vars.sx;
		}
		if (vars.e2 <= vars.dx)
		{
			vars.err += vars.dx;
			vars.init_y += vars.sy;
		}
	}
}
