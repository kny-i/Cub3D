#include "cub3d.h"

void escape(void)//finally should free_all
{
	exit(EXIT_FAILURE);
}

#define ESC 65307

int keymap(int key, t_info *info)
{
	if (key == ESC)
		escape();
	if (key == 'a')//key
		;
	else if (key == 'd')
		;
	else if (key == 'w')
		;
	else if (key == 's')
		;
}
