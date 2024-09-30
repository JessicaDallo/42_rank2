#include "so_long.h"

void	free_ff(t_ff *ff)
{
	int	i;

	i = 0;
	ft_destroy(map);
	if (map->map)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
}
