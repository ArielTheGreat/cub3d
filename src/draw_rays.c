#include "../includes/cub3d.h"

void check_contacts_grid(float firstRayAngle, t_player *player)
{
    float first_horizontal_contact_y;
    float first_horizontal_contact_x;

    first_horizontal_contact_y = floor(player->y / CUBE_SIZE) * CUBE_SIZE;
    first_horizontal_contact_x = player->x + (cos(firstRayAngle) * CUBE_SIZE);

    float y_step = CUBE_SIZE;
    float x_step = CUBE_SIZE / tan(firstRayAngle);

    int y_to_check = (first_horizontal_contact_y / CUBE_SIZE);
    int x_to_check = (first_horizontal_contact_x / CUBE_SIZE);
    while(!is_wall(y_to_check, x_to_check, player))
    {
        y_to_check += y_step;
        x_to_check += x_step;
    }
    printf("Y: %d ", y_to_check);
    printf("X: %d\n", x_to_check);

    int distance_ray2wall = sqrt((x_to_check - player->x) * (x_to_check - player->x) + (y_to_check - player->y) * (y_to_check - player->y));

    draw_line(player,
        player->game,
        player->x + cos(firstRayAngle) * distance_ray2wall,
        player->y + sin(firstRayAngle) * distance_ray2wall
    );
}

void draw_rays(t_game *game, t_player *player)
{
    (void)game;
    float substract_to_get_first_ray = (FOV / 2) * (PI / 180);
    float firstRayAngle = player->rotationAngle - substract_to_get_first_ray;
    int counter = 0;
    int limit = 1;
    float addAngleNextRay = (FOV / limit) * PI / 180;
    while(counter < limit)
    {
        check_contacts_grid(firstRayAngle, player);
        firstRayAngle += addAngleNextRay;
        counter++;
    }
}