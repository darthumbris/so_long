#include "so_long.h"

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
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	exit_msg(t_game *game, char *msg)
{
	if (game)
		mlx_destroy_window(game->mlx, game->win);
	ft_putendl_fd(msg, 1);
	exit(0);
}
