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


void second(void)
{
	void *mlx = mlx_init();
	t_data img;

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}

void third()
{
	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, 1920, 1080, "new york");

	t_data img;
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								 &img.line_length, &img.endian);
//	mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
//	first();
//	second();
	third();
}
