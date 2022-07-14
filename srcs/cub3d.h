#ifndef CUB3D_H
#define CUB3D_H

#include <libc.h>
#include "mlx_linux/mlx.h"

typedef struct s_map
{
	size_t width;
	size_t height;


	size_t c;//collectibles
	size_t p;//players
	size_t e;//exit
} t_map;

typedef struct s_info
{
	void *mlx_ptr;
	void *win_ptr;
	t_map map;
} t_info;

#endif