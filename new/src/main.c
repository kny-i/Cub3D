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

int launch_cub3d(int argc, char **argv)
{
	t_cub3d info;
	if (is_valid_args(argc, argv) == false)
		return (usage());
//	init_map(&game_info);//why
	parser(argv[1], info.map);
	return (SUCCESS);
}
int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	launch_cub3d(argc, argv);
}
