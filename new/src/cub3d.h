#ifndef CUB3D_H
# define CUB3D_H


# include "./color.h"
# include "../libft/libft.h"
# include <libc.h>
# include <stdbool.h>

typedef struct s_data {
	void *mlx;
	void *window;
	void *image;
	char *address;
	size_t bpp;//bits per pixel
	size_t line_length;
	size_t endian;
} t_data;

typedef struct	s_point {
	double		x;
	double		y;
	long long		color;
}				t_point;

typedef struct s_map {
	char **grid;
	size_t width;
	size_t height;
	size_t max_width;
	size_t max_height;
	size_t nb_col;
	size_t nb_row;

	t_point *start_position;

	double angle;
	size_t nb_ray;
	long long ceiling_color;
	long long floor_color;
	char **filepath;

	size_t nb_sprites;
	t_point **sprite_position;
} t_map;

typedef struct s_player {
	t_point *position;
	long long turn_direction;
	long long walk_direction;
	double angle;
	size_t default_spped;
	double rotate_speed;
	double projection;
} t_player;

typedef struct s_ray {
	t_point *collision;
	double dest_wall;
	double angle;
	long long coordination;
} t_ray;

typedef struct s_texture {
	t_data *data;
	size_t height;
	size_t width;
} t_texture;

typedef struct s_cub3d {
	/* basic info */
	t_data *data;

	/* map info */
	t_map *map;

	t_point *point;
	/* player info */
	t_player *player;

	/* ray info */
	t_ray **ray;

	/* texture info */
	t_texture **texture;
}	t_cub3d;


#endif
