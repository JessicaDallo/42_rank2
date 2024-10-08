/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:38:00 by jesilva-          #+#    #+#             */
/*   Updated: 2024/09/30 12:38:02 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_array(char **map, int *height)
{
	int	i;

	i = 0;
	while (i < *height)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}

void	get_map_size(t_map *map)
{
	map->win_h = map->height * 32;
	map->win_w = map->width * 32;
}

void	get_positions(t_map *map)
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
		ft_printf("%s <map/map_file.ber>\n", p_name);
		return (0);
	}
	else if (!ft_strnstr(str, "map/", ft_strlen(str)))
	{
		ft_printf("Please try again with the corrects informations. \n");
		ft_printf("%s <map/map_file.ber>\n", p_name);
		return (0);
	}
	return (1);
}

void	ft_atribute(t_map *map)
{
	map->berry = 0;
	map->moves = 0;
	map->player_img = map->p_r;
}
