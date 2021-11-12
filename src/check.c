#include <so_long.h>

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

static int	check_filetype(char *file)
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

int	check_conditions(t_game *game, char **argv)
{
	if (check_filetype(argv[1]))
	{
		game->map = read_map(argv[1]);
		if (game->map == NULL)
		{
			free_map(game->map);
			exit_msg(NULL, "Error: Invalid input");
		}
		game->map_height = get_map_height(game->map);
		game->map_width = get_map_width(game->map, game->map_height);
		if (check_map(game->map, game->map_width, game->map_height))
			if (init_player(game) && check_exit(game) && init_fishes(game))
				return (1);
	}
	return (0);
}
