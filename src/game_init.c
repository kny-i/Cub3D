#include "cub3d.h"

t_texture *load_texture(void *mlx_ptr, char *path)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	texture->data = ft_calloc(1, sizeof(t_image));
	texture->data->image =
			mlx_xpm_file_to_image(mlx_ptr,
								  path,
								  &texture->width,
								  &texture->height);
	if (texture->data->image == NULL)
		return (NULL);
	texture->data->address = mlx_get_data_addr(texture->data->image,
											   &texture->data->bpp,
											   &texture->data->size_line,
											   &texture->data->endian);
	if (texture == NULL)
		return (NULL);
	return (texture);
}

t_texture **initialize_texture(void *mlx_ptr, char **path)
{
	t_texture	**texture;

	texture = ft_calloc(4, sizeof(t_texture *));
	texture[north] = load_texture(mlx_ptr, path[north]);
	texture[south] = load_texture(mlx_ptr, path[south]);
	texture[east] = load_texture(mlx_ptr, path[east]);
	texture[west] = load_texture(mlx_ptr, path[west]);
	if ((texture[north] == NULL)
		|| (texture[south] == NULL)
		|| (texture[east] == NULL)
		|| (texture[west] == NULL))
		error_message("INVALID TEXTURE PATH!"
					  " OR INVALID DIRECTION FORMAT!");
	return (texture);
}

t_image *initialize_image_data(void *mlx_ptr, t_map *map)
{
	t_image *image;

	map->width = DEFAULT_WIDTH;
	map->height = DEFAULT_HEIGHT;
	image = ft_calloc(1, sizeof (t_image));
	image->image = mlx_new_image(mlx_ptr, map->width, map->height);
	image->address = mlx_get_data_addr(image->image, &image->bpp, &image->size_line, &image->endian);
	return (image);
}

t_point *initialize_point(int x, int y, int color)
{
	t_point *point;

	point = ft_calloc(1, sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

//t_player  *initialize_player( *map, const int default_speed, const double rotate_speed)
//{
//
//	/* ここでしていた情報の決定をどうするべきか */
//	player->rotate_speed = rotate_speed;
//
//	/* initすべきかは後で決定 */
//	player->walk_direction = 0;
//
//	player->position->x = 0;
//	player->position->y = 0;
//	return (player);
//}
