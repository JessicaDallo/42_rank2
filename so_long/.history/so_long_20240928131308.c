#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

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
	map.mlx_ptr = mlx_init();
	get_map_size(&map);
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.win_w, map.win_h, "so_long");
	load_images(&map);
	ft_atribute(&map);
	get_positions(&map);
	is_map_valid(&map);
	draw_map(&map);
	mlx_hook(map.win_ptr, 17, 0, close_window, &map);
	mlx_hook(map.win_ptr, 2, 1L << 0, press_key, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
