# ifndef SO_LONG_H
# define SO_LONG_H

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_data
{
	char	*addr;
	char	**map;
	int	bpp;
	int	line_len;
	int	endian;
	int	width;
	int	height;
	int	p_x;
	int	p_y;
//	int	n_x;
	//int	n_y;
	int	berry;
} s_map;

typedef struct s_image
{
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
	int	img_width;
	int	img_height;

} s_image;

int main(int ac, char **av);

//map
int	check_map(char *str, char av[0]);
void	get_height(const char *file, int *height);
void	get_width(int *height, int *width, char **map);
char	**init_map(int *height);
char	**read_map(const char *file, int *width, int *height);

//validate map
int	validate_comp(char map, int i, int *height);
int	validate_rec(int *height, int *width,char **map);
int	validate_map(int *height, int *width, char **map);
int	validate_char(int *height, int *width, char **map);
int	validate_walls(int *height, int *width, char **map);

//draw_map
void	get_positions(s_map *map); //achar onde deixar.
void	load_images(s_image *image);
void	draw_map(s_image *image, s_map *map);

//moves
int press_key(int key, s_map *map, s_image *image);
void move_player( s_map *map, int m_x, int m_y, s_image *image);
//void exit_image(s_image image);

# endif
