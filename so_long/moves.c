#include "so_long.h"

void move_player(s_map *map, int m_y, int m_x)
{
    static int on_exit = 0; // Variável para rastrear se o jogador está na saída
    int n_x = map->p_x + m_x;
    int n_y = map->p_y + m_y;

    // Verifica se o mapa e os ponteiros críticos estão inicializados
    if (!map || !map->map || !map->map[map->p_y] || !map->map[map->p_y][map->p_x]) {
        ft_printf("Error: Invalid map or player position\n");
        return;
    }

    // Verifica se o movimento está dentro dos limites do mapa
    if (n_x < 0 || n_x >= map->width || n_y < 0 || n_y >= map->height) {
        ft_printf("Invalid move: Out of bounds\n");
        return;
    }

    // Verifica se a posição de destino é uma parede
    if (map->map[n_y][n_x] == '1') {
        ft_printf("Invalid move: Wall encountered\n");
        return;
    }

    // Movendo-se para uma posição de berry
    if (map->map[n_y][n_x] == 'C') {
        map->berry--;
    }

    // Movendo-se para a saída com todas as berries coletadas
    if (map->map[n_y][n_x] == 'E' && map->berry == 0) {
        ft_printf("PARABENS!!\n");
        cleanup(map);
        exit(0);
    }

    // Atualizando o mapa de acordo com o movimento
    if (on_exit == 1) {
	map->map[map->p_y][map->p_x] = 'E'; // Restaura 'E' se estava na saída
        on_exit = 0;
    } else {
        map->map[map->p_y][map->p_x] = '0'; // Marca a posição anterior como livre
    }

    if (map->map[n_y][n_x] == 'E') {
        on_exit = 1; // Define que agora está na saída
    }

    // Atualiza a posição do jogador
    //map->map[map->p_y][map->p_x] = '0';
    map->map[n_y][n_x] = 'P';
    map->p_x = n_x;
    map->p_y = n_y;
    map->moves++;

    // Exibe o status atual
    ft_printf("%d BERRIES \n", map->berry);
    ft_printf("%d MOVES \n", map->moves);

    // Atualiza o desenho do mapa
    draw_map(map);
}



// void move_player(s_map *map, int m_y, int m_x)
// {
// 	int n_x;
// 	int n_y;
	
// 	n_y = map->p_y + m_y;
// 	n_x = map->p_x + m_x;

// 	if (n_x >= 0 && n_x < map->width && n_y >= 0 && n_y < map->height) 
// 	{
//     		if (map->map[n_y][n_x] != '1') 
// 		{
// 			if(map->map[n_y][n_x] == 'C')
// 				map->berry = map->berry - 1;
// 			else if(map->map[n_y][n_x] == 'E' && map->berry == 0)
// 			{
// 				ft_printf("PARABENS!!");
// 				cleanup(map);
// 				exit(1);
// 			}
// 			map->map[map->p_y][map->p_x] = '0';
// 			map->map[n_y][n_x] = 'P';
// 			map->moves = map->moves + 1;
// 			map->p_x = n_x;
// 			map->p_y = n_y;
// 		}
// 		else
// 			ft_printf("Invalid move: Out of bounds\n");
// 	}
// 	ft_printf("%d BERRIES \n", map->berry);
// 	ft_printf("%d MOVES \n", map->moves);
// 	draw_map(map);
// }

void cleanup(s_map *map) 
{
    if (map->player_img)
        mlx_destroy_image(map->mlx_ptr, map->player_img);
    if (map->wall_img_u_l)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_u_l);
    if (map->wall_img_u_r)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_u_r);
    if (map->wall_img_d_l)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_d_l);
    if (map->wall_img_d_r)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_d_r);
    if (map->wall_img_h)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_h);
    if (map->wall_img_v)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_v);
    if (map->wall_img_sq)
        mlx_destroy_image(map->mlx_ptr, map->wall_img_sq);
    if (map->coin_img)
        mlx_destroy_image(map->mlx_ptr, map->coin_img);
    if (map->exit_img)
        mlx_destroy_image(map->mlx_ptr, map->exit_img);
    if (map->floor_img)
        mlx_destroy_image(map->mlx_ptr, map->floor_img);

    // Liberando o mapa
    if (map->map) {
        for (int i = 0; map->map[i] != NULL; i++) {
            free(map->map[i]);
        }
        free(map->map);
    }

    // Liberando a janela e a display
    if (map->win_ptr)
        mlx_destroy_window(map->mlx_ptr, map->win_ptr);
    if (map->mlx_ptr) {
        mlx_destroy_display(map->mlx_ptr);
        free(map->mlx_ptr);
    }
}

//tenho que usar um int para que a função hook funcione 
int press_key(int key, s_map *map)
{
	// printf("PRESSKEY\n");
	// printf("player %d -> y, %d -> x\n", map->p_y, map->p_x);
	// ft_printf("%p ponteiro PRESS KEY\n", map->mlx_ptr);
	// ft_printf("%d\n", key);
	 if (key == KEY_W )
	 {
		move_player(map, -1, 0); //função para chamar o map, e a posicão y e x
	 }
	else if (key == KEY_A)
		move_player(map, 0, -1);
	else if (key == KEY_S)
		move_player(map, 1, 0);
	else if (key == KEY_D)
		move_player(map, 0, 1);
	if (key == KEY_ESC)
	{
		ft_printf("Successfully completed\n");
		cleanup(map);
		exit (1);
		
		//mlx_loop_end(map->mlx_ptr);
		//cleanup(map);
		//mlx_loop_end(map->mlx_ptr);
		//mlx_destroy_window(map, map->win_ptr);
	}
	return (0);
}