#include "so_long.h"


void move_player(s_map *map, int m_y, int m_x, s_image *image)
{
	int n_x;
	int n_y;
	ft_printf("%p ponteiro \n", image->mlx_ptr);
	
	n_y = map->p_y + m_y;
	n_x = map->p_x + m_x;
	printf("MOVES\n");
	printf("Current position: player_y = %d, player_x = %d\n", map->p_y, map->p_x);
	printf("New position: n_y = %d, n_x = %d\n", n_y, n_x);
	printf("Map size: height = %d, width = %d\n", map->height, map->width);

	if (n_x >= 0 && n_x < map->width && n_y >= 0 && n_y < map->height) 
	{
    		if (map->map[n_y][n_x] != '1') 
		{  // Corrigido para comparar com '1' (caractere) em vez de 1 (inteiro)
       			 map->map[map->p_y][map->p_x] = '0';
       			 map->map[n_y][n_x] = 'P';
       			// map->p_x = n_x;
        		//map->p_y = n_y;
    		}
		else 
       			printf("Invalid move: Out of bounds\n");
	}
	ft_printf("%p ponteiro \n", image->mlx_ptr);
	draw_map(image, map);
}

void cleanup(s_image *image) 
{
    if (image->player_img)
        mlx_destroy_image(image->mlx_ptr, image->player_img);
    if (image->wall_img_u_l)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_u_l);
    if (image->wall_img_u_r)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_u_r);
    if (image->wall_img_d_l)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_d_l);
    if (image->wall_img_d_r)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_d_r);
    if (image->wall_img_h)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_h);
    if (image->wall_img_v)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_v);
    if (image->wall_img_sq)
        mlx_destroy_image(image->mlx_ptr, image->wall_img_sq);
    if (image->coin_img)
        mlx_destroy_image(image->mlx_ptr, image->coin_img);
    if (image->exit_img)
        mlx_destroy_image(image->mlx_ptr, image->exit_img);
    if (image->floor_img)
        mlx_destroy_image(image->mlx_ptr, image->floor_img);
    if (image->win_ptr)
        mlx_destroy_window(image->mlx_ptr, image->win_ptr);
    if (image->mlx_ptr) {
        mlx_destroy_display(image->mlx_ptr);
        free(image->mlx_ptr);
	}
}

//tenho que usar um int para que a função hook funcione 
int press_key(int key, s_map *map, s_image *image)
{
	 if (key == KEY_W )
	 {
		printf("PRESSKEY\n");
		printf("player %d -> y, %d -> x\n", map->p_y, map->p_x);
		ft_printf("%p ponteiro PRESS KEY\n", image->mlx_ptr);
		ft_printf("%d\n", key);
		move_player(map, -1, 0, image); //função para chamar o image, e a posicão y e x
	 }
	// else if (key == KEY_A)
	// 	move_player(image, -1, 0);
	// else if (key == KEY_S)
	// 	move_player(image, 0, 1);
	// else if (key == KEY_D)
	// 	move_player(image, 1, 0);
	if (key == KEY_ESC)
	{
		ft_printf("Successfully completed\n");
		exit (1);
		
		//mlx_loop_end(image->mlx_ptr);
		//cleanup(image);
		//mlx_loop_end(image->mlx_ptr);
		//mlx_destroy_window(image, image->win_ptr);
	}
	return (0);
}