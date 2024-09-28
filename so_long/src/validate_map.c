#include "so_long.h"

int	validate_comp(char map, int i, int *height)
{
	static int	e = 0;
	static int	p = 0;
	static int	c = 0;

	if (map == 'E')
		e++;
	else if (map == 'P')
		p++;
	else if (map == 'C')
		c++;
	if (i == *height - 1)
	{
		if (e != 1 || p != 1 || c == 0)
		{
			ft_printf("Error\nInvalid components found in map!\n");
			return (0);
		}
		return (1);
	}
	return (1);
}

int	validate_walls(int *height, int *width, char **map)
{
	int	i;

	i = 0;
	while (i < *width)
	{
		if (map[0][i] != '1' || map[*height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < *height)
	{
		if (map[i][0] != '1' || map[i][*width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_rec(int *height, int *width, char **map)
{
	int	i;
	int	x;

	i = 0;
	while (i < *height)
	{
		x = 0;
		if (ft_check(map[i]) == 1)
			x = 2;
		if ((ft_strlen(map[i]) - x) != *width)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_char(int *height, int *width, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < *height)
	{
		j = 0;
		while (j < *width)
		{
			if (validate_comp(map[i][j], i, height) == 0)
				return (0);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
					&& map[i][j] != 'P' && map[i][j] != 'C')
			{
				ft_printf("Error\nInvalid character found in map!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

//se o mapa for valido retorna 1
int	validate_map(int *height, int *width, char **map)
{
	if (!validate_rec(height, width, map))
	{
		ft_printf("Error\nThe map is not a rectangle!\n");
		return (0);
	}
	if (!validate_char(height, width, map))
		return (0);
	if (!validate_walls(height, width, map))
	{
		ft_printf("Error\nInvalid character found in the wall!\n");
		return (0);
	}
	return (1);
}
