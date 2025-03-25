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

void process_map_row(t_game *game, int i, int *base_x_mult, int *base_y_mult)
{
    int x;
    
    x = 0;
    while (game->map[i][x])
    {
        if (game->map[i][x] == '1')
        {
            draw_walls(game, *base_x_mult, *base_y_mult);
        }else if (game->map[i][x] == 'N' || game->map[i][x] == 'S' || game->map[i][x] == 'E'
            || game->map[i][x] == 'W')
        {
            game->player_position_x = *base_x_mult;
            game->player_position_y = *base_y_mult;
        }
        *base_x_mult += CUBE_SIZE;
        x++;
    }
}

void add_static_pixels(t_game *game)
{
    int add_y;
    int base_x_mult;
    int base_y_mult;
    int i;

    add_y = 1;
    base_x_mult = CUBE_SIZE;
    base_y_mult = CUBE_SIZE;
    i = 0;
    while (i <= game->map_height)
    {
        process_map_row(game, i, &base_x_mult, &base_y_mult);
        add_y++;
        base_x_mult = CUBE_SIZE;
        base_y_mult = CUBE_SIZE * add_y;
        i++;
    }
    mlx_image_to_window(game->mlx, game->static_layer, 0, 0);
}

void	keys_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player_position_x;
	new_y = game->player_position_y;
	// Calculate new position based on key input
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		new_y -= 5; // Move up
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		new_y += 5; // Move down
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		new_x -= 5; // Move left
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		new_x += 5; // Move right
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	// Check for collision before updating position
    game->player_position_x = new_x;
	game->player_position_y = new_y;
}


void render(void *param)
{
    t_game *game = (t_game *)param;

	int		radius;
	int		center_x;
	int		center_y;
	int		x;
	int		y;

	game = (t_game *)param;
	// Clear the image with a color (e.g., black)
	memset(game->dynamic_layer->pixels, 0, game->dynamic_layer->width
		* game->dynamic_layer->height * sizeof(int32_t));
	// Define the radius of the circle
	radius = MOVING_OBJECT_SIZE / 2;
	// Calculate the center of the circle
	center_x = game->player_position_x + radius;
	center_y = game->player_position_y + radius;
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
		// Update the decision parameter
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
	// Render the image to the window
	mlx_image_to_window(game->mlx, game->dynamic_layer, 0, 0);
}

int main()
{
    t_game game;
    
    game.map = malloc(sizeof(char *) * 10);
    game.map[0] = ft_strdup("111111111111111");
    game.map[1] = ft_strdup("100000000000001");
    game.map[2] = ft_strdup("1000000N0000001");
    game.map[3] = ft_strdup("100000000000001");
    game.map[4] = ft_strdup("100000000000001");
    game.map[5] = ft_strdup("111111111111111");
    game.map[6] = NULL;
    
    game.map_height = 5;
    init_mlx(&game);
    add_static_pixels(&game);
    mlx_loop_hook(game.mlx, render, &game);
    mlx_key_hook(game.mlx, keys_hook, &game);
    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    return (0);
}