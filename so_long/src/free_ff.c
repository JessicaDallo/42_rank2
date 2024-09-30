#include "so_long.h"

void	free_ff(t_ff *ff)
{
	int	i;

	i = 0;
	if (ff->vis)
	{
		while (i < ff->height)
		{
			free(ff->vis[i]);
			ff->vis[i] = NULL;
			i++;
		}
		free(ff->vis);
		ff->vis = NULL;
	}
}
