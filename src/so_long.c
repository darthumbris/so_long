#include <so_long.h>

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (game == NULL)
			exit_msg(NULL, "Error: Malloc failed");
		init_values(game);
		if (!check_conditions(game, argv))
			exit_msg(NULL, "Error: Invalid map");
		init_game(game);
		draw_map(game);
		hook_calls(game);
		mlx_loop(game->mlx);
	}
	else
		exit_msg(NULL, "Error: Invalid input");
	return (EXIT_SUCCESS);
}
