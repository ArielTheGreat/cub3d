#include "../includes/cub3d.h"

void movePlayer(t_player *player)
{
    player->rotationAngle += player->turnDirection * player->turnSpeed;

    float moveStep = player->walkDirection * player->walkSpeed;

    float newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
    float newPlayerY = player->y + sin(player->rotationAngle) * moveStep;

    if (!check_obstacle_blocks(newPlayerX, newPlayerY, player))
    {
        player->x = newPlayerX;
        player->y = newPlayerY;
    }
}

void draw_circle(t_player *player, t_game *game)
{
	int		radius;
	float		center_x;
	float		center_y;
	int		x;
	int		y;

	radius = MOVING_OBJECT_SIZE / 2;
	center_x = player->x + radius;
	center_y = player->y + radius;
	x = radius;
	y = 0;
    int p = 1 - radius;
	while (x >= y)
	{
		for (int i = -x; i <= x; i++)
		{
			mlx_put_pixel(game->dynamic_layer, center_x + i, center_y + y,
				0xFF0000FF);
			mlx_put_pixel(game->dynamic_layer, center_x + i, center_y - y,
				0xFF0000FF);
		}
		for (int i = -y; i <= y; i++)
		{
			mlx_put_pixel(game->dynamic_layer, center_x + i, center_y + x,
				0xFF0000FF);
			mlx_put_pixel(game->dynamic_layer, center_x + i, center_y - x,
				0xFF0000FF);
		}
		y++;
		if (p <= 0)
		{
			p = p + 2 * y + 1;
		}
		else
		{
			x--;
			p = p + 2 * y - 2 * x + 1;
		}
	}
}