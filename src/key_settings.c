#include "cub3d.h"

int key_settings(int key, t_cub3d *info)
{
	if (key == ESC_KEY)
		the_end();
	if (key == W_KEY)
		moving_forward(info);
	if (key == S_KEY)
		moving_backward(info);
	if (key == A_KEY)
		moving_rightside(info);
	if (key == D_KEY)
		moving_leftside(info);
	if (key == LOOKING_LEFT_KEY)
		looking_leftside(info);
	if (key == LOOKING_RIGHT_KEY)
		looking_rightside(info);
	return (0);
}
