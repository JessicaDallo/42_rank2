/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:35:58 by jesilva-          #+#    #+#             */
/*   Updated: 2024/09/30 12:36:04 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map)
{
	ft_free(map);
	exit(0);
	return (0);
}

void	ft_destroy_wall(t_map *map)
{
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
}

void	ft_destroy_player(t_map *map)
{
	if (map->p_u)
		mlx_destroy_image(map->mlx_ptr, map->p_u);
	if (map->p_d)
		mlx_destroy_image(map->mlx_ptr, map->p_d);
	if (map->p_l)
		mlx_destroy_image(map->mlx_ptr, map->p_l);
	if (map->p_r)
		mlx_destroy_image(map->mlx_ptr, map->p_r);
}

void	ft_destroy(t_map *map)
{
	ft_destroy_wall(map);
	ft_destroy_player(map);
	if (map->coin_img)
		mlx_destroy_image(map->mlx_ptr, map->coin_img);
	if (map->exit_img)
		mlx_destroy_image(map->mlx_ptr, map->exit_img);
	if (map->floor_img)
		mlx_destroy_image(map->mlx_ptr, map->floor_img);
}

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	ft_destroy(map);
	if (map->map)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
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
