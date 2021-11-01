#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "utils/gnl/get_next_line.h"
# include "utils/libft/libft.h"
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_bg;
	void	*img_player;
	void	*img_wall;
	void	*img_exit;
	void	*img_fish;
	int		player_x;
	int		player_y;
	int		map_width;
	int		map_height;
	int		image_width;
	int		image_height;
	int		exit_x;
	int		exit_y;
}				t_game;
char	**read_map(char *file);
int		check_map(char **map);
int		get_map_height(char **map);
int		get_map_width(char **map, int height);
void	init_game(t_game *game);
int		init_map(t_game *game);
void	draw_map(t_game *game);
void	hook_calls(t_game *game);
void	free_map(char **game);
int		close_game(t_game *game);
#endif