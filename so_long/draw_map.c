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
			x++;
		}
		y++;
	}
	printf("GET POSITION\n");
	printf("player %d -> y, %d -> x\n", map->p_y, map->p_x);
}


void	draw_map(s_image *image, s_map *map)
{
	int	x;
	int	y;
	ft_printf("%p ponteiro \n", image->mlx_ptr);

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (y == 0 && x == 0)
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_u_l, x * image->img_width, y * image->img_height);
				else if (y == 0 && x == map->width - 1)
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_u_r, x * image->img_width, y * image->img_height);
				else if (y == map->height - 1 && x == 0)
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_d_l, x * image->img_width, y * image->img_height);
				else if (y == map->height - 1 && x == map->width - 1)
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_d_r, x * image->img_width, y * image->img_height);
				else if (y == 0 || y == map->height - 1)
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_h, x * image->img_width, y * image->img_height);
				else if (x == 0 || x == map->width - 1)
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_v, x * image->img_width, y * image->img_height);
				else
					mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->wall_img_sq, x * image->img_width, y * image->img_height);
			}
			else if(map->map[y][x] == '0')
				mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->floor_img, x * image->img_width, y * image->img_height);
			else if(map->map[y][x] == 'E')
				mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->exit_img, x * image->img_width, y * image->img_height);
			else if(map->map[y][x] == 'P')
				mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->player_img, x * image->img_width, y * image->img_height);
			else if(map->map[y][x] == 'C')
				mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->coin_img, x * image->img_width, y * image->img_height);
			x++;
		}
		y++;
	}
	ft_printf("%p ponteiro \n", image->mlx_ptr);
}

void	load_images(s_image *image)
{
	image->player_img = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/pac.xpm", &image->img_width, &image->img_height);
	image->wall_img_d_l = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/do_L.xpm", &image->img_width, &image->img_height);
	image->wall_img_d_r = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/do_R.xpm", &image->img_width, &image->img_height);
	image->wall_img_u_l = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/up_L.xpm", &image->img_width, &image->img_height);
	image->wall_img_u_r = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/up_R.xpm", &image->img_width, &image->img_height);
	image->wall_img_h = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/wall_h.xpm", &image->img_width, &image->img_height);
	image->wall_img_v = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/wall_v.xpm", &image->img_width, &image->img_height);
	image->wall_img_sq = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/wall_sq.xpm", &image->img_width, &image->img_height);
	image->floor_img = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/floor.xpm", &image->img_width, &image->img_height);
	image->coin_img = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/col.xpm", &image->img_width, &image->img_height);
	image->exit_img = mlx_xpm_file_to_image(image->mlx_ptr, "./sprites/exit.xpm", &image->img_width, &image->img_height);
}
