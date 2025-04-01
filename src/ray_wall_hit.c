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
    t_ray_wall_hit_horz horz_ray_data;

    find_horz_intercepts(&horz_ray_data, ray_angle, player, ray_facing_data);
    find_horz_steps(&horz_ray_data, ray_angle, ray_facing_data);
    while(horz_ray_data.next_horz_touch_wall_x >= 0 && horz_ray_data.next_horz_touch_wall_x <= WINDOW_WIDTH && horz_ray_data.next_horz_touch_wall_y >= 0 && horz_ray_data.next_horz_touch_wall_y <= WINDOW_HEIGHT)
    {
        horz_ray_data.x_to_check = horz_ray_data.next_horz_touch_wall_x;
        horz_ray_data.y_to_check = horz_ray_data.next_horz_touch_wall_y + (ray_facing_data->is_ray_facing_up ? -1 : 0);
        if (is_wall(horz_ray_data.x_to_check, horz_ray_data.y_to_check, player) == 1)
        {
            horz_wall_hit_data->horzwall_hit_x = horz_ray_data.next_horz_touch_wall_x;
            horz_wall_hit_data->horzwall_hit_y = horz_ray_data.next_horz_touch_wall_y;
            horz_wall_hit_data->found_horz_hit = true;
            break;
        }else
        {
            horz_ray_data.next_horz_touch_wall_x += horz_ray_data.x_step;
            horz_ray_data.next_horz_touch_wall_y += horz_ray_data.y_step;
        }
    }
}

void find_vert_ray_wall_hit(t_vert_wall_hit_data *vert_wall_hit_data, float ray_angle, t_player *player, t_ray_facing_data  *ray_facing_data)
{
    t_ray_wall_hit_vert vert_ray_data;

    find_vert_intercepts(&vert_ray_data, ray_angle, player, ray_facing_data);
    find_horz_steps(&vert_ray_data, ray_angle, ray_facing_data);
    while(vert_ray_data.next_vert_touch_wall_x >= 0 && vert_ray_data.next_vert_touch_wall_x <= WINDOW_WIDTH && vert_ray_data.next_vert_touch_wall_y >= 0 && vert_ray_data.next_vert_touch_wall_y <= WINDOW_HEIGHT)
    {
        vert_ray_data.y_to_check = vert_ray_data.next_vert_touch_wall_y;
        vert_ray_data.x_to_check = vert_ray_data.next_vert_touch_wall_x + (ray_facing_data->is_ray_facing_left ? -1 : 0);
        if (is_wall(vert_ray_data.x_to_check, vert_ray_data.y_to_check, player) == 1)
        {
            vert_wall_hit_data->vertwall_hit_x = vert_ray_data.next_vert_touch_wall_x;
            vert_wall_hit_data->vertwall_hit_y = vert_ray_data.next_vert_touch_wall_y;
            vert_wall_hit_data->found_vert_hit = true;
            break;
        }else
        {
            vert_ray_data.next_vert_touch_wall_x += vert_ray_data.x_step;
            vert_ray_data.next_vert_touch_wall_y += vert_ray_data.y_step;
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
