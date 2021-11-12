#include <so_long_bonus.h>

static void	free_animations(t_anim *anim, t_game *game)
{
	if (anim->frame1.img != NULL)
		mlx_destroy_image(game->mlx, anim->frame1.img);
	if (anim->frame2.img != NULL)
		mlx_destroy_image(game->mlx, anim->frame2.img);
	if (anim->frame3.img != NULL)
		mlx_destroy_image(game->mlx, anim->frame3.img);
	if (anim->frame4.img != NULL)
		mlx_destroy_image(game->mlx, anim->frame4.img);
}

void	free_images(t_game *game)
{
	if (game->wall.img != NULL)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->exit.img != NULL)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->end.img != NULL)
		mlx_destroy_image(game->mlx, game->end.img);
	if (game->game_over.img != NULL)
		mlx_destroy_image(game->mlx, game->game_over.img);
	free_animations(&game->canvas, game);
	free_animations(&game->bg, game);
	free_animations(&game->player, game);
	free_animations(&game->fish, game);
	free_animations(&game->crab, game);
}

void	free_enemies(t_enemy **crablst)
{
	t_enemy	*tmp;

	if (*crablst)
	{
		while (*crablst)
		{
			tmp = (*crablst)->next;
			free(*crablst);
			*crablst = tmp;
		}
	}
}