#ifndef SO_LONG_H
# define SO_LONG_H
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	bg;
	t_img	player;
	t_img	wall;
	t_img	exit;
	t_img	fish;
	t_img	end;
	t_img	canvas;
	int		player_x;
	int		player_y;
	int		moves;
	int		map_width;
	int		map_height;
	int		fish_total;
	int		fish_collect;
	int		endstate;
}				t_game;
char	**read_map(char *file);
int		check_map(char **map);
int		check_conditions(t_game *game);
int		get_map_height(char **map);
int		get_map_width(char **map, int height);
void	init_game(t_game *game);
int		init_player(t_game *game);
int		init_exit(t_game *game);
int		init_fishes(t_game *game);
void	draw_map(t_game *game);
void	draw_image(t_game *game, void *image, int x, int y);
void	hook_calls(t_game *game);
int		check_valid_position(t_game *game, int x, int y);
void	player_move(t_game *game, int x, int y);
void	free_map(char **game);
int		end_game(t_game *game);
int		close_game(t_game *game);
#endif