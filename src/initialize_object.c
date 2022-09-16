#include "cub3d.h"

void	initialize_object(t_cub3d *info)
{
	info->texture_image = initialize_texture(info->mlx, info->map->path);
	info->data = initialize_image_data(info->mlx, info->map);
	info->player = initialize_player(info);
	info->ray = initialize_ray(info);
}
