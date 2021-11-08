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

void	destroy_animations(t_anim *anim, t_game *game)
{
	mlx_destroy_image(game->mlx, anim->frame1->img);
	mlx_destroy_image(game->mlx, anim->frame2->img);
	mlx_destroy_image(game->mlx, anim->frame3->img);
	mlx_destroy_image(game->mlx, anim->frame4->img);
	free(anim->frame1);
	free(anim->frame2);
	free(anim->frame3);
	free(anim->frame4);
	free(anim);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->exit->img);
	mlx_destroy_image(game->mlx, game->wall->img);
	mlx_destroy_image(game->mlx, game->end->img);
	destroy_animations(game->canvas, game);
	destroy_animations(game->bg, game);
	destroy_animations(game->player, game);
	destroy_animations(game->fish, game);
	free(game->wall);
	free(game->exit);
	free(game->end);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}
