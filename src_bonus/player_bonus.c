#include "so_long_bonus.h"

void	player_move(t_game *game, int x, int y)
{
	if (check_valid_position(game, x, y) != 0)
	{
		game->player_x += x;
		game->player_y += y;
		game->moves++;
		ft_putstr_fd("Moves made: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\r', 1);
	}
}
