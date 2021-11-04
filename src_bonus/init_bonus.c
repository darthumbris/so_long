#include "so_long_bonus.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map_width = get_map_width(game->map, 1) * 32;
	game->map_height = get_map_height(game->map) * 32;
	game->win = mlx_new_window
		(game->mlx, game->map_width, game->map_height, "So Long");
	init_player(game);
	init_struct(game);
	init_animation(game, (game->bg), "assets/anim/bg");
	init_animation(game, (game->player), "assets/anim/player");
	init_animation(game, (game->fish), "assets/anim/fish");
	game->wall->img = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &game->wall->img_w, &game->wall->img_h);
	game->exit->img = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &game->exit->img_w, &game->exit->img_h);
	game->end->img = mlx_xpm_file_to_image
		(game->mlx, "assets/end.xpm", &game->end->img_w, &game->end->img_h);
	game->fish_collect = 0;
	game->fish_total = 0;
	mlx_clear_window(game->mlx, game->win);
	game->moves = 0;
	ft_putstr_fd("Moves made: 0\r", 1);
	game->endstate = 0;
	game->loop = 1;
	game->direction = 1;
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

int	init_exit(t_game *game)
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

void	init_struct(t_game *game)
{
	game->bg = malloc(sizeof(t_anim));
	game->fish = malloc(sizeof(t_anim));
	game->player = malloc(sizeof(t_anim));
	game->bg = malloc(sizeof(t_anim));
	game->wall = malloc(sizeof(t_img));
	game->exit = malloc(sizeof(t_img));
	game->end = malloc(sizeof(t_img));
}
