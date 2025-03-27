#include "../includes/cub3d.h"

void init_mlx(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", true);
	game->dynamic_layer = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->static_layer = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void draw_walls(t_game *game, int base_x_mult, int base_y_mult)
{
    int x;
    int y;

    y = 0;
    while (y < CUBE_SIZE)
    {
        x = 0;
        while (x < CUBE_SIZE)
        {
            mlx_put_pixel(game->static_layer, base_x_mult + x, base_y_mult + y, 0xFFFFFFFF); // White color
            x++;
        }
        y++;
    }
}

void process_map_row(t_str_access *str_access, int i, int *base_x_mult, int *base_y_mult)
{
    int x;
    t_player *player;
    t_map *map;
    t_game *game;

    player = str_access->player;
    map = str_access->map;
    game = str_access->game;
    x = 0;
    while (map->grid[i][x])
    {
        if (map->grid[i][x] == '1')
        {
            draw_walls(game, *base_x_mult, *base_y_mult);
        }else if (map->grid[i][x] == 'N' || map->grid[i][x] == 'S' || map->grid[i][x] == 'E'
            || map->grid[i][x] == 'W')
        {
            player->x = *base_x_mult;
            player->y = *base_y_mult;
        }
        *base_x_mult += CUBE_SIZE;
        x++;
    }
}

void add_static_pixels(t_str_access *str_access)
{
    int add_y;
    int base_x_mult;
    int base_y_mult;
    int i;

    add_y = 1;
    base_x_mult = CUBE_SIZE;
    base_y_mult = CUBE_SIZE;
    i = 0;
    while (i <= str_access->map->map_height)
    {
        process_map_row(str_access, i, &base_x_mult, &base_y_mult);
        add_y++;
        base_x_mult = CUBE_SIZE;
        base_y_mult = CUBE_SIZE * add_y;
        i++;
    }
    mlx_image_to_window(str_access->game->mlx, str_access->game->static_layer, 0, 0);
}

void	keys_hook(mlx_key_data_t keydata, void *param)
{
	t_player *player;

	player = (t_player *)param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS))
			player->walkDirection = +1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
			player->walkDirection = -1;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
			player->turnDirection = +1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
			player->turnDirection = -1;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(player->game->mlx);

		if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
			player->walkDirection = 0;
		else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
			player->walkDirection = 0;
		else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
			player->turnDirection = 0;
		else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
			player->turnDirection = 0;
}


void render(void *param)
{
    t_str_access *str_access = (t_str_access *)param;
    t_game *game;
    t_player *player;
	int		radius;
	float		center_x;
	float		center_y;
	int		x;
	int		y;

	str_access = (t_str_access *)param;
    game = str_access->game;
    player = str_access->player;
	// Clear the image with a color (e.g., black)
	memset(game->dynamic_layer->pixels, 0, game->dynamic_layer->width
		* game->dynamic_layer->height * sizeof(int32_t));
	movePlayer(player);
	// Define the radius of the circle
	radius = MOVING_OBJECT_SIZE / 2;
	// Calculate the center of the circle
	center_x = player->x + radius;
	center_y = player->y + radius;
	// Midpoint circle algorithm (filled circle)
	x = radius;
	y = 0;
    int p = 1 - radius; // Decision parameter
	while (x >= y)
	{
		// Draw horizontal lines to fill the circle
		for (int i = -x; i <= x; i++)
		{
			mlx_put_pixel(game->dynamic_layer, center_x + i, center_y + y,
				0xFF0000FF); // Red color
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
	draw_line(player,
		game,
		player->x + cos(player->rotationAngle) * 40,
		player->y + sin(player->rotationAngle) * 40
	);
	usleep(10000);
}

int main()
{
    t_str_access stru_access;
    t_game *game;
    
	stru_access.map = NULL;
	stru_access.game = NULL;
	stru_access.player = NULL;
	initiate_str_access_values(&stru_access);
    game = stru_access.game;
    initiate_map(stru_access.map);
    initiate_player(stru_access.player, game);
    init_mlx(game);
    add_static_pixels(&stru_access);
	mlx_image_to_window(game->mlx, game->dynamic_layer, 0, 0);
    mlx_loop_hook(game->mlx, render, &stru_access);
    mlx_key_hook(game->mlx, keys_hook, stru_access.player);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    return (0);
}