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

typedef struct s_player
{
	double x_pos;
	double y_pos;
} t_player;

typedef struct s_picture
{
	void *e;//empty
	void *w;//wall
	void *c;//collectible
	void *e;//exit
	void *p;//player
	size_t size;//size
} t_picture;

typedef struct s_info
{
	void *mlx_ptr;
	void *win_ptr;
	t_map map;
	t_player player;
	t_picture picture;
} t_info;

int keymap(int key, t_info *info);

#endif