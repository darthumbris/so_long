#include "so_long.h"
#include <stdlib.h>

int	check_filetype(char *file)
{
	int	i;

	if (!file)
		return (0);
	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (0);
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || \
		file[i - 3] != 'b' || file[i - 4] != '.')
		return (0);
	return (1);
}

static void	invalid_map(t_game *game, int close)
{
	printf("Error: Invalid map\n");
	if (close)
		close_game(game);
	else
		free_map(game->map);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (check_map(game.map) && check_filetype(argv[1]))
			init_game(&game);
		else
			invalid_map(&game, 0);
		if (!init_map(&game))
			invalid_map(&game, 1);
		draw_map(&game);
		hook_calls(&game);
		mlx_loop(game.mlx);
	}
	else
	{
		printf("Error: Invalid input\n");
		exit(1);
	}
	return (0);
}
