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

    int foundVertWallHit = false;
    float vertWallHitX = 0;
    float vertWallHitY = 0;

    x_intercept = floor(player->x / CUBE_SIZE) * CUBE_SIZE;
    x_intercept += isRayFacingRight ? CUBE_SIZE : 0;

    y_intercept = player->y + (x_intercept - player->x) / tan(rayAngle);

    x_step = CUBE_SIZE;
    x_step *= isRayFacingLeft ? -1 : 1;

    y_step = CUBE_SIZE / tan(rayAngle);
    y_step *= (isRayFacingUp && x_step > 0) ? -1 : 1;
    y_step *= (isRayFacingDown && x_step < 0) ? -1 : 1;

    float nextVertTouchWallX = x_intercept;
    float nextVertTouchWallY = y_intercept;
    while(nextVertTouchWallX >= 0 && nextVertTouchWallX <= WINDOW_WIDTH && nextVertTouchWallY >= 0 && nextVertTouchWallY <= WINDOW_HEIGHT)
    {
        float yToCheck = nextVertTouchWallY;
        float xToCheck = nextVertTouchWallX + (isRayFacingLeft ? -1 : 0);

        if (is_wall(xToCheck, yToCheck, player) == 1)
        {
            vertWallHitX = nextVertTouchWallX;
            vertWallHitY = nextVertTouchWallY;
            foundVertWallHit = true;
            break;
        }else
        {
            nextVertTouchWallX += x_step;
            nextVertTouchWallY += y_step;
        }
    }

    float hitHorizontalDistance = foundHorizontalHit ? distance_ray2wall(player->x, player->y, horzWallHitX, horzWallHitY) : INT_MAX;
    float hitVerticalDistance = foundVertWallHit ? distance_ray2wall(player->x, player->y, vertWallHitX, vertWallHitY) : INT_MAX;

    if (hitVerticalDistance < hitHorizontalDistance)
    {
        (*rays)[counter].distance = hitVerticalDistance;
        (*rays)[counter].wallHitX = vertWallHitX;
        (*rays)[counter].wallHitY = vertWallHitY;
        (*rays)[counter].wasHitVertical = 1;
    }else
    {
        (*rays)[counter].distance = hitHorizontalDistance;
        (*rays)[counter].wallHitX = horzWallHitX;
        (*rays)[counter].wallHitY = horzWallHitY;
        (*rays)[counter].wasHitVertical = 0;
    }
    (*rays)[counter].rayAngle = rayAngle;
    (*rays)[counter].isRayFacingUp = isRayFacingUp;
    (*rays)[counter].isRayFacingDown = isRayFacingDown;
    (*rays)[counter].isRayFacingLeft = isRayFacingLeft;
    (*rays)[counter].isRayFacingRight = isRayFacingRight;
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