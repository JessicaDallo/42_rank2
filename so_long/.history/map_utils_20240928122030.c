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

int	check_map(char *str, char *p_name)
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		ft_printf("Please try again with the corrects informations. \n");
		ft_printf("%s <map_file.ber>\n", p_name);
		return (0);
	}
	return (1);
}

void	ft_atribute(s_map *map)
{
	map->berry = 0;
	map->moves = 0;
	map->player_img = map->p_r;
}
