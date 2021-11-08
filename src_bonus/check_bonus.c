#include "so_long_bonus.h"

int	check_valid_position(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = game->player_y + y;
	j = game->player_x + x;
	if (!(i >= 0 && i < game->map_height && j >= 0 && j < game->map_width))
		return (0);
	if (game->map[i][j] == '1')
		return (0);
	if (game->map[i][j] == 'C')
	{
		game->fish_collect++;
		game->map[i][j] = '0';
		update_canvas(game, j, i);
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

static int	check_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_conditions(t_game *game)
{
	if (init_player(game) > 0 && check_exit(game) > 0 && init_fishes(game) > 0)
		return (1);
	return (0);
}
