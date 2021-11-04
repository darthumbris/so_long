#include "so_long_bonus.h"

void	player_move(t_game *game, int x, int y)
{
	if (check_valid_position(game, x, y) != 0)
	{
		if (check_valid_position(game, 0, 0) > 0)
			check_frame(game->bg, game);
		else
		{
			check_frame(game->bg, game);
			draw_image(game, game->exit->img, game->player_x, game->player_y);
		}
		game->player_x += x;
		game->player_y += y;
		game->moves++;
		ft_putstr_fd("Moves made: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\r', 1);
		animation_player(game, game->player_x, game->player_y);
	}
}
