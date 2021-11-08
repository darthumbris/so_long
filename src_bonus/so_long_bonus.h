#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include "../utils/libft/libft.h"
# include <stdio.h>

# define UP 	13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESCAPE 53
# define NONE	4278190080

typedef unsigned int	t_uint;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}			t_img;

typedef struct s_anim
{
	t_img	*frame1;
	t_img	*frame2;
	t_img	*frame3;
	t_img	*frame4;
}				t_anim;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	unsigned int	color;
	t_anim			*canvas;
	t_anim			*bg;
	t_anim			*player;
	t_anim			*fish;
	t_img			*wall;
	t_img			*exit;
	t_img			*end;
	int				player_x;
	int				player_y;
	int				moves;
	int				map_width;
	int				map_height;
	int				fish_total;
	int				fish_collect;
	int				endstate;
	int				loop;
	int				direction;
	int				frame_c;
}				t_game;

char		**read_map(char *file);
int			check_map(char **map);
int			get_map_height(char **map);
int			get_map_width(char **map, int height);
void		free_map(char **game);

int			check_conditions(t_game *game);
int			check_valid_position(t_game *game, int x, int y);

void		init_game(t_game *game);
int			init_player(t_game *game);
int			init_exit(t_game *game);
int			init_fishes(t_game *game);
void		init_animation_frames(t_game *game, t_anim *anim, char *path);
void		init_struct(t_game *game);
void		init_canvas(t_game *game);
void		init_address(t_game *game);
void		load_textures(t_game *game);

void		draw_image(t_game *game, void *image, int x, int y);
void		draw_background(t_game *game, int x, int y, t_img *canvas_frame);
void		draw_canvas(t_game *game);

void		update_canvas(t_game *game, int x, int y);
void		fill_canvas_frame(t_game *game, t_anim *anim);

t_img		*background_selector(t_game *game);
t_img		*sprite_selector(t_game *game, char c);

t_uint		get_sprite_color(t_img *sprite, int pix_x, int pix_y);
void		pixel_to_canvas(t_img *img, int x, int y, int color);

int			animation_loop(t_game *game);
void		animation_canvas(t_game *game, int *loop);
void		animation_player(t_game *game, int x, int y);

void		hook_calls(t_game *game);
void		player_move(t_game *game, int x, int y);

int			end_game(t_game *game);
int			close_game(t_game *game);
#endif