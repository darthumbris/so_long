NAME = so_long

NAME_BONUS = so_long_bonus

LIBFT_DIR = ./libs/libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./libs/mlx

MLX_LIB = $(MLX_DIR)/libmlx.dylib

FLAGS = -Wall -Werror -Wextra -g 

LFLAGS = -framework OpenGL -framework AppKit

INC = -I ./includes

SRC = 	./src/so_long.c \
		./src/map.c \
		./src/init.c \
		./src/draw.c \
		./src/hook.c \
		./src/player.c \
		./src/check.c \
		./src/end_game.c

SRC_BONUS =	./src_bonus/so_long_bonus.c \
			./src_bonus/map_bonus.c \
			./src_bonus/init_bonus.c \
			./src_bonus/draw_bonus.c \
			./src_bonus/hook_bonus.c \
			./src_bonus/player_bonus.c \
			./src_bonus/check_bonus.c \
			./src_bonus/end_game_bonus.c \
			./src_bonus/animation_bonus.c \
			./src_bonus/canvas_bonus.c \
			./src_bonus/sprite_bonus.c \
			./src_bonus/init_address_bonus.c \
			./src_bonus/moves_to_string_bonus.c \
			./src_bonus/draw_enemies_bonus.c \
			./src_bonus/enemy_handling_bonus.c \
			./src_bonus/free_game_bonus.c \
			./src_bonus/init_enemies_bonus.c 

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJ)
	gcc $(FLAGS) $(OBJ) -L. -lmlx $(LIBFT) $(LFLAGS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	cd $(MLX_DIR) && cp ./libmlx.dylib ../../

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MLX_LIB) $(LIBFT) $(OBJ_BONUS)
	gcc $(FLAGS) $(OBJ_BONUS) -L. -lmlx $(LIBFT) $(LFLAGS) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(OBJ_BONUS) libmlx.dylib

fclean:	clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus