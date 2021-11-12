#include <so_long.h>

void	player_move(t_game *game, int x, int y)
{
	if (check_valid_position(game, x, y))
	{
		if (check_valid_position(game, 0, 0) > 0)
			draw_image(game, game->bg.img, game->player_x, game->player_y);
		else
		{
			draw_image(game, game->bg.img, game->player_x, game->player_y);
			draw_image(game, game->exit.img, game->player_x, game->player_y);
		}
		game->player_x += x;
		game->player_y += y;
		game->moves++;
		ft_putstr_fd("Moves made: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\r', 1);
		draw_image(game, game->player.img, game->player_x, game->player_y);
	}
}
