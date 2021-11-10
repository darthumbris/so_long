#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (game == NULL)
			exit_msg(NULL, "Error: MAlloc failed");
		init_values(game);
		if (!check_conditions(game, argv))
			exit_msg(game, "Error: Invalid map");
		init_game(game);
		draw_canvas(game);
		hook_calls(game);
		mlx_loop(game->mlx);
	}
	else
		exit_msg(NULL, "Error: Invalid input");
	return (0);
}
