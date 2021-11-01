#include "../so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map_width = get_map_width(game->map, 1) * 32;
	game->map_height = get_map_height(game->map) * 32;
	game->win = mlx_new_window
		(game->mlx, game->map_width, game->map_height, "So Long");
	game->img_bg = mlx_xpm_file_to_image
		(game->mlx, "assets/bg.xpm", &game->image_width, &game->image_height);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &game->image_width, &game->image_height);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/play.xpm", &game->image_width, &game->image_height);
	game->img_fish = mlx_xpm_file_to_image
		(game->mlx, "assets/fish.xpm", &game->image_width, &game->image_height);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &game->image_width, &game->image_height);
}

static int	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	init_exit(t_game *game)
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
			{
				game->exit_x = j;
				game->exit_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_map(t_game *game)
{
	return (init_player(game) && init_exit(game) && check_collect(game));
}
