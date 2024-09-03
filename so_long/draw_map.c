#include "so_long.h"

void	draw_wall(s_map *map, int y, int x)
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

void	draw_exit(s_map *map, int y, int x)
{
	if (map->berry == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->exit_img, x * map->img_w, y * map->img_h);
	else
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor_img, x * map->img_w, y * map->img_h);
}

void	draw_map(s_map *map)
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
}

void	load_images(s_map *map)
{
	map->p_u = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/pac_U.xpm", &map->img_w, &map->img_h);
	map->p_d = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/pac_D.xpm", &map->img_w, &map->img_h);
	map->p_l = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/pac_L.xpm", &map->img_w, &map->img_h);
	map->p_r = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/pac_R.xpm", &map->img_w, &map->img_h);
	map->wall_img_d_l = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/do_L.xpm", &map->img_w, &map->img_h);
	map->wall_img_d_r = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/do_R.xpm", &map->img_w, &map->img_h);
	map->wall_img_u_l = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/up_L.xpm", &map->img_w, &map->img_h);
	map->wall_img_u_r = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/up_R.xpm", &map->img_w, &map->img_h);
	map->wall_img_h = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/wall_h.xpm", &map->img_w, &map->img_h);
	map->wall_img_v = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/wall_v.xpm", &map->img_w, &map->img_h);
	map->wall_img_sq = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/wall_sq.xpm", &map->img_w, &map->img_h);
	map->floor_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/floor.xpm", &map->img_w, &map->img_h);
	map->coin_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/col.xpm", &map->img_w, &map->img_h);
	map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./sprites/exit.xpm", &map->img_w, &map->img_h);
}
