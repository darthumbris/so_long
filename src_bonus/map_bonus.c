#include <so_long_bonus.h>
#include <fcntl.h>

char	**read_map(char *file)
{
	int		fd;
	char	*map_line;
	char	*temp_map;
	char	*temp_line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_line = ft_calloc(1, 1);
	while (map_line)
	{
		temp_line = get_next_line(fd);
		if (!temp_line)
			break ;
		temp_map = map_line;
		map_line = ft_strjoin(temp_map, temp_line);
		free(temp_line);
		free(temp_map);
	}
	map = ft_split(map_line, '\n');
	free(map_line);
	close(fd);
	return (map);
}

int	get_map_width(char **map, int height)
{
	int	i;
	int	width;

	i = 1;
	if (!map)
		return (0);
	width = 0;
	if (map[0])
		width = (int)ft_strlen(map[0]);
	while (i < height && width && map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	if (map)
	{
		while (map[height])
			height++;
	}
	return (height);
}

int	check_map(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y && map)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][0] != '1' || map[0][j] != '1' || \
				map[y - 1][j] != '1' || map[i][x - 1] != '1')
				return (0);
			if (j > 0 && j < x && i > 0 && i < y)
				if (map[i][j] != '0' && map[i][j] != 'C' && \
					map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			if (map[i] != NULL)
				free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		map = NULL;
	}
}
