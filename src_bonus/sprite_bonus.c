#include "so_long_bonus.h"

void	load_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &game->wall.img_w, &game->wall.img_h);
	game->exit.img = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &game->exit.img_w, &game->exit.img_h);
	game->end.img = mlx_xpm_file_to_image
		(game->mlx, "assets/end.xpm", &game->end.img_w, &game->end.img_h);
	init_animation_frames(game, (&game->bg), "assets/anim/bg");
	init_animation_frames(game, (&game->player), "assets/anim/player");
	init_animation_frames(game, (&game->fish), "assets/anim/fish");
}

t_img	*sprite_selector(t_game *game, char c)
{
	if (c == 'E')
		return (&game->exit);
	else if (c == 'C')
	{
		if (game->frame_c == 1)
			return (&game->fish.frame1);
		if (game->frame_c == 2)
			return (&game->fish.frame2);
		if (game->frame_c == 3)
			return (&game->fish.frame3);
		if (game->frame_c == 4)
			return (&game->fish.frame4);
	}
	else if (c == '1')
		return (&game->wall);
	else if (c == '0' || c == 'P')
		return (background_selector(game));
	return (NULL);
}

unsigned int	get_sprite_color(t_img *sprite, int x, int y)
{
	if (!sprite)
		return (NONE);
	return (*(unsigned int *)
		(sprite->addr + (x * sprite->bpp / 8 + y * sprite->line_length)));
}

t_img	*background_selector(t_game *game)
{
	if (game->frame_c == 1)
		return (&game->bg.frame1);
	else if (game->frame_c == 2)
		return (&game->bg.frame2);
	else if (game->frame_c == 3)
		return (&game->bg.frame3);
	else if (game->frame_c == 4)
		return (&game->bg.frame4);
	return (NULL);
}
