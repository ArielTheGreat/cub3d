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

void	find_horz_intercepts(t_ray_wall_hit_horz *horz_ray_data,
		float ray_angle, t_player *player, t_ray_facing_data *ray_facing_data)
{
	horz_ray_data->y_intercept = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
	if (ray_facing_data->is_ray_facing_down)
		horz_ray_data->y_intercept += CUBE_SIZE;
	horz_ray_data->x_intercept = player->x + (horz_ray_data->y_intercept
			- player->y) / tan(ray_angle);
	horz_ray_data->next_horz_touch_wall_x = horz_ray_data->x_intercept;
	horz_ray_data->next_horz_touch_wall_y = horz_ray_data->y_intercept;
}

void	find_horz_steps(t_ray_wall_hit_horz *horz_ray_data, float ray_angle,
		t_ray_facing_data *ray_facing_data)
{
	horz_ray_data->y_step = CUBE_SIZE;
	if (ray_facing_data->is_ray_facing_up)
		horz_ray_data->y_step *= -1;
	horz_ray_data->x_step = CUBE_SIZE / tan(ray_angle);
	if (ray_facing_data->is_ray_facing_left && horz_ray_data->x_step > 0)
		horz_ray_data->x_step *= -1;
	if (ray_facing_data->is_ray_facing_right && horz_ray_data->x_step < 0)
		horz_ray_data->x_step *= -1;
}

void	find_vert_intercepts(t_ray_wall_hit_vert *vert_ray_data,
		float ray_angle, t_player *player, t_ray_facing_data *ray_facing_data)
{
	vert_ray_data->x_intercept = floor(player->x / CUBE_SIZE) * CUBE_SIZE;
	if (ray_facing_data->is_ray_facing_right)
		vert_ray_data->x_intercept += CUBE_SIZE;
	vert_ray_data->y_intercept = player->y + (vert_ray_data->x_intercept
			- player->x) * tan(ray_angle);
	vert_ray_data->next_vert_touch_wall_x = vert_ray_data->x_intercept;
	vert_ray_data->next_vert_touch_wall_y = vert_ray_data->y_intercept;
}

void	find_vert_steps(t_ray_wall_hit_vert *vert_ray_data, float ray_angle,
		t_ray_facing_data *ray_facing_data)
{
	vert_ray_data->x_step = CUBE_SIZE;
	if (ray_facing_data->is_ray_facing_left)
		vert_ray_data->x_step *= -1;
	vert_ray_data->y_step = CUBE_SIZE * tan(ray_angle);
	if (ray_facing_data->is_ray_facing_up && vert_ray_data->y_step > 0)
		vert_ray_data->y_step *= -1;
	if (ray_facing_data->is_ray_facing_down && vert_ray_data->y_step < 0)
		vert_ray_data->y_step *= -1;
}
