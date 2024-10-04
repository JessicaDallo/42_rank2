#include "so_long.h"

void	display_moves(t_map *map)
{
	char	*moves;
	char	*msg;

	moves = ft_itoa(map->moves);
	msg = ft_strjoin("MOVES: ", moves);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 40, 0xFF0000, msg);
	free(moves);
	free(msg);
}

void	draw_wall(t_map *map, int y, int x)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall_img_u_l, x * map->img_w, y * map->img_h);
	else if (y == 0 && x == map->width - 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall_img_u_r, x * map->img_w, y * map->img_h);
	else if (y == map->height - 1 && x == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall_img_d_l, x * map->img_w, y * map->img_h);
	else if (y == map->height - 1 && x == map->width - 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall_img_d_r, x * map->img_w, y * map->img_h);
	else if (y == 0 || y == map->height - 1)
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->wall_img_h, x * map->img_w, y * map->img_h);
	else if (x == 0 || x == map->width - 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall_img_v, x * map->img_w, y * map->img_h);
	else
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall_img_sq, x * map->img_w, y * map->img_h);
}

void	draw_exit(t_map *map, int y, int x)
{
	if (map->berry == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->exit_img, x * map->img_w, y * map->img_h);
	else
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor_img, x * map->img_w, y * map->img_h);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = -1;
		while (x++ < map->width)
		{
			if (map->map[y][x] == '1')
				draw_wall(map, y, x);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->floor_img, x * map->img_w, y * map->img_h);
			else if (map->map[y][x] == 'E')
				draw_exit(map, y, x);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->player_img, x * map->img_w, y * map->img_h);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->coin_img, x * map->img_w, y * map->img_h);
		}
		y++;
	}
	display_moves(map);
}