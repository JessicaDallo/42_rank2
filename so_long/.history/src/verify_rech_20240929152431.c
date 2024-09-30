#include "so_long.h"

void	init_vis(t_ff *ff)
{
	int	i;
	int	j;

	i = 0;
	ff->vis = ft_calloc(ff->height, sizeof(int *));
	if (ff->vis == NULL)
	{
		ft_printf("Error!\n ff->vis, Memory allocation failed");
		exit(1);
	}
	while (i < ff->height)
	{
		ff->vis[i] = ft_calloc(ff->width, sizeof(int));
		if (ff->vis[i] == NULL)
		{
			ft_printf("Error!\n ff->vis[%d], Memory allocation failed", i);
			exit(1);
		}
		while (j < ff->width)
			ff->vis[i][j++] = 0;
		i++;
	}
}

void	flood_fill(t_ff *ff, int x, int y)
{
	if(x < 0 || y < 0 || x > ff->width || y > ff->height || ff->map[x][y] == '1' || ff->vis[x][y])
		return ;
	ff->vis[x][y] = 1;
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
	p_t = 0;
	while (i < ff->height)
	{
		j = 0;
		while (j < ff->width)
		{
			if ((ff->map[i][j] == 'C' || ff->map[i][j] == 'E') && ff->vis[i][j] == 1)

		}
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
	check_player(ff, map);
}