#include "cub3d.h"

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
	debug_parser(info.map);

	is_valid_map(info.map);
	//debug_parser(info.map);

	/* init mlx */
	initialize_mlx(&info);

	/* start game! */
	start_game(&info);

	/* mlxs */
	mlx_loop(info.mlx);
	return (SUCCESS);
}

void sample(void);
int main(int argc, char **argv)
{
//	setbuf(stderr, NULL);
	launch_cub3d(argc, argv);
//	sample();
}

//void sample(void)
//{
//	char *str = "     Hello";
//	printf("%s", skip_space_str(str));
//}
