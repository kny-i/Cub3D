#include "cub3d.h"

void initialize_mlx(t_cub3d *info)
{
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "team:CRI");
}

int launch_cub3d(int argc, char **argv)
{
	t_cub3d *info;

	if (is_valid_args(argc, argv) == false)
		return (usage());

	/* parser */
	info = ft_calloc(1, sizeof(t_cub3d));
	info = parser(argv[1], info);

	is_valid_map(info->map);
	//debug_parser(info->map);

	/* init mlx */
	initialize_mlx(info);

	/* start game! */
	start_game(info);

	/* mlxs hooks & loop */
	mlx_loop(info->mlx);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	launch_cub3d(argc, argv);
}
