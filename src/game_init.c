#include "cub3d.h"

t_image	*load_texture(void *mlx_ptr, char *path)
{
	t_image	*texture;

	texture = xcalloc(1, sizeof(t_image));
	texture->image = \
	mlx_xpm_file_to_image \
	(mlx_ptr, path, &texture->width, &texture->height);
	if (texture->image == NULL)
		return (NULL);
	texture->address = \
	mlx_get_data_addr \
	(texture->image, &texture->bpp, &texture->size_line, &texture->endian);
	if (texture == NULL)
		return (NULL);
	return (texture);
}

t_image	**initialize_texture(void *mlx_ptr, char **path)
{
	t_image	**texture_image;

	texture_image = xcalloc(4, sizeof(t_image *));
	texture_image[north] = load_texture(mlx_ptr, path[north]);
	texture_image[south] = load_texture(mlx_ptr, path[south]);
	texture_image[east] = load_texture(mlx_ptr, path[east]);
	texture_image[west] = load_texture(mlx_ptr, path[west]);
	if ((texture_image[north] == NULL)
		|| (texture_image[south] == NULL)
		|| (texture_image[east] == NULL)
		|| (texture_image[west] == NULL))
		error_message("INVALID TEXTURE PATH!" \
					  " OR INVALID DIRECTION FORMAT!");
	return (texture_image);
}

t_image	*initialize_image_data(void *mlx_ptr, t_map *map)
{
	t_image	*image;

	map->width = DEFAULT_WIDTH;
	map->height = DEFAULT_HEIGHT;
	image = xcalloc(1, sizeof (t_image));
	image->image = mlx_new_image(mlx_ptr, map->width, map->height);
	image->address = mlx_get_data_addr \
	(image->image, &image->bpp, &image->size_line, &image->endian);
	return (image);
}

t_point	*initialize_point(int x, int y, int color)
{
	t_point	*point;

	point = xcalloc(1, sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_player	*initialize_player(t_cub3d *info)
{
	t_player	*player;

	player = info->player;
	player->rotate_speed = ROTATE_SPEED;
	player->should_rotate = false;
	player->should_move = false;
	player->walk_direction = 0;
	return (player);
}
