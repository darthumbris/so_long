#include "../so_long.h"

int	check_valid_position(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = game->player_y + y;
	j = game->player_x + x;
	if (game->map[i][j] == '1')
		return (0);
	if (game->map[i][j] == 'C')
	{
		game->fish_collect++;
		game->map[i][j] = '0';
	}
	if (game->map[i][j] == 'E')
	{
		if (game->fish_collect == game->fish_total)
			return (end_game(game));
		return (-1);
	}
	ft_putstr_fd("\r", 1);
	return (1);
}

int	check_conditions(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	if (init_player(game) > 0 && init_exit(game) > 0 && init_fishes(game) > 0)
		return (1);
	return (0);
}
