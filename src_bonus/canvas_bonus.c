#include <so_long_bonus.h>

void	init_canvas(t_game *game)
{
	game->canvas.frame1.img = NULL;
	game->canvas.frame2.img = NULL;
	game->canvas.frame3.img = NULL;
	game->canvas.frame4.img = NULL;
	game->canvas.frame1.img = mlx_new_image
		(game->mlx, game->map_width, game->map_height);
	game->canvas.frame2.img = mlx_new_image
		(game->mlx, game->map_width, game->map_height);
	game->canvas.frame3.img = mlx_new_image
		(game->mlx, game->map_width, game->map_height);
	game->canvas.frame4.img = mlx_new_image
		(game->mlx, game->map_width, game->map_height);
}

void	draw_canvas_frame(int x, int y, t_img *canvas_frame, t_game *game)
{
	int				pix_x;
	int				pix_y;
	unsigned int	color;
	t_img			*sprite;

	pix_y = 0;
	sprite = sprite_selector(game, game->map[y][x]);
	if (game->map[y][x] != '0' || game->map[y][x] != 'P')
		draw_background(game, x, y, canvas_frame);
	while (pix_y < 32)
	{
		pix_x = 0;
		while (pix_x < 32)
		{
			if (sprite)
				color = get_sprite_color(sprite, pix_x, pix_y);
			if (color != NONE)
				pixel_to_canvas(canvas_frame,
					(x * 32) + pix_x, (y * 32) + pix_y,
					color);
			pix_x++;
		}
		pix_y++;
	}
}

void	draw_background(t_game *game, int x, int y, t_img *canvas_frame)
{
	int				pix_x;
	int				pix_y;
	t_img			*bg;
	unsigned int	color;

	pix_y = 0;
	bg = background_selector(game);
	while (pix_y < 32)
	{
		pix_x = 0;
		while (pix_x < 32)
		{
			if (bg)
				color = get_sprite_color(bg, pix_x, pix_y);
			if (color != NONE)
				pixel_to_canvas(canvas_frame,
					(x * 32) + pix_x, (y * 32) + pix_y,
					color);
			pix_x++;
		}
		pix_y++;
	}
}

void	fill_canvas_frame(t_game *game, t_anim *anim)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->frame_c == 1)
				draw_canvas_frame(x, y, &anim->frame1, game);
			else if (game->frame_c == 2)
				draw_canvas_frame(x, y, &anim->frame2, game);
			else if (game->frame_c == 3)
				draw_canvas_frame(x, y, &anim->frame3, game);
			else if (game->frame_c == 4)
				draw_canvas_frame(x, y, &anim->frame4, game);
			x++;
		}
		y++;
	}
}
