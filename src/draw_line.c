#include "../includes/cub3d.h"

void draw_line(t_player *player, t_game *game, float dest_x, float dest_y) {
    float origin_x = player->x;
    float origin_y = player->y;
    int dx = fabs(dest_x - origin_x);
    int dy = -fabs(dest_y - origin_y);
    int sx = (origin_x < dest_x) ? 1 : -1;
    int sy = (origin_y < dest_y) ? 1 : -1;
    int err = dx + dy;
    int e2;
    printf("DDD\n");

    while (1) {
        // Draw pixel (replace with your graphics library's function)
        mlx_put_pixel(game->dynamic_layer, origin_x, origin_y, 0xFFFFFFFF); // White
        
        if (origin_x == dest_x && origin_y == dest_y)
        {
            printf("BGGGG\n");
            break;
        }
        e2 = 2 * err;
        if (e2 >= dy) { // Horizontal step
            err += dy;
            origin_x += sx;
        }
        if (e2 <= dx) { // Vertical step
            err += dx;
            origin_y += sy;
        }
    }
}