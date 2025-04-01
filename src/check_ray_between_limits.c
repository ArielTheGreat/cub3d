/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_between_limits.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:56:17 by frocha            #+#    #+#             */
/*   Updated: 2025/04/01 18:56:19 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_limits_horz_ray(t_ray_wall_hit_horz *horz_ray_data)
{
	if (horz_ray_data->next_horz_touch_wall_x >= 0
		&& horz_ray_data->next_horz_touch_wall_x <= WINDOW_WIDTH
		&& horz_ray_data->next_horz_touch_wall_y >= 0
		&& horz_ray_data->next_horz_touch_wall_y <= WINDOW_HEIGHT)
	{
		return (true);
	}
	return (false);
}

bool	check_limits_vert_ray(t_ray_wall_hit_vert *vert_ray_data)
{
	if (vert_ray_data->next_vert_touch_wall_x >= 0
		&& vert_ray_data->next_vert_touch_wall_x <= WINDOW_WIDTH
		&& vert_ray_data->next_vert_touch_wall_y >= 0
		&& vert_ray_data->next_vert_touch_wall_y <= WINDOW_HEIGHT)
	{
		return (true);
	}
	return (false);
}
