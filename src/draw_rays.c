/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:03:41 by frocha            #+#    #+#             */
/*   Updated: 2025/03/31 22:03:43 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return (angle);
}

int	distance_ray2wall(float origin_x, float origin_y, float destination_x,
		float destination_y)
{
	return (sqrt((destination_x - origin_x) * (destination_x - origin_x)
			+ (destination_y - origin_y) * (destination_y - origin_y)));
}

void	cast_ray(float ray_angle, t_player *player, int counter, t_rays *rays)
{
	t_horz_wall_hit_data	horz_wall_hit_data;
	t_vert_wall_hit_data	vert_wall_hit_data;
	t_ray_facing_data		ray_facing_data;
	t_hit_distance_wall		hit_distance_wall;

	ray_angle = normalize_angle(ray_angle);
	initiate_wall_hit_data_structs_values(&horz_wall_hit_data,
		&vert_wall_hit_data);
	inititate_ray_direction_data(&ray_facing_data, ray_angle);
	find_horz_ray_wall_hit(&horz_wall_hit_data, ray_angle, player,
		&ray_facing_data);
	find_vert_ray_wall_hit(&vert_wall_hit_data, ray_angle, player,
		&ray_facing_data);
	find_distance(&hit_distance_wall, &horz_wall_hit_data, &vert_wall_hit_data,
		player);
	if (hit_distance_wall.vert < hit_distance_wall.horz)
	{
		set_vert_values_ray(rays, &hit_distance_wall, &vert_wall_hit_data,
			counter);
	}
	else
	{
		set_horz_values_ray(rays, &hit_distance_wall, &horz_wall_hit_data,
			counter);
	}
	set_values_ray(rays, ray_angle, &ray_facing_data, counter);
}

void	cast_all_rays(t_player *player, t_rays *rays)
{
	float	ray_angle;
	int		counter;

	ray_angle = player->rotation_angle - (FOV_ANGLE / 2);
	counter = 0;
	while (counter < NUM_RAYS)
	{
		cast_ray(ray_angle, player, counter, rays);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		counter++;
	}
}

void	render_rays(t_player *player, t_rays *rays)
{
	int	counter;

	counter = 0;
	while (counter < NUM_RAYS)
	{
		draw_line(player, player->game, (*rays)[counter].wall_hit_x,
			(*rays)[counter].wall_hit_y);
		counter++;
	}
}
