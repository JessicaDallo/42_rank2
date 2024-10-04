#include "so_long.h"

char	**init_map(int *height)
{
	char	**map;

	map = ft_calloc(sizeof(char *), *height + 1);
	if (!map)
	{
		perror("Erro ao alocar memória para o mapa");
		return (NULL);
	}
	return (map);
}

void	get_width(int *height, int *width, char **map)
{
	int	x;

	x = 0;
	if (ft_check(map[0]) == 1)
		x = 2;
	if (*height > 0 && map[0] != NULL)
		*width = (strlen(map[0]) - x);
	else
		*width = 0;
}

void	get_height(const char *file, int *height)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Erro ao abrir o arquivo");
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

char	**to_fill(char **map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	free(line);
	return (map);
}

char	**read_map(const char *file, int *width, int *height)
{
	int		fd;
	char	**map;

	*height = 0;
	fd = open(file, O_RDONLY);
	get_height(file, height);
	map = init_map(height);
	map = to_fill(map, fd);
	get_width(height, width, map);
	if (!validate_map(height, width, map))
	{
		ft_free_array(map);
		ft_printf("Invalid map!\n");
		return (NULL);
	}
	close(fd);
	return (map);
}
