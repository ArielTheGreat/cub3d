/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_each_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:51:52 by frocha            #+#    #+#             */
/*   Updated: 2025/03/31 22:51:53 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_values_ray(t_rays *rays, float ray_angle, t_ray_directin_data  *ray_directin_data, int counter)
{
    (*rays)[counter].ray_angle = ray_angle;
    (*rays)[counter].is_ray_facing_up = ray_directin_data->is_ray_facing_up;
    (*rays)[counter].is_ray_facing_down = ray_directin_data->is_ray_facing_down;
    (*rays)[counter].is_ray_facing_left = ray_directin_data->is_ray_facing_left;
    (*rays)[counter].is_ray_facing_right = ray_directin_data->is_ray_facing_right;
}

void set_vert_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_vert_wall_hit_data *vert_wall_hit_data, int counter)
{
    (*rays)[counter].distance = hit_distance_wall->vert;
    (*rays)[counter].wall_hit_x = vert_wall_hit_data->vertwall_hit_x;
    (*rays)[counter].wall_hit_y = vert_wall_hit_data->vertwall_hit_y;
    (*rays)[counter].was_hit_vertical = 1;
}

void set_horz_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, int counter)
{
    (*rays)[counter].distance = hit_distance_wall->horz;
    (*rays)[counter].wall_hit_x = horz_wall_hit_data->horzwall_hit_x;
    (*rays)[counter].wall_hit_y = horz_wall_hit_data->horzwall_hit_y;
    (*rays)[counter].was_hit_vertical = 0;
}
