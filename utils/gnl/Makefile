NAME = get_next_line.a
FLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c get_next_line_utils.c

HEADER = get_next_line.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all clean fclean re norm