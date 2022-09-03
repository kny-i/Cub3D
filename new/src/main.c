#include "cub3d.h"

bool is_valid_args(int argc, char **argv)
{
	return (true);
}

int usage()
{
	printf(RED"[USAGE]\n"
			  "./cub3d [map.cub3d]\n"STOP);
	return (1);
}

int launch_cub3d(int argc, char **argv)
{
	if (is_valid_args(argc, argv) == true)
		return (usage());

	return (0);
}

int main(int argc, char **argv)
{
	launch_cub3d(argc, argv);
}

