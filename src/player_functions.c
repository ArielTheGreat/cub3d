#include "../includes/cub3d.h"

void movePlayer(t_player *player)
{
    player->rotationAngle += player->turnDirection * player->turnSpeed;

    float moveStep = player->walkDirection * player->walkSpeed;

    float newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
    float newPlayerY = player->y + sin(player->rotationAngle) * moveStep;

    player->x = newPlayerX;
    player->y = newPlayerY;
}