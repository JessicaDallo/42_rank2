#include "so_long.h"

int close_window(s_map *map)
{
    mlx_destroy_window(map->mlx_ptr, map->win_ptr); // Fecha a janela
    exit(0); // Sai do programa
    return (0);
}


int main(int ac, char **av)
{
	s_map map;

	if (ac != 2)
	{
		ft_printf("Please try again with the corrects informations. \n");
		ft_printf("%s <map_file.ber>\n", av[0]);
		return (1);
	}
	if(!check_map(av[1], av[0]))
		return (0);
	map.map =  read_map(av[1], &map.width, &map.height);
	if(!map.map)
		return (1);
	map.berry = 0;
	map.moves = 0;
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 1000, 420, "so_long");
	get_positions(&map);
	load_images(&map);
	draw_map(&map);
	mlx_hook(map.win_ptr,  2, 1L << 0,press_key, &map);
	//mlx_hook(map.win_ptr, 17, 0, close_window, &map);
	// Entrar no loop de eventos
	mlx_loop(map.mlx_ptr);
	//free(map.map);
	// while (i < map.height)
	// {
	// 	ft_printf("%s", map.map[i]);
	// 	free(map.map[i]);
	// 	i++;
	// }

	return (0);
}


	// map.img_ptr = mlx_xpm_file_to_image(map.mlx_ptr, "./sprites/up_L.xpm", &img_width, &img_height);
	//  if (!map.img_ptr)
	// {
	//  // Verifique se a imagem foi carregada corretamente
	// 	printf("Erro ao carregar a imagem.\n");
	// 	return (1);
	// }

	// // Exibir a imagem na tela
	// mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, map.img_ptr, 100, 100);