#include "so_long.h"

void	load_walls(t_map *map)
{
	map->wall_img_d_l = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/do_L.xpm", &map->img_w, &map->img_h);
	map->wall_img_d_r = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/do_R.xpm", &map->img_w, &map->img_h);
	map->wall_img_u_l = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/up_L.xpm", &map->img_w, &map->img_h);
	map->wall_img_u_r = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/up_R.xpm", &map->img_w, &map->img_h);
	map->wall_img_h = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/wall_h.xpm", &map->img_w, &map->img_h);
	map->wall_img_v = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/wall_v.xpm", &map->img_w, &map->img_h);
	map->wall_img_sq = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/wall_sq.xpm", &map->img_w, &map->img_h);
}

void 	load_player(t_map *map)
{
	map->p_u = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/pac_U.xpm", &map->img_w, &map->img_h);
	map->p_d = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/pac_D.xpm", &map->img_w, &map->img_h);
	map->p_l = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/pac_L.xpm", &map->img_w, &map->img_h);
	map->p_r = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/pac_R.xpm", &map->img_w, &map->img_h);
}

void	load_floor(t_map *map)
{
	map->floor_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/floor.xpm", &map->img_w, &map->img_h);
	map->coin_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/col.xpm", &map->img_w, &map->img_h);
	map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"../sprites/exit.xpm", &map->img_w, &map->img_h);
}

void	load_images(t_map *map)
{
	load_walls(map);
	load_floor(map);
	load_player(map);
}
