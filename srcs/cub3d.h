#ifndef CUB3D_H
#define CUB3D_H

#include <libc.h>
#include "mlx_linux/mlx.h"

typedef struct s_map
{
	char **map_strs;
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
	void *em;//empty
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

#define BUFFER_SIZE 100
#define READ_ERROR -1
#define END_OF_FILE 0
#define NOT_EOF 100
/* gnl_utils.c */
size_t ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif