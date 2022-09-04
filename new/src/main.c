#include "cub3d.h"

bool is_valid_args(int argc, char **argv)
{
	if (argc == 2)
		return (true);
	return (false);
}

int usage(void)
{
	printf(RED"[USAGE]\n"
			  "./cub3d [map.cub]\n"STOP);
	return (FAILURE);
}

void initialize_mlx(t_cub3d *info)
{
	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx,
						&info->map->max_width,
						&info->map->max_height);
}


int launch_cub3d(int argc, char **argv)
{
	t_cub3d info;

	if (is_valid_args(argc, argv) == false)
		return (usage());

	/* parser */
	info.map = parser(argv[1], info.map);
	/* init mlx */

	initialize_mlx(&info);

	debug_parser(info.map);

	/* start game! */
	start_game(&info);


//	start_game(info);

	return (SUCCESS);
}
int main(int argc, char **argv)
{
	setbuf(stderr, NULL);
	launch_cub3d(argc, argv);
}
