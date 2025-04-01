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

void find_horz_ray_wall_hit(t_horz_wall_hit_data *horz_wall_hit_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data)
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;
    float nextHorzTouchWallX;
    float nextHorzTouchWallY;
    float x_to_check;
    float y_to_check;

    y_intercept = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
    y_intercept += ray_facing_data->is_ray_facing_down ? CUBE_SIZE : 0;

    x_intercept = player->x + (y_intercept - player->y) / tan(ray_angle);

    y_step = CUBE_SIZE;
    y_step *= ray_facing_data->is_ray_facing_up ? -1 : 1;

    x_step = CUBE_SIZE / tan(ray_angle);
    x_step *= (ray_facing_data->is_ray_facing_left && x_step > 0) ? -1 : 1;
    x_step *= (ray_facing_data->is_ray_facing_right && x_step < 0) ? -1 : 1;

    nextHorzTouchWallX = x_intercept;
    nextHorzTouchWallY = y_intercept;
    while(nextHorzTouchWallX >= 0 && nextHorzTouchWallX <= WINDOW_WIDTH && nextHorzTouchWallY >= 0 && nextHorzTouchWallY <= WINDOW_HEIGHT)
    {
        x_to_check = nextHorzTouchWallX;
        y_to_check = nextHorzTouchWallY + (ray_facing_data->is_ray_facing_up ? -1 : 0);

        if (is_wall(x_to_check, y_to_check, player) == 1)
        {
            horz_wall_hit_data->horzwall_hit_x = nextHorzTouchWallX;
            horz_wall_hit_data->horzwall_hit_y = nextHorzTouchWallY;
            horz_wall_hit_data->found_horz_hit = true;
            break;
        }else
        {
            nextHorzTouchWallX += x_step;
            nextHorzTouchWallY += y_step;
        }
    }
}

void find_vert_ray_wall_hit(t_vert_wall_hit_data *vert_wall_hit_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data)
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;
    float next_vert_touch_wall_x;
    float next_vert_touch_wall_y;
    float y_to_check;
    float x_to_check;

    x_intercept = floor(player->x / CUBE_SIZE) * CUBE_SIZE;
    x_intercept += ray_facing_data->is_ray_facing_right ? CUBE_SIZE : 0;

    y_intercept = player->y + (x_intercept - player->x) * tan(ray_angle);

    x_step = CUBE_SIZE;
    x_step *= ray_facing_data->is_ray_facing_left ? -1 : 1;

    y_step = CUBE_SIZE * tan(ray_angle);
    y_step *= (ray_facing_data->is_ray_facing_up && y_step > 0) ? -1 : 1;
    y_step *= (ray_facing_data->is_ray_facing_down && y_step < 0) ? -1 : 1;

    next_vert_touch_wall_x = x_intercept;
    next_vert_touch_wall_y = y_intercept;
    while(next_vert_touch_wall_x >= 0 && next_vert_touch_wall_x <= WINDOW_WIDTH && next_vert_touch_wall_y >= 0 && next_vert_touch_wall_y <= WINDOW_HEIGHT)
    {
        y_to_check = next_vert_touch_wall_y;
        x_to_check = next_vert_touch_wall_x + (ray_facing_data->is_ray_facing_left ? -1 : 0);
        if (is_wall(x_to_check, y_to_check, player) == 1)
        {
            vert_wall_hit_data->vertwall_hit_x = next_vert_touch_wall_x;
            vert_wall_hit_data->vertwall_hit_y = next_vert_touch_wall_y;
            vert_wall_hit_data->found_vert_hit = true;
            break;
        }else
        {
            next_vert_touch_wall_x += x_step;
            next_vert_touch_wall_y += y_step;
        }
    }
}

void inititate_ray_direction_data(t_ray_facing_data *ray_facing_data, float ray_angle)
{
    ray_facing_data->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
    ray_facing_data->is_ray_facing_up = !ray_facing_data->is_ray_facing_down;
    ray_facing_data->is_ray_facing_right = ray_angle < (PI / 2) || ray_angle > (PI * 1.5);
    ray_facing_data->is_ray_facing_left = !ray_facing_data->is_ray_facing_right;
}

void find_distance(t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data, t_player *player)
{
    if (horz_wall_hit_data->found_horz_hit)
    {
        hit_distance_wall->horz = distance_ray2wall(player->x, player->y, horz_wall_hit_data->horzwall_hit_x, horz_wall_hit_data->horzwall_hit_y);
    }else{
        hit_distance_wall->horz = INT_MAX;
    }

    if (vert_wall_hit_data->found_vert_hit)
    {
        hit_distance_wall->vert = distance_ray2wall(player->x, player->y, vert_wall_hit_data->vertwall_hit_x, vert_wall_hit_data->vertwall_hit_y);
    }else{
        hit_distance_wall->vert = INT_MAX;
    }
}

void initiate_wall_hit_data_structs_values(t_horz_wall_hit_data *horz_wall_hit_data, t_vert_wall_hit_data *vert_wall_hit_data)
{
    horz_wall_hit_data->horzwall_hit_x = 0;
    horz_wall_hit_data->horzwall_hit_y = 0;
    horz_wall_hit_data->found_horz_hit = false;

    vert_wall_hit_data->vertwall_hit_x = 0;
    vert_wall_hit_data->vertwall_hit_y = 0;
    vert_wall_hit_data->found_vert_hit = false;
}
