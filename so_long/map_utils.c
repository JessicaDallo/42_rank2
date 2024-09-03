#include "so_long.h"

void	get_map_size(s_map *map)
{
	map->win_h = map->height * 32;
	map->win_w = map->width * 32;
}

void	get_positions(s_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				map->p_y = y;
				map->p_x = x;
			}
			else if (map->map[y][x] == 'C')
			{
				map->berry = map->berry + 1;
			}
			x++;
		}
		y++;
	}
}

int	check_map(char *str, char av[0])
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		ft_printf("Please try again with a map.ber! \n");
		ft_printf("%s <map_file.ber>\n", av[0]);
		return (0);
	}
	return (1);
}
