#include <mlx.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data
{
	void *mlx;
	void *win;
} t_data;

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        mlx_pixel_put(data->mlx, data->win, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main()
{
	t_data data;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "draw line");

	draw_line(&data, 100, 30, 50, 500, 0xffcbdb);

	mlx_loop(data.mlx);
	return(0);
}