#include "../includes/cub3d.h"

void findHorzRayWallHit(t_horz_wall_hit_data *horzWallHitData, float rayAngle, t_player *player, t_ray_directin_data  *ray_directin_data)
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;

    y_intercept = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
    y_intercept += ray_directin_data->isRayFacingDown ? CUBE_SIZE : 0;

    x_intercept = player->x + (y_intercept - player->y) / tan(rayAngle);

    y_step = CUBE_SIZE;
    y_step *= ray_directin_data->isRayFacingUp ? -1 : 1;

    x_step = CUBE_SIZE / tan(rayAngle);
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
            horzWallHitData->horzWallHitX = nextHorzTouchWallX;
            horzWallHitData->horzWallHitY = nextHorzTouchWallY;
            horzWallHitData->foundHorizontalHit = true;
            break;
        }else
        {
            nextHorzTouchWallX += x_step;
            nextHorzTouchWallY += y_step;
        }
    }
}

void findVertRayWallHit(t_vert_wall_hit_data *vertWallHitData, float rayAngle, t_player *player, t_ray_directin_data  *ray_directin_data)
{
    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;

    x_intercept = floor(player->x / CUBE_SIZE) * CUBE_SIZE;
    x_intercept += ray_directin_data->isRayFacingRight ? CUBE_SIZE : 0;

    y_intercept = player->y + (x_intercept - player->x) / tan(rayAngle);

    x_step = CUBE_SIZE;
    x_step *= ray_directin_data->isRayFacingLeft ? -1 : 1;

    y_step = CUBE_SIZE / tan(rayAngle);
    y_step *= (ray_directin_data->isRayFacingUp && x_step > 0) ? -1 : 1;
    y_step *= (ray_directin_data->isRayFacingDown && x_step < 0) ? -1 : 1;

    float nextVertTouchWallX = x_intercept;
    float nextVertTouchWallY = y_intercept;
    while(nextVertTouchWallX >= 0 && nextVertTouchWallX <= WINDOW_WIDTH && nextVertTouchWallY >= 0 && nextVertTouchWallY <= WINDOW_HEIGHT)
    {
        float yToCheck = nextVertTouchWallY;
        float xToCheck = nextVertTouchWallX + (ray_directin_data->isRayFacingLeft ? -1 : 0);

        if (is_wall(xToCheck, yToCheck, player) == 1)
        {
            vertWallHitData->vertWallHitX = nextVertTouchWallX;
            vertWallHitData->vertWallHitY = nextVertTouchWallY;
            vertWallHitData->foundVertWallHit = true;
            break;
        }else
        {
            nextVertTouchWallX += x_step;
            nextVertTouchWallY += y_step;
        }
    }
}

void inititate_ray_direction_data(t_ray_directin_data *ray_directin_data, float rayAngle)
{
    ray_directin_data->isRayFacingDown = rayAngle > 0 && rayAngle < PI;
    ray_directin_data->isRayFacingUp = !ray_directin_data->isRayFacingDown;
    ray_directin_data->isRayFacingRight = rayAngle < (PI / 2) || rayAngle > (PI * 1.5);
    ray_directin_data->isRayFacingLeft = !ray_directin_data->isRayFacingRight;
}

void find_distance(t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horzWallHitData, t_vert_wall_hit_data *vertWallHitData, t_player *player)
{
    if (horzWallHitData->foundHorizontalHit)
    {
        hit_distance_wall->horz = distance_ray2wall(player->x, player->y, horzWallHitData->horzWallHitX, horzWallHitData->horzWallHitY);
    }else{
        hit_distance_wall->horz = INT_MAX;
    }

    if (vertWallHitData->foundVertWallHit)
    {
        hit_distance_wall->vert = distance_ray2wall(player->x, player->y, vertWallHitData->vertWallHitX, vertWallHitData->vertWallHitY);
    }else{
        hit_distance_wall->vert = INT_MAX;
    }
}

void set_values_ray(t_rays *rays, float rayAngle, t_ray_directin_data  *ray_directin_data, int counter)
{
    (*rays)[counter].rayAngle = rayAngle;
    (*rays)[counter].isRayFacingUp = ray_directin_data->isRayFacingUp;
    (*rays)[counter].isRayFacingDown = ray_directin_data->isRayFacingDown;
    (*rays)[counter].isRayFacingLeft = ray_directin_data->isRayFacingLeft;
    (*rays)[counter].isRayFacingRight = ray_directin_data->isRayFacingRight;
}

void set_vert_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_vert_wall_hit_data *vertWallHitData, int counter)
{
    (*rays)[counter].distance = hit_distance_wall->vert;
    (*rays)[counter].wallHitX = vertWallHitData->vertWallHitX;
    (*rays)[counter].wallHitY = vertWallHitData->vertWallHitY;
    (*rays)[counter].wasHitVertical = 1;
}

void set_horz_values_ray(t_rays *rays, t_hit_distance_wall *hit_distance_wall, t_horz_wall_hit_data *horzWallHitData, int counter)
{
    (*rays)[counter].distance = hit_distance_wall->horz;
    (*rays)[counter].wallHitX = horzWallHitData->horzWallHitX;
    (*rays)[counter].wallHitY = horzWallHitData->horzWallHitY;
    (*rays)[counter].wasHitVertical = 0;
}

void initiate_wall_hit_data_structs_values(t_horz_wall_hit_data *horzWallHitData, t_vert_wall_hit_data *vertWallHitData)
{
    horzWallHitData->horzWallHitX = 0;
    horzWallHitData->horzWallHitY = 0;
    horzWallHitData->foundHorizontalHit = false;

    vertWallHitData->foundVertWallHit = false;
    vertWallHitData->vertWallHitX = 0;
    vertWallHitData->vertWallHitY = 0;
}