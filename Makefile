NAME = so_long

LIBFT_DIR = ./utils/libft

LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./utils/gnl

GNL = $(GNL_DIR)/get_next_line.a

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

HEADER = $(SRC_DIR)/so_long.h $(GNL_DIR)/get_next_line.h

OBJ = $(SRC:%.c=%.o)

all: minilibx $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER) $(GNL)
	gcc  $(LFLAGS) $(OBJ) $(LIBFT) $(GNL) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

minilibx:
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX_LIB) ./$(MLX_LIB)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	rm -f $(OBJ) $(MLX_LIB)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm