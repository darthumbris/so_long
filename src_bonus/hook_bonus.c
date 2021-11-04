#include "so_long_bonus.h"

static int	keypress(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		close_game(game);
	else if (keycode == UP && game->endstate != 1)
	{
		player_move(game, 0, -1);
		game->direction = 3;
	}
	else if (keycode == LEFT && game->endstate != 1)
	{
		player_move(game, -1, 0);
		game->direction = 2;
	}
	else if (keycode == DOWN && game->endstate != 1)
	{
		player_move(game, 0, 1);
		game->direction = 4;
	}
	else if (keycode == RIGHT && game->endstate != 1)
	{
		player_move(game, 1, 0);
		game->direction = 1;
	}
	return (1);
}

void	hook_calls(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, animation_loop, game);
}
