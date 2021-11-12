#include <so_long_bonus.h>

static t_enemy	*new_enemy_list(int x, int y, int direction)
{
	t_enemy	*tmp;

	tmp = malloc(sizeof(t_enemy));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->direction = direction;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

static	t_enemy	*last_enemy_in_list(t_enemy *crablst)
{
	if (crablst)
	{
		while (crablst->next)
			crablst = crablst->next;
		return (crablst);
	}
	return (NULL);
}

static void	add_enemy(t_enemy **crablst, t_enemy *new)
{
	t_enemy	*tmp;

	if (crablst)
	{
		if (*crablst == NULL)
			*crablst = new;
		else
		{
			tmp = last_enemy_in_list(*crablst);
			tmp->next = new;
		}
	}
}

static int	set_enemy_data(t_game *game, int x, int y, int *first)
{
	int	direction;

	if (check_valid_enemy_position(game, x, y))
	{
		direction = y % 4 + 1;
		if (*first)
		{
			game->crabs = new_enemy_list(x, y, 1);
			*first = 0;
		}
		else
			add_enemy(&game->crabs, new_enemy_list(x, y, direction));
		game->map[y][x] = 'F';
		game->enemies--;
		return (1);
	}
	return (0);
}

void	init_enemies(t_game *game)
{
	int	first;
	int	x;
	int	y;

	first = 1;
	y = 1;
	check_enemies_amount(game);
	if (game->enemies)
	{
		while (y < ((game->map_height / 32) - 1))
		{
			x = 1;
			while (x < ((game->map_width / 32) - 1) && game->enemies)
			{
				if (set_enemy_data(game, x, y, &first))
					break ;
				x++;
			}
			y++;
		}
	}
}
