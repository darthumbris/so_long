#include "../so_long.h"
#include <stdio.h>

int	end_game(t_game *game)
{
	game->endstate = 1;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	game->win = mlx_new_window
		(game->mlx, game->end.img_w, game->end.img_h, "So Long!");
	mlx_put_image_to_window(game->mlx, game->win, game->end.img, 0, 0);
	hook_calls(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->bg.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->fish.img);
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->end.img);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}
