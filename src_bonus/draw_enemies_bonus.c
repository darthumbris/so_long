#include <so_long_bonus.h>

void	draw_enemies(t_game *game)
{
	t_enemy	*save;

	save = game->crabs;
	while (game->crabs && game->endstate != 1)
	{
		if (game->crabs->direction == 1)
			draw_image
			(game, game->crab.frame1.img, game->crabs->x, game->crabs->y);
		else if (game->crabs->direction == 2)
			draw_image
			(game, game->crab.frame2.img, game->crabs->x, game->crabs->y);
		else if (game->crabs->direction == 3)
			draw_image
			(game, game->crab.frame3.img, game->crabs->x, game->crabs->y);
		else if (game->crabs->direction == 4)
			draw_image
			(game, game->crab.frame4.img, game->crabs->x, game->crabs->y);
		game->crabs = game->crabs->next;
	}
	game->crabs = save;
}
