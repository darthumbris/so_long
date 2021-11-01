#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);

int		ft_nl_len(char *str, char c);
char	*ft_create_shift_free(char **remain, char *buff);
char	*ft_strjoingnl(char *remain, char const *buff, int btrd, int len);
char	*ft_create_line(char **remain, char *buff, int final);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif