#include "cub3d.h"

int keymap(int key, t_info *info)
{
	if (key == 'a')//key
		;
	else if (key == 'd')
		;
	else if (key == 'w')
		;
	else if (key == 's')
		;
}

int free_all(t_info *info)
{
	//should deal with ft_free
	return (1);
}

void mlx_hooks_and_loop(t_info info)
{
	mlx_hook(info.win_ptr, 2, 1L << 0, keymap, &info);
	//info is param of keymap function.
	mlx_hook(info.win_ptr, 33, 1L << 17, free_all, &info);
//	mlx_hook(info.win_ptr, 12, 1L < 15, rendering, &info);
	mlx_loop(info.mlx_ptr);
}

int main(int argc, char **argv)
{
	t_info info;
	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr, 1000, 1000, "cub3d");//1000 have no meaning size.

	mlx_hooks_and_loop(info);//↑want to get all info.
}