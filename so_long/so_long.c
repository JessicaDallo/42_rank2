#include "so_long.h"

int main(int ac, char **av)
{
	s_map map;
	s_image image;
	//int i = 0;

	if(ac != 2)
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
	ft_memset (&image, 0 ,sizeof(s_image));
	image.mlx_ptr = mlx_init();
	ft_printf("%p ponteiro \n", image.mlx_ptr);
	image.win_ptr = mlx_new_window(image.mlx_ptr, 640, 480, "so_long");
	ft_printf("%p ponteiro \n", image.mlx_ptr);
	load_images(&image);
	ft_printf("%p ponteiro \n", image.mlx_ptr);
	get_positions(&map);
	ft_printf("%p ponteiro \n", image.mlx_ptr);
	draw_map(&image, &map);
	ft_printf("%p ponteiro \n", image.mlx_ptr);
	mlx_hook(image.win_ptr,  2, 1L << 0,press_key, &map);
	ft_printf("%p ponteiro1 \n", image.mlx_ptr);
	// Entrar no loop de eventos
	mlx_loop(image.mlx_ptr);
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