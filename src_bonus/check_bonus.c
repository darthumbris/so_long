#include "so_long_bonus.h"

int	check_valid_position(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = game->player_y + y;
	j = game->player_x + x;
	if (!(i >= 0 && i < game->map_height && j >= 0 && j < game->map_width))
		return (0);
	if (game->map[i][j] == '1')
		return (0);
	if (game->map[i][j] == 'C')
	{
		game->fish_collect++;
		game->map[i][j] = '0';
	}
	if (game->map[i][j] == 'E')
	{
		if (game->fish_collect == game->fish_total)
			return (end_game(game));
		return (-1);
	}
	ft_putstr_fd("\r", 1);
	return (1);
}

int	check_conditions(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	if (init_player(game) > 0 && init_exit(game) > 0 && init_fishes(game) > 0)
		return (1);
	return (0);
}

void	check_frame(t_anim *anim, t_game *game)
{
	if (game->frame_c == 1)
		draw_image
			(game, anim->frame1.img, game->player_x, game->player_y);
	if (game->frame_c == 2)
		draw_image
			(game, anim->frame2.img, game->player_x, game->player_y);
	if (game->frame_c == 3)
		draw_image
			(game, anim->frame3.img, game->player_x, game->player_y);
	if (game->frame_c == 4)
		draw_image
			(game, anim->frame4.img, game->player_x, game->player_y);
}
