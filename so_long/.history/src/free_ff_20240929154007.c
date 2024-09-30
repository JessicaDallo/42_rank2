#include "so_long.h"

void	free_ff(t_ff *ff)
{
	int	i;

	i = 0;
	ft_destroy(ff->map);
	if (ff->vis)
	{
		while (ff->vis[i] != NULL)
		{
			free(ff->vis[i]);
			i++;
		}
		free(ff->vis);
	}
	