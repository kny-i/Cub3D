#include "cub3d.h"


t_texture *load_texture(void *mlx_ptr, char *path)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	texture->data = ft_calloc(1, sizeof(t_data));
	texture->data->image = mlx_xpm_file_to_image(mlx_ptr, path, &texture->width,
											 &texture->height);
	if (texture->data->image == NULL)
		return (NULL);
	texture->data->address = mlx_get_data_addr(texture->data->image, &texture->data->bpp,
										&texture->data->line_length, &texture->data->endian);
	return (texture);
}
t_texture **initialize_texture(void *mlx_ptr, char **path)
{
	t_texture	**texture;

	texture = ft_calloc(5, sizeof(t_texture *));
	texture[north] = load_texture(mlx_ptr, path[north]);
	texture[south] = load_texture(mlx_ptr, path[south]);
	texture[east] = load_texture(mlx_ptr, path[east]);
	texture[west] = load_texture(mlx_ptr, path[west]);
	texture[sprite] = load_texture(mlx_ptr, path[sprite]);
	if (!(texture[north]) || !(texture[south]) || !(texture[east]) ||
		!(texture[west]) || !(texture[sprite]))
		error_message("INVALID TEXTURE PATH");
	return (texture);

}

void start_game(t_cub3d *info)
{
	info->texture = initialize_texture(info->mlx, info->map->path);


}