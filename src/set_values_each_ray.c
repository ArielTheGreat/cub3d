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
    (*rays)[counter].isRayFacingUp = ray_directin_data->isRayFacingUp;
    (*rays)[counter].isRayFacingDown = ray_directin_data->isRayFacingDown;
    (*rays)[counter].isRayFacingLeft = ray_directin_data->isRayFacingLeft;
    (*rays)[counter].isRayFacingRight = ray_directin_data->isRayFacingRight;
}

void set_vert_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_vert_wall_hit_data *vert_wall_hit_data, int counter)
{
    (*rays)[counter].distance = hit_distance_wall->vert;
    (*rays)[counter].wallHitX = vert_wall_hit_data->vertWallHitX;
    (*rays)[counter].wallHitY = vert_wall_hit_data->vertWallHitY;
    (*rays)[counter].wasHitVertical = 1;
}

void set_horz_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, int counter)
{
    (*rays)[counter].distance = hit_distance_wall->horz;
    (*rays)[counter].wallHitX = horz_wall_hit_data->horzWallHitX;
    (*rays)[counter].wallHitY = horz_wall_hit_data->horzWallHitY;
    (*rays)[counter].wasHitVertical = 0;
}
