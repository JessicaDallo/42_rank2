#include "so_long.h"

void	move_player(s_map *map, int m_y, int m_x)
{
	static int	on_exit = 0;
	int		n_x;
	int		n_y;
	
	n_y = map->p_y + m_y;
	n_x = map->p_x + m_x;
	if (n_x >= 0 && n_x < map->width && n_y >= 0 && n_y < map->height) 
	{
		if (map->map[n_y][n_x] == '1')
			return ;
		if (map->map[n_y][n_x] == 'C')
				map->berry--;
		if (map->map[n_y][n_x] == 'E' && map->berry == 0) 
		{
			ft_printf("PARABENS!!\n");
			cleanup(map);
			exit(0);
		}
		if (on_exit == 1)
		{
			map->map[map->p_y][map->p_x] = 'E';
			on_exit = 0;
		}
		else 
			map->map[map->p_y][map->p_x] = '0';
		if (map->map[n_y][n_x] == 'E') 
			on_exit = 1;
		map->map[n_y][n_x] = 'P';
		map->p_x = n_x;
		map->p_y = n_y;
		map->moves++;
	}
	ft_printf("%d MOVES \n", map->moves);
	draw_map(map);
}

void	cleanup(s_map *map) 
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
	if (map->map) 
	{
		for (int i = 0; map->map[i] != NULL; i++) 
		{ //arrumar aqui 
			free(map->map[i]);
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

int	press_key(int key, s_map *map)
{
	 if (key == KEY_W )
		move_player(map, -1, 0);
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
	}
	return (0);
}