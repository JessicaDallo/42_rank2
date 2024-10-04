/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:36:41 by jesilva-          #+#    #+#             */
/*   Updated: 2024/09/30 12:36:44 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		ft_printf("Please try again with the corrects informations. \n");
		ft_printf("%s <map/map_file.ber>\n", av[0]);
		return (1);
	}
	if (!check_map(av[1], av[0]))
		return (0);
	map.map = read_map(av[1], &map.width, &map.height);
	if (!map.map)
		return (0);
	map.mlx_ptr = mlx_init();
	get_map_size(&map);
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.win_w, map.win_h, "so_long");
	load_images(&map);
	ft_atribute(&map);
	get_positions(&map);
	validade_reach(&map);
	draw_map(&map);
	mlx_hook(map.win_ptr, 17, 0, close_window, &map);
	mlx_hook(map.win_ptr, 2, 1L << 0, press_key, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
