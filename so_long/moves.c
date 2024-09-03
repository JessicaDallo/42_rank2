#include "so_long.h"

void	ft_win(s_map *map)
{
	ft_printf("PARABENS!!\n");
	ft_free(map);
	exit(0);
}

void	ft_move(s_map *map, int n_y, int n_x)
{
	static int	on_exit = 0;

	if (map->map[n_y][n_x] == '1')
		return ;
	if (map->map[n_y][n_x] == 'C')
		map->berry--;
	if (map->map[n_y][n_x] == 'E' && map->berry == 0)
		ft_win(map);
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

void	move_player(s_map *map, int m_y, int m_x)
{
	int	n_x;
	int	n_y;

	n_y = map->p_y + m_y;
	n_x = map->p_x + m_x;
	if (n_x >= 0 && n_x < map->width && n_y >= 0 && n_y < map->height)
	{
		ft_move(map, n_y, n_x);
	}
	draw_map(map);
}

int	press_key(int key, s_map *map)
{
	if (key == KEY_W)
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
		ft_free(map);
		exit (1);
	}
	return (0);
}
