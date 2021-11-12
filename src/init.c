#include <so_long.h>

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
	init_img(game);
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->fish_collect = 0;
	game->fish_total = 0;
	game->endstate = 0;
}

void	init_game(t_game *game)
{
	game->map_width = game->map_width * 32;
	game->map_height = game->map_height * 32;
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->map_width, game->map_height, "So Long");
	game->bg.img = mlx_xpm_file_to_image
		(game->mlx, "assets/bg2.xpm", &game->bg.img_w, &game->bg.img_h);
	game->wall.img = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &game->wall.img_w, &game->wall.img_h);
	game->player.img = mlx_xpm_file_to_image
		(game->mlx, "assets/play.xpm", \
		&game->player.img_w, &game->player.img_h);
	game->fish.img = mlx_xpm_file_to_image
		(game->mlx, "assets/fish.xpm", &game->fish.img_w, &game->fish.img_h);
	game->exit.img = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &game->exit.img_w, &game->exit.img_h);
	game->end.img = mlx_xpm_file_to_image
		(game->mlx, "assets/end.xpm", &game->end.img_w, &game->end.img_h);
	mlx_clear_window(game->mlx, game->win);
	ft_putstr_fd("Moves made: 0\r", 1);
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
