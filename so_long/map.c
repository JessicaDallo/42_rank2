#include "so_long.h"
#include <string.h>

int	check_map(char *str, char av[0])
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		ft_printf("Please try again with a map.ber! \n");
		ft_printf("%s <map_file.ber>\n",av[0]);
		return (0);
	}
	return (1);
}

char	**init_map(int *height)
{
	char **map;
	map = ft_calloc(sizeof(char*), *height + 1);
	if (!map)
	{
		perror("Erro ao alocar memória para o mapa");
		return NULL;
	}
	return (map);
}

void	get_width(int *height, int *width, char **map)
{
	int x;

	x = 0;
	if(ft_check(map[0]) == 1)
			x = 2;
	if (*height > 0 && map[0] != NULL)
		*width = (strlen(map[0]) - x);
	else
		*width = 0;
}

void	get_height(const char *file, int *height)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		ft_printf("Erro ao abrir o arquivo");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		(*height)++;
		free(line);
	}
	close(fd);
}

char	**read_map(const char *file, int *width, int *height)
{
	int fd;
	char *line;
	char **map;
	int i;

	i = 0;
	*height = 0;
	fd = open(file, O_RDONLY);
	get_height(file, height);
	map = init_map(height);
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	get_width(height, width, map);
	if (!validate_map(height, width, map))
	{
		ft_printf("Invalid map!\n");
		return NULL;
	}
	free(line);
	close(fd);
	return map;
}