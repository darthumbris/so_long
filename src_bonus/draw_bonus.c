#include <so_long_bonus.h>

void	draw_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

void	pixel_to_canvas(t_img *img, int x, int y, int color)
{
	char	*target;

	target = img->addr + (x * (img->bpp / 8) + y * img->line_length);
	*(unsigned int *)target = color;
}

void	draw_canvas(t_game *game)
{
	game->frame_c = 1;
	while (game->frame_c < 5)
	{
		fill_canvas_frame(game, &game->canvas);
		game->frame_c++;
	}
	game->frame_c = 1;
}

void	update_canvas(t_game *game, int x, int y)
{
	int	temp_frame;

	temp_frame = game->frame_c;
	game->frame_c = 1;
	while (game->frame_c < 5)
	{
		if (game->frame_c == 1)
			draw_background(game, x, y, &game->canvas.frame1);
		else if (game->frame_c == 2)
			draw_background(game, x, y, &game->canvas.frame2);
		else if (game->frame_c == 3)
			draw_background(game, x, y, &game->canvas.frame3);
		else if (game->frame_c == 4)
			draw_background(game, x, y, &game->canvas.frame4);
		game->frame_c++;
	}
	game->frame_c = temp_frame;
}
