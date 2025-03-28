#include "../includes/cub3d.h"

void check_contacts_grid(float firstRayAngle, t_player *player)
{
    float first_horizontal_contact_y;
    float first_horizontal_contact_x;

    first_horizontal_contact_y = floor(player->y / 32) * 32;
    first_horizontal_contact_x = player->x + (cos(HALF_FOV_RADIANS) * 40);

    float y_step = CUBE_SIZE;
    float x_step = 32 / tan(HALF_FOV_RADIANS);

    // if (player->map->grid[(int)y_step][(int)x_step] == '1')
    // {
    //     return (distance);
    // }
}

void draw_rays(t_game *game, t_player *player)
{
    float substract_to_get_first_ray = HALF_FOV_RADIANS;
    float firstRayAngle = player->rotationAngle - substract_to_get_first_ray;
    int counter = 0;
    int limit = 1;
    float addAngleNextRay = (FOV / limit) * PI / 180;
    while(counter < limit)
    {
        check_contacts_grid(firstRayAngle, player);
        draw_line(player,
            game,
            player->x + cos(firstRayAngle) * 40,
            player->y + sin(firstRayAngle) * 40
        );
        firstRayAngle += addAngleNextRay;
        counter++;
    }
}