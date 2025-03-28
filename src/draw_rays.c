#include "../includes/cub3d.h"

void draw_rays(t_game *game, t_player *player)
{
    float substract_to_get_first_ray = (FOV / 2) * PI / 180;
    float firstRay = player->rotationAngle - substract_to_get_first_ray;
    int counter = 0;
    int limit = 30;
    float addNextRay = (FOV / limit) * PI / 180;
    while(counter < limit)
    {
        draw_line(player,
            game,
            player->x + cos(firstRay) * 40,
            player->y + sin(firstRay) * 40
        );
        firstRay += addNextRay;
        counter++;
    }
}