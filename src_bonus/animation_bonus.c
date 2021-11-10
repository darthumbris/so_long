#include "so_long_bonus.h"

void	init_animation_frames(t_game *game, t_anim *anim, char *path)
{
	char	*frame1_p;
	char	*frame2_p;
	char	*frame3_p;
	char	*frame4_p;

	frame1_p = ft_strjoin(path, "/frame1.xpm");
	frame2_p = ft_strjoin(path, "/frame2.xpm");
	frame3_p = ft_strjoin(path, "/frame3.xpm");
	frame4_p = ft_strjoin(path, "/frame4.xpm");
	anim->frame1.img = NULL;
	anim->frame2.img = NULL;
	anim->frame3.img = NULL;
	anim->frame4.img = NULL;
	anim->frame1.img = mlx_xpm_file_to_image
		(game->mlx, frame1_p, &anim->frame1.img_w, &anim->frame1.img_h);
	anim->frame2.img = mlx_xpm_file_to_image
		(game->mlx, frame2_p, &anim->frame2.img_w, &anim->frame2.img_h);
	anim->frame3.img = mlx_xpm_file_to_image
		(game->mlx, frame3_p, &anim->frame3.img_w, &anim->frame3.img_h);
	anim->frame4.img = mlx_xpm_file_to_image
		(game->mlx, frame4_p, &anim->frame4.img_w, &anim->frame4.img_h);
	free(frame1_p);
	free(frame2_p);
	free(frame3_p);
	free(frame4_p);
}

int	animation_loop(t_game *game)
{
	if (game->endstate != 1)
	{
		animation_canvas(game, &game->loop);
		animation_player(game, game->player_x, game->player_y);
		mlx_string_put(game->mlx, game->win, 0, 12, 0, game->moves_str);
		game->loop++;
	}
	return (1);
}

void	animation_canvas(t_game *game, int *loop)
{
	if (*loop == 5)
	{
		draw_image(game, game->canvas.frame1.img, 0, 0);
		game->frame_c = 1;
	}
	else if (*loop == 10)
	{
		draw_image(game, game->canvas.frame2.img, 0, 0);
		game->frame_c = 2;
	}
	else if (*loop == 15)
	{
		draw_image(game, game->canvas.frame3.img, 0, 0);
		game->frame_c = 3;
	}
	else if (*loop == 20)
	{
		draw_image(game, game->canvas.frame4.img, 0, 0);
		game->frame_c = 4;
	}
	else if (*loop > 25)
		*loop = 0;
}

void	animation_player(t_game *game, int x, int y)
{
	if (game->direction == 1)
		draw_image(game, game->player.frame1.img, x, y);
	else if (game->direction == 2)
		draw_image(game, game->player.frame2.img, x, y);
	else if (game->direction == 3)
		draw_image(game, game->player.frame3.img, x, y);
	else if (game->direction == 4)
		draw_image(game, game->player.frame4.img, x, y);
}
