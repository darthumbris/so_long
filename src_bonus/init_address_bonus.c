#include "so_long_bonus.h"

static void	init_img_address(t_img *img)
{
	img->addr = mlx_get_data_addr
		(img->img, &(img->bpp), &(img->line_length), &(img->endian));
}

static void	init_anim_address(t_anim *anim)
{
	init_img_address(&anim->frame1);
	init_img_address(&anim->frame2);
	init_img_address(&anim->frame3);
	init_img_address(&anim->frame4);
}

void	init_address(t_game *game)
{
	init_img_address(&game->wall);
	init_img_address(&game->exit);
	init_img_address(&game->end);
	init_anim_address(&game->player);
	init_anim_address(&game->canvas);
	init_anim_address(&game->bg);
	init_anim_address(&game->fish);
}
