NAME = libft.a
FLAGS = -Wall -Werror -Wextra -c

SRC = 	ft_bzero.c ft_calloc.c ft_itoa.c\
		ft_memcpy.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strjoin.c ft_strlcpy.c \
		ft_strlen.c ft_substr.c get_next_line.c \

HEADER = libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER) $(BONUS_SRC)

.PHONY: all clean fclean re bonus norm