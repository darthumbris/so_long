#include "libft.h"

char	*get_next_line(int fd)
{
	char		*buff;
	int			btrd;
	static char	*remain;

	btrd = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff)
		btrd = read(fd, buff, BUFFER_SIZE);
	while (btrd > 0 && buff)
	{
		remain = ft_strjoingnl(remain, buff, btrd, ft_nl_len(remain, '\0'));
		if (ft_nl_len(remain, '\n') != -1)
			return (ft_create_shift_free(&remain, buff));
		btrd = read(fd, buff, BUFFER_SIZE);
	}
	if (btrd != -1 && ft_nl_len(remain, '\n') != -1 && buff)
		return (ft_create_shift_free(&remain, buff));
	else if (btrd != -1 && buff && remain && *remain)
		return (ft_create_line(&remain, buff, 1));
	free(remain);
	free(buff);
	return (NULL);
}
