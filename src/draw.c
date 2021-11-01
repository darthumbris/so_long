#include "../so_long.h"

static void	draw_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_image(game, game->img_wall, j, i);
			else if (game->map[i][j] == 'C')
				draw_image(game, game->img_fish, j, i);
			else if (game->map[i][j] == 'E')
				draw_image(game, game->img_exit, j, i);
			else if (game->map[i][j] == '0')
				draw_image(game, game->img_bg, j, i);
			else if (game->map[i][j] == 'P')
				draw_image(game, game->img_player, j, i);
			j++;
		}
		i++;
	}
}
