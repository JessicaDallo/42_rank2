#include "so_long.h"

void get_positions(s_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			if(map->map[y][x] == 'P')
			{
				map->p_y = y;
				map->p_x = x;
			}
			else if(map->map[y][x] == 'C')
			{
				map->berry = map->berry + 1;
			}
			x++;
		}
		y++;
	}
	int i = 0;
	while (i < map->height)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
				ft_printf("BERRY GET POSITION %d\n\n", map->berry);
}


void	draw_map(s_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (y == 0 && x == 0)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_u_l, x * map->img_width, y * map->img_height);
				else if (y == 0 && x == map->width - 1)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_u_r, x * map->img_width, y * map->img_height);
				else if (y == map->height - 1 && x == 0)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_d_l, x * map->img_width, y * map->img_height);
				else if (y == map->height - 1 && x == map->width - 1)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_d_r, x * map->img_width, y * map->img_height);
				else if (y == 0 || y == map->height - 1)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_h, x * map->img_width, y * map->img_height);
				else if (x == 0 || x == map->width - 1)
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_v, x * map->img_width, y * map->img_height);
				else
					mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall_img_sq, x * map->img_width, y * map->img_height);
			}
			else if(map->map[y][x] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor_img, x * map->img_width, y * map->img_height);
			else if(map->map[y][x] == 'E')
				{
					if (map->berry == 0)
						mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->exit_img, x * map->img_width, y * map->img_height);
				}
			else if(map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player_img, x * map->img_width, y * map->img_height);
			else if(map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->coin_img, x * map->img_width, y * map->img_height);
			x++;
		}
		y++;
	}
}

void	load_images(s_map *map)
{
	map->player_img = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/pac.xpm", &map->img_width, &map->img_height);
	map->wall_img_d_l = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/do_L.xpm", &map->img_width, &map->img_height);
	map->wall_img_d_r = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/do_R.xpm", &map->img_width, &map->img_height);
	map->wall_img_u_l = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/up_L.xpm", &map->img_width, &map->img_height);
	map->wall_img_u_r = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/up_R.xpm", &map->img_width, &map->img_height);
	map->wall_img_h = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/wall_h.xpm", &map->img_width, &map->img_height);
	map->wall_img_v = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/wall_v.xpm", &map->img_width, &map->img_height);
	map->wall_img_sq = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/wall_sq.xpm", &map->img_width, &map->img_height);
	map->floor_img = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/floor.xpm", &map->img_width, &map->img_height);
	map->coin_img = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/col.xpm", &map->img_width, &map->img_height);
	map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr, "./sprites/exit.xpm", &map->img_width, &map->img_height);
}
