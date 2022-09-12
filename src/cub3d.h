#ifndef CUB3D_H
# define CUB3D_H


# include "./color.h"
# include "../libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <math.h>
# include <libc.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>

# define SUCCESS 0
# define FAILURE 1

/* keys */
# define RIGHT_ARROW_KEY 0x00ff53
# define LEFT_ARROW_KEY 0x00ff51
# define M_KEY 0x006d
# define ESC_KEY 0x00ff1b

/* colors */
# define OFFSET 8
# define WALL_COLOR 0x4d4d33
# define RAYS_COLOR 0xffff66

/* speeds */
# define DEFAULT_SPEED 30
# define ROTATE_SPEED 5 * (M_PI / 180)

# define DEFAULT_WIDTH 1200
# define DEFAULT_HEIGHT 600
# define TILE_SIZE 64

/* related to math */
# define FOV 1.5//human's field Of view
# define PI 3.1415926535897932384264338327950288419716939937910

# define HORIZONTAL 0
# define VERTICAL 1

# define WALL_WIDTH 1

typedef enum
{
	ray_up = 0,
	ray_down = 1,
	ray_right = 2,
	ray_left = 3
} e_ray_direction;

typedef enum
{
	north = 0,
	south = 1,
	east  = 2,
	west = 3,
} e_direction;

typedef struct s_image {
	void *image;
	char *address;
	int bpp;//bits per pixel
	int size_line;
	int endian;
	int width;
	int height;
} t_image;

typedef struct	s_point {
	double		x;
	double		y;
}				t_point;

typedef struct s_map {
	char **grid;
	int width;
	int height;
	int max_width;
	int max_height;
	size_t nb_col;
	size_t nb_row;


	//t_point *start_position;
	bool is_filled_start_position;
	//double angle;
//	size_t nb_ray;
	int ceiling_color;
	int floor_color;
	char *path[4];
	t_image *texture_image[4];

//	size_t nb_sprites;
//	t_point **sprite_position;
} t_map;

typedef struct s_player {
	t_point *position;
	t_point  wall_hit;
//	long long turn_direction;
	long long walk_direction;
	double angle;
	double rotate_speed;
	//double player_to_plane_distance;
	bool	should_move;
	bool	should_rotate;
} t_player;

typedef struct s_ray {
	double angle;
	t_point *light_source;
	t_point wall_hit;
	double distance;
	bool hit_vertical_flag;
	bool is_face_up;
	bool is_face_down;
	bool is_face_left;
	bool is_face_right;
	e_direction direction;
} t_ray;

typedef struct s_wall_strip {
	int	height;
	int	top_pixel;
	int	bottom_pixel;
}	t_wall_strip;

typedef struct s_texture {
	t_image *data;
	int height;
	int width;
} t_texture;

typedef struct s_cub3d {

	/*mlx info*/
	void *mlx;
	void *window;

	/* basic info */
	t_image *data;

	/* map info */
	t_map *map;

	/* point info */
	t_point *point;

	/* player info */
	t_player *player;

	/* ray info */
	t_ray *ray;

	/* texture info */
//	t_texture **texture;

	/* sprite info */
//	t_sprite	**sprite;
}	t_cub3d;




/* parser.c */
t_cub3d *parser(char *file, t_cub3d *map);

/* message.c */
void error_message(char *message);

/* debug.c*/
void debug_direction_path(t_map *map);
void debug_parser(t_map *map);
void debug_map(t_map *map);


/* start_game.c */
void start_game(t_cub3d *info);

/* game_init.c */
t_texture *load_texture(void *mlx_ptr, char *path);
t_texture **initialize_texture(void *mlx_ptr, char **path);
t_image *initialize_image_data(void *mlx_ptr, t_map *map);
t_point *initialize_point(int x, int y, int color);
t_player *initialize_player(t_map *map, int move_speed, double rotate_speed);

/* start_cub3d.c */
void start_cub3d(t_cub3d *info);

/* utils.c */
char *xstrdup(const char *s1);
int ft_isspace(int c);
int usage(void);
char *skip_space_str(char *str);
double distance_to_btw_points(double x0, double y0, double x1, double y1);

/* related_to_is.c */
bool is_all_specific_char(char *line, char *specific_strs);
bool is_valid_format_file(char *filename);
bool is_valid_args(int argc, char **argv);
int is_nbrs(char *str);
bool is_one_at_first(char *line);

/* related_to_is2.c */
bool is_screen_edge(t_map *map, double x, double y);
bool is_wall(t_map *map, int x, int y, char identification);
bool is_all_strs_space(char *str);

/* is_valid_map.c */
void is_valid_map(t_map *map);
void set_player_info_loop(t_cub3d *info);
bool is_specific_char(char c, char *str);

/* validate_map_utils.c */
char **strs_dup(char **strs);
void	free_strs(char **strs);

/* parse_utils.c" */
int allocate_color(t_map *map, char *line);
bool parse_color(t_map *map, char *line);
void allocate_map(t_map *map, char *line, size_t *map_col_index);


size_t strs_len(char **strs);//where?

/* init.c */
//void init_map(t_cub3d *info);
//void init(t_cub3d *info);
//void init_player(t_player *player);
//void init_ray(t_ray **ray);
//void init_texture(t_texture **texture);
//void init_sprite(t_sprite **sprite);

#endif
