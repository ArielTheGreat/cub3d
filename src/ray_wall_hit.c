/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:04:25 by frocha            #+#    #+#             */
/*   Updated: 2025/03/31 22:04:26 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void find_horz_ray_wall_hit(t_horz_wall_hit_data *horz_wall_hit_data, float ray_angle, t_player *player, t_ray_directin_data  *ray_directin_data)
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;

    y_intercept = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
    y_intercept += ray_directin_data->isRayFacingDown ? CUBE_SIZE : 0;

    x_intercept = player->x + (y_intercept - player->y) / tan(ray_angle);

    y_step = CUBE_SIZE;
    y_step *= ray_directin_data->isRayFacingUp ? -1 : 1;

    x_step = CUBE_SIZE / tan(ray_angle);
    x_step *= (ray_directin_data->isRayFacingLeft && x_step > 0) ? -1 : 1;
    x_step *= (ray_directin_data->isRayFacingRight && x_step < 0) ? -1 : 1;

    float nextHorzTouchWallX = x_intercept;
    float nextHorzTouchWallY = y_intercept;
    while(nextHorzTouchWallX >= 0 && nextHorzTouchWallX <= WINDOW_WIDTH && nextHorzTouchWallY >= 0 && nextHorzTouchWallY <= WINDOW_HEIGHT)
    {
        float xToCheck = nextHorzTouchWallX;
        float yToCheck = nextHorzTouchWallY + (ray_directin_data->isRayFacingUp ? -1 : 0);

        if (is_wall(xToCheck, yToCheck, player) == 1)
        {
            horz_wall_hit_data->horzWallHitX = nextHorzTouchWallX;
            horz_wall_hit_data->horzWallHitY = nextHorzTouchWallY;
            horz_wall_hit_data->foundHorizontalHit = true;
            break;
        }else
        {
            nextHorzTouchWallX += x_step;
            nextHorzTouchWallY += y_step;
        }
    }
}

void find_vert_ray_wall_hit(t_vert_wall_hit_data *vert_wall_hit_data, float ray_angle, t_player *player, t_ray_directin_data  *ray_directin_data)
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;

    x_intercept = floor(player->x / CUBE_SIZE) * CUBE_SIZE;
    x_intercept += ray_directin_data->isRayFacingRight ? CUBE_SIZE : 0;

    y_intercept = player->y + (x_intercept - player->x) * tan(ray_angle);

    x_step = CUBE_SIZE;
    x_step *= ray_directin_data->isRayFacingLeft ? -1 : 1;

    y_step = CUBE_SIZE * tan(ray_angle);
    y_step *= (ray_directin_data->isRayFacingUp && y_step > 0) ? -1 : 1;
    y_step *= (ray_directin_data->isRayFacingDown && y_step < 0) ? -1 : 1;

    float nextVertTouchWallX = x_intercept;
    float nextVertTouchWallY = y_intercept;
    while(nextVertTouchWallX >= 0 && nextVertTouchWallX <= WINDOW_WIDTH && nextVertTouchWallY >= 0 && nextVertTouchWallY <= WINDOW_HEIGHT)
    {
        float yToCheck = nextVertTouchWallY;
        float xToCheck = nextVertTouchWallX + (ray_directin_data->isRayFacingLeft ? -1 : 0);

        if (is_wall(xToCheck, yToCheck, player) == 1)
        {
            vert_wall_hit_data->vertWallHitX = nextVertTouchWallX;
            vert_wall_hit_data->vertWallHitY = nextVertTouchWallY;
            vert_wall_hit_data->foundVertWallHit = true;
            break;
        }else
        {
            nextVertTouchWallX += x_step;
            nextVertTouchWallY += y_step;
        }
    }
}

void inititate_ray_direction_data(t_ray_directin_data *ray_directin_data, float ray_angle)
{
    ray_directin_data->isRayFacingDown = ray_angle > 0 && ray_angle < PI;
    ray_directin_data->isRayFacingUp = !ray_directin_data->isRayFacingDown;
    ray_directin_data->isRayFacingRight = ray_angle < (PI / 2) || ray_angle > (PI * 1.5);
    ray_directin_data->isRayFacingLeft = !ray_directin_data->isRayFacingRight;
}

void find_distance(t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data, t_player *player)
{
    if (horz_wall_hit_data->foundHorizontalHit)
    {
        hit_distance_wall->horz = distance_ray2wall(player->x, player->y, horz_wall_hit_data->horzWallHitX, horz_wall_hit_data->horzWallHitY);
    }else{
        hit_distance_wall->horz = INT_MAX;
    }

    if (vert_wall_hit_data->foundVertWallHit)
    {
        hit_distance_wall->vert = distance_ray2wall(player->x, player->y, vert_wall_hit_data->vertWallHitX, vert_wall_hit_data->vertWallHitY);
    }else{
        hit_distance_wall->vert = INT_MAX;
    }
}

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

void initiate_wall_hit_data_structs_values(t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data)
{
    horz_wall_hit_data->horzWallHitX = 0;
    horz_wall_hit_data->horzWallHitY = 0;
    horz_wall_hit_data->foundHorizontalHit = false;

    vert_wall_hit_data->vertWallHitX = 0;
    vert_wall_hit_data->vertWallHitY = 0;
    vert_wall_hit_data->foundVertWallHit = false;
}
