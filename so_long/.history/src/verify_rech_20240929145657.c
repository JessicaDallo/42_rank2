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


void	validade_reach(t_map *map)
{
	t_ff	ff;

	ff.map = map->map;
	ff.width = map->width;
	ff.height = map->height;
	init_vis(&ff);
}