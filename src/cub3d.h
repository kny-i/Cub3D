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

/* colors */
# define OFFSET 8
# define WALL_COLOR 0x4d4d33
# define RAYS_COLOR 0xffff66

/* speeds */
# define DEFAULT_SPEED 30
# define ROTATE_SPEED 5 * (M_PI / 180)

# define DEFAULT_WIDTH 649
# define DEFAULT_HEIGHT 410
# define TILE_SIZE 32

/* related to math */
# define FOV 1 / M_PI * 3

# define HORIZONTAL 0
# define VERTICAL 1

# define WALL_WIDTH 1
# define NB_RAYS DEFAULT_WIDTH
# define MOVE_STEP 2

/* KEY MACROS */
# define ESC_KEY	0xff1b
# define W_KEY		'w'
# define S_KEY		's'
# define A_KEY		'a'
# define D_KEY		'd'
# define LOOKING_LEFT_KEY	0xff51
# define LOOKING_RIGHT_KEY	0xff53

# define STRUCTURE_NOTIFY_MASK 131072
# define WINDOW_DESTROY 17

typedef enum s_ray_direction
{
	ray_up = 0,
	ray_down = 1,
	ray_right = 2,
	ray_left = 3
}			t_ray_direction;

typedef enum s_direction
{
	north = 0,
	south = 1,
	east  = 2,
	west  = 3,
}			t_direction;

typedef struct s_image {
	void	*image;
	char	*address;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		max_width;
	int		max_height;
	size_t	nb_col;
	size_t	nb_row;
	bool	is_filled_start_position;
	int		ceiling_color;
	int		floor_color;
	char	*path[4];
	t_image	*texture_image[4];
}				t_map;

typedef struct s_player
{
	t_point	*position;
	t_point	wall_hit;
	double	walk_direction;
	double	angle;
	double	rotate_speed;
	bool	should_move;
	bool	should_rotate;
}				t_player;

typedef struct s_ray {
	double		angle;
	t_point		*light_source;
	t_point		wall_hit;
	double		distance;
	bool		horizontal_or_vertical;
	bool		hit_vertical_flag;
	bool		is_face_up;
	bool		is_face_down;
	bool		is_face_left;
	bool		is_face_right;
	t_direction	wall_direction;
}				t_ray;

typedef struct s_wall_strip {
	int	height;
	int	top_pixel;
	int	bottom_pixel;
}	t_strip;

typedef struct s_texture
{
	t_image	*data;
	int		height;
	int		width;
}			t_texture;


typedef struct s_cub3d
{
	void		*mlx;
	void		*window;
	t_image		*data;
	t_map		*map;
	t_point		*point;
	t_player	*player;
	t_ray		**ray;
	t_image		**texture_image;
}	t_cub3d;

/* parser.c */
t_cub3d		*parser(char *file, t_cub3d *map);

/* message.c */
void		error_message(char *message);
int			usage(void);
int			the_end(void);

/* debug.c*/
void		debug_direction_path(t_map *map);
void		debug_parser(t_map *map);
void		debug_map(t_map *map);

/* start_game.c */
void		start_game(t_cub3d *info);

/* game_init.c */
t_image		*initialize_image_data(void *mlx_ptr, t_map *map);
t_point		*initialize_point(int x, int y, int color);
t_player	*initialize_player(t_cub3d *info);
t_image		*load_texture(void *mlx_ptr, char *path);
t_image		**initialize_texture(void *mlx_ptr, char **path);

/* start_cub3d.c */
void		start_cub3d(t_cub3d *info);
double		normalize_angle(double angle);

/* utils.c */
char		*xstrdup(const char *s1);
int			ft_isspace(int c);
char		*skip_space_str(char *str);
double		distance_to_btw_points(double x0, double y0, double x1, double y1);
size_t		strs_len(char **strs);

/* related_to_is.c */
bool		is_all_specific_char(char *line, char *specific_strs);
bool		is_valid_format_file(char *filename);
bool		is_valid_args(int argc, char **argv);
int			is_nbrs(char *str);
bool		is_one_at_first(char *line);

/* related_to_is2.c */
bool		is_screen_edge(t_map *map, double x, double y);
bool		is_wall(t_map *map, int x, int y, char identification);
bool		is_all_strs_space(char *str);

/* is_valid_map.c */
void		is_valid_map(t_map *map);
void		set_player_info_loop(t_cub3d *info);
bool		is_specific_char(char c, char *str);

/* validate_map_utils.c */
char		**strs_dup(char **strs);
void		free_strs(char **strs);

/* parse_utils.c" */
int			allocate_color(t_map *map, char *line);
bool		parse_color(t_map *map, char *line);
void		allocate_map(t_map *map, char *line, size_t *map_col_index);
void		get_nb_col(int fd, t_map *map, size_t *nb_col);

/* initialize_object.c */
void		initialize_object(t_cub3d *info);
t_ray		**cast_all_rays(t_cub3d *info, t_ray **ray);
void		get_closest_wall_hit(t_ray *ray, t_point *horizontal_wall_hit, t_point *vertical_wall_hit);
void		get_hit_wall_direction(t_ray *ray);
void		set_ray_direction(t_ray *ray, double ray_angle);
t_point		find_first_horizontal_interception(t_ray *ray);
t_point		find_first_vertical_interception(t_ray *ray);

/* play_gaming.c */
void		play_gaming(t_cub3d *info);

/* rendering.c */
int			rendering(t_cub3d *info);


/* my_mlx_pixel_put.c */
void		my_mlx_pixel_put(t_cub3d *info, int x, int y, int color);

/* update.c */
int			updating(t_cub3d *info);

/* key_settings.c */
int			key_settings(int key, t_cub3d *info);
int			reset_key(int key, t_cub3d *info);


/* moving.c */
void		moving_forward(t_cub3d *info);
void		moving_backward(t_cub3d *info);
void		moving_rightside(t_cub3d *info);
void		moving_leftside(t_cub3d *info);

/* looking.c */
void		looking_rightside(t_cub3d *info);
void		looking_leftside(t_cub3d *info);

/* raycasting.c */
t_ray		*cast_ray(t_ray *ray, t_cub3d *info, double ray_angle);

/* interception.c */
t_point		find_first_vertical_interception(t_ray *ray);
t_point		find_first_horizontal_interception(t_ray *ray);

/* ray_cast_utils*/
void		get_hit_wall_direction(t_ray *ray);
/*init ray*/
t_ray		**initialize_ray(t_cub3d *info);
/* rendering_utils.c */
t_strip		get_strip_info(t_cub3d *info, t_ray *ray);
t_image		*choose_texture_image(t_cub3d *info, t_ray *ray);
void		drawing_ceiling_and_floor(t_cub3d *info);
#endif
