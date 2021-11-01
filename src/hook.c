#include "../so_long.h"

int	keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		close_game(game);
	else if (keycode == 13)
		printf("w pressed\n");
	else if (keycode == 0)
		printf("a pressed\n");
	else if (keycode == 1)
		printf("s pressed\n");
	else if (keycode == 2)
		printf("d pressed\n");
	return (1);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_bg);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_fish);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

void	hook_calls(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
}
