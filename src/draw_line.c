#include "../includes/cub3d.h"

void draw_line(t_player *player, t_game *game, int dest_x, int dest_y) {
    int dx = fabs(dest_x - player->x);
    int dy = -fabs(dest_y - player->y);
    int sx = (player->x < dest_x) ? 1 : -1;
    int sy = (player->y < dest_y) ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1) {
        // Draw pixel (replace with your graphics library's function)
        mlx_put_pixel(game->dynamic_layer, player->x, player->y, 0xFFFFFFFF); // White
        
        if (player->x == dest_x && player->y == dest_y) break;
        
        e2 = 2 * err;
        if (e2 >= dy) { // Horizontal step
            err += dy;
            player->x += sx;
        }
        if (e2 <= dx) { // Vertical step
            err += dx;
            player->y += sy;
        }
    }
}