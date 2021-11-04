#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include "../utils/gnl/get_next_line.h"
# include "../utils/libft/libft.h"

# define UP 	13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESCAPE 53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_p_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}			t_img;

typedef struct s_anim
{
	t_img	frame1;
	t_img	frame2;
	t_img	frame3;
	t_img	frame4;
}				t_anim;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_anim	*bg;
	t_anim	*player;
	t_anim	*fish;
	t_img	*wall;
	t_img	*exit;
	t_img	*end;
	int		player_x;
	int		player_y;
	int		moves;
	int		map_width;
	int		map_height;
	int		fish_total;
	int		fish_collect;
	int		endstate;
	int		loop;
	int		direction;
	int		frame_c;
}				t_game;
char	**read_map(char *file);
int		check_map(char **map);
void	check_frame(t_anim *anim, t_game *game);
int		check_conditions(t_game *game);
int		get_map_height(char **map);
int		get_map_width(char **map, int height);
void	init_game(t_game *game);
int		init_player(t_game *game);
int		init_exit(t_game *game);
int		init_fishes(t_game *game);
void	init_animation(t_game *game, t_anim *anim, char *path);
void	init_struct(t_game *game);
void	draw_map(t_game *game);
void	draw_image(t_game *game, void *image, int x, int y);
void	draw_bg(t_game *game);
void	draw_fish(t_game *game);
void	play_animation(t_game *game, t_anim *anim, int x, int y);
int		animation_loop(t_game *game);
void	animation_bg(t_game *game, int *loop, int x, int y);
void	animation_fish(t_game *game, int *loop, int x, int y);
void	animation_player(t_game *game, int x, int y);
void	hook_calls(t_game *game);
int		check_valid_position(t_game *game, int x, int y);
void	player_move(t_game *game, int x, int y);
void	free_map(char **game);
int		end_game(t_game *game);
int		close_game(t_game *game);
#endif