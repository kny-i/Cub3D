#ifndef CUB_H
#define CUB_H

#include <libc.h>
#include "minilibx-linux/mlx.h"


#define KEYPRESSMASK 1L<<0
#define KEYPRESS 2

typedef struct s_vars {
	void *mlx;
	void *win;
} t_vars;

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

#endif