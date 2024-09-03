#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_data
{
	char	*addr;
	char	**map;
	int	bpp;
	int	line_len;
	int	endian;
	int	moves;
	int	width;
	int	height;
	int	p_x;
	int	p_y;
	int	berry;
	int	img_w;
	int	img_h;
	int	win_h;
	int	win_w;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_img;
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
} s_map;

int main(int ac, char **av);

//map
void	get_height(const char *file, int *height);
void	get_width(int *height, int *width, char **map);
char	**init_map(int *height);
char	**read_map(const char *file, int *width, int *height);
char	**preencher(char **map, int fd);

//validate map
int	validate_comp(char map, int i, int *height);
int	validate_rec(int *height, int *width,char **map);
int	validate_map(int *height, int *width, char **map);
int	validate_char(int *height, int *width, char **map);
int	validate_walls(int *height, int *width, char **map);

//draw_map
void	draw_wall(s_map *map, int y, int x);
void	draw_exit(s_map *map, int y, int x);
void	load_images(s_map *map);
void	draw_map(s_map *map);

//moves
void	move_player( s_map *map, int m_x, int m_y);
int	press_key(int key, s_map *map);
void	ft_move(s_map *map, int n_y, int n_x);
void	ft_win(s_map *map);

//free
void	ft_free(s_map *map);
void	ft_destroy(s_map *map);

//map_utils
int	check_map(char *str, char av[0]);
void	get_positions(s_map *map);
void	get_map_size(s_map *map);

#endif