#include "libft.h"

/*
 * Function: ft_nl_len
 * --------------------
 * This function is used to either get the
 * position of a new line or the length
 * of the string.
 */
int	ft_nl_len(char *str, char c)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	if (c == '\0')
		return (i);
	return (-1);
}

/*
 * Function: ft_strjoin
 * --------------------
 * This function add the buffer to the remainder
 * using ft_calloc to allocate the correct
 * amount of memory and also to null terminate
 * the joined string.
 * It also frees the remainder.
 * the buffer might be needed after this so this
 * gets freed later.
 */
char	*ft_strjoingnl(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		i = 0;
	else
		i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = malloc(i + j + 1);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, i);
	ft_memcpy(ret + i, s2, j + 1);
	return (ret);
}

/*
 * Function: ft_create_shift_free
 * ----------------------------
 * This Functions creates the line
 * to be returned and then shifts
 * the remainder to the left
 * so it is a substr without
 * the line that is returned
 * after that it will free the buff
 * and return the line that was created
 */
char	*ft_create_shift_free(char **remain, char *buff)
{
	char	*line;
	int		i;
	int		j;

	line = ft_create_line(*&remain, buff, 0);
	j = 0;
	i = ft_nl_len(*remain, '\n') + 1;
	while ((*remain)[j + i])
	{
		(*remain)[j] = (*remain)[j + i];
		j++;
	}
	(*remain)[j] = '\0';
	free(buff);
	buff = NULL;
	return (line);
}

/*
 * Function ft_create_line
 * -----------------------
 * This function creates the line
 * to be returned and in the case
 * it is the final return it will
 * also free the buffer and checks
 * if the remain string can be freed
 * and sets it to NULL
 */
char	*ft_create_line(char **remain, char *buff, int final)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = ft_nl_len(*remain, '\n') + 1;
	if (i == 0)
		i = ft_nl_len(*remain, '\0');
	line = ft_calloc((i + 1), sizeof(char));
	while (j < i && line)
	{
		line[j] = (*remain)[j];
		j++;
	}
	if (!final)
		return (line);
	if (*remain)
	{
		free(*remain);
		*remain = NULL;
	}
	free(buff);
	return (line);
}