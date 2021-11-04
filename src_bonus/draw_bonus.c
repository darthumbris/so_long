#include "so_long_bonus.h"

void	draw_image(t_game *game, void *image, int x, int y)
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
			animation_bg(game, &game->loop, j, i);
			if (game->map[i][j] == '1')
				draw_image(game, game->wall->img, j, i);
			else if (game->map[i][j] == 'C')
				animation_fish(game, &game->loop, j, i);
			else if (game->map[i][j] == 'E')
				draw_image(game, game->exit->img, j, i);
			animation_player(game, game->player_x, game->player_y);
			j++;
		}
		i++;
	}
}
