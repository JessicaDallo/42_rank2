#include "so_long.h"

int	close_window(s_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	s_map	map;

	if (ac != 2)
	{
		ft_printf("Please try again with the corrects informations. \n");
		ft_printf("%s <map_file.ber>\n", av[0]);
		return (1);
	}
	if (!check_map(av[1], av[0]))
		return (0);
	map.map = read_map(av[1], &map.width, &map.height);
	if (!map.map)
		return (1);
	map.berry = 0;
	map.moves = 0;
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 1000, 420, "so_long");
	get_positions(&map);
	load_images(&map);
	draw_map(&map);
	mlx_hook(map.win_ptr, 2, 1L << 0, press_key, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
