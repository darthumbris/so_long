#include <so_long_bonus.h>

int	check_valid_enemy_position(t_game *game, int x, int y)
{
	return (game->map[y][x] == '0' && \
		y != game->player_y && x != game->player_x);
}

static int	check_enemy_player_collision(t_game *game, int x, int y)
{
	if (game->player_x == x && game->player_y == y)
		return (1);
	return (0);
}

static void	move_enemy(t_game *game, t_enemy *crab, int x, int y)
{
	if (check_enemy_player_collision(game, crab->x + x, crab->y + y))
		game_over(game);
	else if (game->map[crab->y + y][crab->x + x] == '0')
	{
		game->map[crab->y][crab->x] = '0';
		game->map[crab->y + y][crab->x + x] = 'F';
		crab->x += x;
		crab->y += y;
	}
	else
	{
		if (crab->direction == 1)
			crab->direction = 2;
		else if (crab->direction == 2)
			crab->direction = 1;
		else if (crab->direction == 3)
			crab->direction = 4;
		else if (crab->direction == 4)
			crab->direction = 3;
	}
}

void	move_enemies(t_game *game)
{
	t_enemy	*save;

	save = game->crabs;
	while (game->crabs)
	{
		if (game->crabs->direction == 1)
			move_enemy(game, game->crabs, 1, 0);
		else if (game->crabs->direction == 2)
			move_enemy(game, game->crabs, -1, 0);
		else if (game->crabs->direction == 3)
			move_enemy(game, game->crabs, 0, -1);
		else if (game->crabs->direction == 4)
			move_enemy(game, game->crabs, 0, 1);
		game->crabs = game->crabs->next;
	}
	game->crabs = save;
}
