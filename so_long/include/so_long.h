/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:01:04 by jesilva-          #+#    #+#             */
/*   Updated: 2024/09/30 13:01:08 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_U 65362
# define KEY_DN 65364
# define KEY_L 65361
# define KEY_R 65363

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_ff
{
	char	**map;
	int		**vis;
	int		width;
	int		height;
}	t_ff;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_img;
	void	*p_u;
	void	*p_d;
	void	*p_l;
	void	*p_r;
	void	*wall_img_u_l;
	void	*wall_img_u_r;
	void	*wall_img_d_l;
	void	*wall_img_d_r;
	void	*wall_img_h;
	void	*wall_img_v;
	void	*wall_img_sq;
	void	*coin_img;
	void	*exit_img;
	void	*floor_img;
	char	*addr;
	char	**map;
	int		bpp;
	int		line_len;
	int		endian;
	int		moves;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		berry;
	int		img_w;
	int		img_h;
	int		win_h;
	int		win_w;
}	t_map;

void	ft_destroy_wall(t_map *map);
void	ft_destroy_player(t_map *map);
void	ft_destroy(t_map *map);
void	ft_free(t_map *map);
void	ft_free_array(char **map, int *height);
void	get_map_size(t_map *map);
void	get_positions(t_map *map);
void	ft_atribute(t_map *map);
void	init_vis(t_ff *ff);
void	flood_fill(t_ff *ff, int x, int y);
void	check_player(t_ff *ff, t_map *map);
void	validade_reach(t_map *map);
void	free_ff(t_ff *ff);
void	display_moves(t_map *map);
void	draw_wall(t_map *map, int y, int x);
void	draw_exit(t_map *map, int y, int x);
void	draw_map(t_map *map);
void	load_images(t_map *map);
void	load_walls(t_map *map);
void	load_player(t_map *map);
void	load_floor(t_map *map);
void	ft_win(t_map *map);
void	ft_move(t_map *map, int n_y, int n_x);
void	ft_direction(t_map *map, int key);
void	move_player( t_map *map, int m_x, int m_y, int key);
void	get_height(const char *file, int *height);
void	get_width(int *height, int *width, char **map);

char	**init_map(int *height);
char	**to_fill(char **map, int fd);
char	**read_map(const char *file, int *width, int *height);

int		main(int ac, char **av);
int		validate_comp(char map, int i, int *height);
int		validate_walls(int *height, int *width, char **map);
int		validate_rec(int *height, int *width, char **map);
int		validate_char(int *height, int *width, char **map);
int		validate_map(int *height, int *width, char **map);
int		press_key(int key, t_map *map);
int		close_window(t_map *map);
int		check_map(char *str, char *p_name);

#endif
