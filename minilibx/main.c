#include "cub.h"

int mlxclose(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void first(void)
{
	t_vars vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1000, "study Cub");
	mlx_hook(vars.win, KEYPRESS, KEYPRESSMASK, mlxclose, &vars);
	mlx_loop(vars.mlx);
}

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void second(void)
{
	void *mlx = mlx_init();
	t_data img;

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}

int	main(int argc, char **argv)
{
	first();
//	second();
}
