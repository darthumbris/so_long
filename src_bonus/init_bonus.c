#include "so_long_bonus.h"

static void	init_values(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	game->map_width = get_map_width(game->map, 1) * 32;
	game->map_height = get_map_height(game->map) * 32;
	game->fish_collect = 0;
	game->fish_total = 0;
	game->endstate = 0;
	game->loop = 1;
	game->direction = 1;
	game->color = 0;
	game->frame_c = 1;
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

void	init_struct(t_game *game)
{
	game->bg = malloc(sizeof(t_anim));
	game->fish = malloc(sizeof(t_anim));
	game->player = malloc(sizeof(t_anim));
	game->canvas = malloc(sizeof(t_anim));
	game->wall = (t_img *)malloc(sizeof(t_img));
	game->exit = malloc(sizeof(t_img));
	game->end = malloc(sizeof(t_img));
}

void	init_game(t_game *game)
{
	init_values(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->map_width, game->map_height, "So Long");
	mlx_clear_window(game->mlx, game->win);
	init_struct(game);
	load_textures(game);
	init_canvas(game);
	init_address(game);
	ft_putstr_fd("Moves made: 0\r", 1);
}
