/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercepts_steps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:14:57 by frocha            #+#    #+#             */
/*   Updated: 2025/04/01 13:14:58 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void find_horz_intercepts(t_ray_wall_hit_horz *horz_ray_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data)
{
    horz_ray_data->y_intercept = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
    horz_ray_data->y_intercept += ray_facing_data->is_ray_facing_down ? CUBE_SIZE : 0;

    horz_ray_data->x_intercept = player->x + (horz_ray_data->y_intercept - player->y) / tan(ray_angle);
    horz_ray_data->nextHorzTouchWallX = horz_ray_data->x_intercept;
    horz_ray_data->nextHorzTouchWallY = horz_ray_data->y_intercept;
}

void find_horz_steps(t_ray_wall_hit_horz *horz_ray_data, float ray_angle, t_ray_facing_data  *ray_facing_data)
{
    horz_ray_data->y_step = CUBE_SIZE;
    horz_ray_data->y_step *= ray_facing_data->is_ray_facing_up ? -1 : 1;

    horz_ray_data->x_step = CUBE_SIZE / tan(ray_angle);
    horz_ray_data->x_step *= (ray_facing_data->is_ray_facing_left && horz_ray_data->x_step > 0) ? -1 : 1;
    horz_ray_data->x_step *= (ray_facing_data->is_ray_facing_right && horz_ray_data->x_step < 0) ? -1 : 1;
}