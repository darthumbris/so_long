#include <so_long.h>

int	end_game(t_game *game)
{
	game->endstate = 1;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	game->win = mlx_new_window
		(game->mlx, game->end.img_w, game->end.img_h, "So Long!");
	mlx_put_image_to_window(game->mlx, game->win, game->end.img, 0, 0);
	hook_calls(game);
	return (0);
}

void	free_images(t_game *game)
{
	if (game->player.img != NULL)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->exit.img != NULL)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->end.img != NULL)
		mlx_destroy_image(game->mlx, game->end.img);
	if (game->wall.img != NULL)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->fish.img != NULL)
		mlx_destroy_image(game->mlx, game->fish.img);
	if (game->bg.img != NULL)
		mlx_destroy_image(game->mlx, game->bg.img);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
	return (1);
}

void	exit_msg(t_game *game, char *msg)
{
	if (game)
		mlx_destroy_window(game->mlx, game->win);
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}
