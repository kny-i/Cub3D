#include "cub3d.h"

void error_message(char *message)
{
	printf(RED"%s\n"STOP, message);
	usage();
	exit(EXIT_FAILURE);
}

