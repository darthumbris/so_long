#include <so_long_bonus.h>

void	moves_to_string(t_game *game)
{
	char	*nbr;

	nbr = ft_itoa(game->moves);
	free(game->moves_str);
	game->moves_str = ft_strjoin("Moves: ", nbr);
	free(nbr);
}
