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

float normalizeAngle(float angle)
{
    angle = remainder(angle,TWO_PI);
    if (angle < 0)
    {
        angle = TWO_PI + angle;
    }
    return (angle);
}

int distance_ray2wall(float origin_x, float origin_y, float destination_x, float destination_y)
{
    return (sqrt((destination_x - origin_x) * (destination_x - origin_x) + (destination_y - origin_y) * (destination_y - origin_y)));
}

void castRay(float rayAngle, t_player *player,int counter, t_rays *rays)
{
    t_horz_wall_hit_data horzWallHitData;
    t_vert_wall_hit_data vertWallHitData;
    t_ray_directin_data  ray_directin_data;
    t_hit_distance_wall  hit_distance_wall;

    rayAngle = normalizeAngle(rayAngle);
    initiate_wall_hit_data_structs_values(&horzWallHitData, &vertWallHitData);
    inititate_ray_direction_data(&ray_directin_data, rayAngle);
    findHorzRayWallHit(&horzWallHitData, rayAngle, player, &ray_directin_data);
    findVertRayWallHit(&vertWallHitData, rayAngle, player, &ray_directin_data);
    find_distance(&hit_distance_wall, &horzWallHitData, &vertWallHitData, player);
    if (hit_distance_wall.vert < hit_distance_wall.horz)
    {
        set_vert_values_ray(rays, &hit_distance_wall, &vertWallHitData, counter);
    }else
    {
        set_horz_values_ray(rays, &hit_distance_wall, &horzWallHitData, counter);
    }
    set_values_ray(rays, rayAngle, &ray_directin_data, counter);
}

void castAllRays(t_player *player,t_rays *rays)
{
    float rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
    int counter = 0;
    while(counter < NUM_RAYS)
    {
        castRay(rayAngle, player, counter, rays);
        rayAngle += FOV_ANGLE / NUM_RAYS;
        counter++;
    }
}

void renderRays(t_player *player, t_rays *rays)
{
    int counter;
    counter = 0;

    while(counter < NUM_RAYS)
    {
        draw_line
        (
            player,
            player->game,
            (*rays)[counter].wallHitX,
            (*rays)[counter].wallHitY
        );
        counter++;
    }
}
