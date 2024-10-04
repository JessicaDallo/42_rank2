/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_reach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:36:51 by jesilva-          #+#    #+#             */
/*   Updated: 2024/09/30 12:36:53 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vis(t_ff *ff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ff->vis = ft_calloc(ff->height, sizeof(int *));
	if (ff->vis == NULL)
	{
		ft_printf("Error!\n ff->vis, Memory allocation failed\n");
		exit(1);
	}
	while (i < ff->height)
	{
		ff->vis[i] = ft_calloc(ff->width, sizeof(int));
		if (ff->vis[i] == NULL)
		{
			ft_printf("Error!\n ff->vis[%d], Memory allocation failed\n", i);
			exit(1);
		}
		while (j < ff->width)
			ff->vis[i][j++] = 0;
		i++;
	}
}

void	flood_fill(t_ff *ff, int x, int y)
{
	if (x < 0 || y < 0 || x > ff->width || y > ff->height
		|| ff->map[y][x] == '1' || ff->vis[y][x])
	{
		return ;
	}
	ff->vis[y][x] = 1;
	flood_fill(ff, x + 1, y);
	flood_fill(ff, x - 1, y);
	flood_fill(ff, x, y + 1);
	flood_fill(ff, x, y - 1);
}

void	check_player(t_ff *ff, t_map *map)
{
	int	i;
	int	j;
	int	p_t;

	i = 0;
	p_t = 1;
	while (i < ff->height)
	{
		j = 0;
		while (j < ff->width)
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E')
					&& ff->vis[i][j] == 1)
				p_t = 0;
			j++;
		}
		i++;
	}
	if (p_t == 1)
	{
		ft_printf("Error!\nGame impossible to finish, player is trapped!\n");
		free_ff(ff);
		ft_free(map);
		exit(0);
	}
}

void	check_c_e(t_ff *ff, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < ff->height)
	{
		j = 0;
		while (j < ff->width)
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E')
					&& (!ff->vis[i][j]))
			{
				ft_printf("Error\nGame impossible ");
				ft_printf("to finish, %c is trapped!\n", map->map[i][j]);
				free_ff(ff);
				ft_free(map);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	validade_reach(t_map *map)
{
	t_ff	ff;

	ff.map = map->map;
	ff.width = map->width;
	ff.height = map->height;
	init_vis(&ff);
	flood_fill(&ff, map->p_x, map->p_y);
	check_player(&ff, map);
	check_c_e(&ff, map);
	//free_ff(&ff);
}
