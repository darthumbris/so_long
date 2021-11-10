#include "so_long_bonus.h"

static void	init_img(t_game *game)
{
	game->wall.img = NULL;
	game->exit.img = NULL;
	game->end.img = NULL;
	game->wall.addr = NULL;
	game->exit.addr = NULL;
	game->end.addr = NULL;
}

void	init_values(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->moves_str = NULL;
	init_img(game);
	game->color = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->fish_collect = 0;
	game->fish_total = 0;
	game->endstate = 0;
	game->loop = 0;
	game->direction = 0;
	game->frame_c = 0;
}

int	init_player(t_game *game)
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

int	init_fishes(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->fish_total = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->fish_total++;
			j++;
		}
		i++;
	}
	return (game->fish_total);
}

void	init_game(t_game *game)
{
	game->map_width = game->map_width * 32;
	game->map_height = game->map_height * 32;
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->map_width, game->map_height, "So Long");
	mlx_clear_window(game->mlx, game->win);
	game->loop = 1;
	game->direction = 1;
	game->frame_c = 1;
	game->moves_str = ft_strdup("Moves: 0");
	load_textures(game);
	init_canvas(game);
	init_address(game);
	ft_putstr_fd("Moves made: 0\r", 1);
}
