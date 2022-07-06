#ifndef CUB_H
#define CUB_H

#include <libc.h>
#include "mlx_linux/mlx.h"


#define KEYPRESSMASK 1L<<0
#define KEYPRESS 2

typedef struct s_vars {
	void *mlx;
	void *win;
} t_vars;

#endif