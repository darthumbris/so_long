#include "so_long_bonus.h"
#include <stdio.h>

void	init_animation(t_game *game, t_anim *anim, char *path)
{
	char	*frame1;
	char	*frame2;
	char	*frame3;
	char	*frame4;

	frame1 = ft_strjoin(path, "/frame1.xpm");
	frame2 = ft_strjoin(path, "/frame2.xpm");
	frame3 = ft_strjoin(path, "/frame3.xpm");
	frame4 = ft_strjoin(path, "/frame4.xpm");
	anim->frame1.img = mlx_xpm_file_to_image
		(game->mlx, frame1, &anim->frame1.img_w, &anim->frame1.img_h);
	anim->frame2.img = mlx_xpm_file_to_image
		(game->mlx, frame2, &anim->frame2.img_w, &anim->frame2.img_h);
	anim->frame3.img = mlx_xpm_file_to_image
		(game->mlx, frame3, &anim->frame3.img_w, &anim->frame3.img_h);
	anim->frame4.img = mlx_xpm_file_to_image
		(game->mlx, frame4, &anim->frame4.img_w, &anim->frame4.img_h);
	free(frame1);
	free(frame2);
	free(frame3);
	free(frame4);
}

int	animation_loop(t_game *game)
{
	if (game->endstate != 1)
	{
		draw_map(game);
		game->loop++;
	}
	return (1);
}

void	animation_bg(t_game *game, int *loop, int x, int y)
{
	if (*loop == 5)
	{
		draw_image(game, game->bg->frame1.img, x, y);
		game->frame_c = 1;
	}
	else if (*loop == 10)
	{
		draw_image(game, game->bg->frame2.img, x, y);
		game->frame_c = 2;
	}
	else if (*loop == 15)
	{
		draw_image(game, game->bg->frame3.img, x, y);
		game->frame_c = 3;
	}
	else if (*loop == 20)
	{
		draw_image(game, game->bg->frame4.img, x, y);
		game->frame_c = 4;
	}
	else if (*loop > 25)
		*loop = 0;
}

void	animation_fish(t_game *game, int *loop, int x, int y)
{
	if (*loop == 5)
	{
		draw_image(game, game->fish->frame1.img, x, y);
		game->frame_c = 1;
	}
	else if (*loop == 10)
	{
		draw_image(game, game->fish->frame2.img, x, y);
		game->frame_c = 2;
	}
	else if (*loop == 15)
	{
		draw_image(game, game->fish->frame3.img, x, y);
		game->frame_c = 3;
	}
	else if (*loop == 20)
	{
		draw_image(game, game->fish->frame4.img, x, y);
		game->frame_c = 4;
	}
	else if (*loop > 25)
		*loop = 0;
}

void	animation_player(t_game *game, int x, int y)
{
	if (game->direction == 1)
		draw_image(game, game->player->frame1.img, x, y);
	else if (game->direction == 2)
		draw_image(game, game->player->frame2.img, x, y);
	else if (game->direction == 3)
		draw_image(game, game->player->frame3.img, x, y);
	else if (game->direction == 4)
		draw_image(game, game->player->frame4.img, x, y);
}
