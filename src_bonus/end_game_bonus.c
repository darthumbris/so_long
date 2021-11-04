#include "so_long_bonus.h"
#include <stdio.h>

int	end_game(t_game *game)
{
	game->endstate = 1;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	game->win = mlx_new_window
		(game->mlx, game->end->img_w, game->end->img_h, "So Long!");
	mlx_put_image_to_window(game->mlx, game->win, game->end->img, 0, 0);
	hook_calls(game);
	return (0);
}

void	destroy_animations(t_game *game)
{
	mlx_destroy_image(game->mlx, game->bg->frame1.img);
	mlx_destroy_image(game->mlx, game->bg->frame2.img);
	mlx_destroy_image(game->mlx, game->bg->frame3.img);
	mlx_destroy_image(game->mlx, game->bg->frame4.img);
	mlx_destroy_image(game->mlx, game->player->frame1.img);
	mlx_destroy_image(game->mlx, game->player->frame2.img);
	mlx_destroy_image(game->mlx, game->player->frame3.img);
	mlx_destroy_image(game->mlx, game->player->frame4.img);
	mlx_destroy_image(game->mlx, game->fish->frame1.img);
	mlx_destroy_image(game->mlx, game->fish->frame2.img);
	mlx_destroy_image(game->mlx, game->fish->frame3.img);
	mlx_destroy_image(game->mlx, game->fish->frame4.img);
	free(game->bg);
	free(game->player);
	free(game->fish);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->exit->img);
	mlx_destroy_image(game->mlx, game->wall->img);
	mlx_destroy_image(game->mlx, game->end->img);
	destroy_animations(game);
	free(game->wall);
	free(game->exit);
	free(game->end);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}
