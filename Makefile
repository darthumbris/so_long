NAME = so_long

NAME_BONUS = so_long_bonus

LIBFT_DIR = ./utils/libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx

MLX_LIB = libmlx.dylib

FLAGS = -Wall -Werror -Wextra

LFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

INC = -Imlx

SRC_DIR = ./src

SRC = 	$(SRC_DIR)/so_long.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/draw.c \
		$(SRC_DIR)/hook.c \
		$(SRC_DIR)/player.c \
		$(SRC_DIR)/check.c \
		$(SRC_DIR)/end_game.c

SRC_BONUS_DIR = ./src_bonus

SRC_BONUS =	$(SRC_BONUS_DIR)/so_long_bonus.c \
			$(SRC_BONUS_DIR)/map_bonus.c \
			$(SRC_BONUS_DIR)/init_bonus.c \
			$(SRC_BONUS_DIR)/draw_bonus.c \
			$(SRC_BONUS_DIR)/hook_bonus.c \
			$(SRC_BONUS_DIR)/player_bonus.c \
			$(SRC_BONUS_DIR)/check_bonus.c \
			$(SRC_BONUS_DIR)/end_game_bonus.c \
			$(SRC_BONUS_DIR)/animation_bonus.c \
			$(SRC_BONUS_DIR)/canvas_bonus.c \
			$(SRC_BONUS_DIR)/sprite_bonus.c \
			$(SRC_BONUS_DIR)/init_address.c

HEADER = $(SRC_DIR)/so_long.h $(LIBFT_DIR)/libft.h

HEADER_BONUS = $(SRC_BONUS_DIR)/so_long_bonus.h $(LIBFT_DIR)/libft.h

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: minilibx $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	gcc  $(LFLAGS) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: minilibx $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS) $(HEADER_BONUS)
	gcc  $(LFLAGS) $(FLAGS) -fsanitize=address -g3 $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

minilibx:
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX_LIB) ./$(MLX_LIB)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(MLX_LIB) $(OBJ_BONUS)

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re norm bonus