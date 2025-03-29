#include "../includes/cub3d.h"

void init_mlx(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", true);
	game->dynamic_layer = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->static_layer = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
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
			player->turnDirection = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
			player->turnDirection = +1;
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
	t_rays rays;

	str_access = (t_str_access *)param;
    game = str_access->game;
    player = str_access->player;
	memset(game->dynamic_layer->pixels, 0, game->dynamic_layer->width
		* game->dynamic_layer->height * sizeof(int32_t));
	movePlayer(player);
	draw_circle(player, game);
	castAllRays(player, &rays);
	renderRays(player, &rays);
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
	stru_access.player->map = stru_access.map;
    init_mlx(game);
    add_static_pixels(&stru_access);
	mlx_image_to_window(game->mlx, game->dynamic_layer, 0, 0);
    mlx_loop_hook(game->mlx, render, &stru_access);
    mlx_key_hook(game->mlx, keys_hook, stru_access.player);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    return (0);
}