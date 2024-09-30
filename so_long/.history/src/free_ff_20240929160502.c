#include "so_long.h"

void	free_ff(t_ff *ff)
{
	int	i;

	i = 0;
	// if (ff->map)
	// {
	// 	while (ff->map[i] != NULL)
	// 	{
	// 		free(ff->map[i]);
	// 		i++;
	// 	}
	// 	free(ff->map);
	// }
	if (ff->vis)
	{
		ft_printf("ff check free\n");
		while (ff->vis[i] != NULL)
		{
			ft_printf("ff while free\n");
			free(ff->vis[i]);
			ff->vis[i] = NULL;
			i++;
		}
	//	free(ff->vis);
		ft_printf("ff finish free\n");
		ff->vis = NULL;
	}
}
