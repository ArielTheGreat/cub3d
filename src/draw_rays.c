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

void castRay(float rayAngle, t_player *player)
{
    rayAngle = normalizeAngle(rayAngle);

    int isRayFacingDown = rayAngle > 0 && rayAngle < PI;
    int isRayFacingUp = !isRayFacingDown;
    int isRayFacingRight = rayAngle < (PI / 2) || rayAngle > (PI * 1.5);
    int isRayFacingLeft = !isRayFacingRight;

    float x_intercept;
    float y_intercept;
    float y_step;
    float x_step;

    int foundHorizontalHit = false;
    float horzWallHitX = 0;
    float horzWallHitY = 0;

    y_intercept = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
    y_intercept += isRayFacingDown ? CUBE_SIZE : 0;

    x_intercept = player->x + (y_intercept - player->y) / tan(rayAngle);

    y_step = CUBE_SIZE;
    y_step *= isRayFacingUp ? -1 : 1;

    x_step = CUBE_SIZE / tan(rayAngle);
    x_step *= (isRayFacingLeft && x_step > 0) ? -1 : 1;
    x_step *= (isRayFacingRight && x_step < 0) ? -1 : 1;

    float nextHorzTouchWallX = x_intercept;
    float nextHorzTouchWallY = y_intercept;
    while(nextHorzTouchWallX >= 0 && nextHorzTouchWallX <= WINDOW_WIDTH && nextHorzTouchWallY >= 0 && nextHorzTouchWallY <= WINDOW_HEIGHT)
    {
        float xToCheck = nextHorzTouchWallX;
        float yToCheck = nextHorzTouchWallY + (isRayFacingUp ? -1 : 0);

        if (is_wall(xToCheck, yToCheck, player) == 1)
        {
            horzWallHitX = nextHorzTouchWallX;
            horzWallHitY = nextHorzTouchWallY;
            foundHorizontalHit = true;
            break;
        }else
        {
            nextHorzTouchWallX += x_step;
            nextHorzTouchWallY += y_step;
        }
    }
    int distance_ray2wall = sqrt((horzWallHitX - player->x) * (horzWallHitX - player->x) + (horzWallHitY - player->y) * (horzWallHitY - player->y));
    draw_line(player,
        player->game,
        player->x + cos(rayAngle) * distance_ray2wall,
        player->y + sin(rayAngle) * distance_ray2wall
    );
}

void castAllRays(t_player *player)
{
    float rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
    int counter = 0;
    while(counter < NUM_RAYS)
    {
        castRay(rayAngle, player);
        rayAngle += FOV_ANGLE / NUM_RAYS;
        counter++;
    }
}