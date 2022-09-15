#include "cub3d.h"

void drawing_ceiling_and_floor(t_cub3d *info)
{
	int scroll_x = 0;
	int scroll_y = 0;
	printf("[%lf]\n", info->map->ceiling_color);
	printf("[%lf]\n", info->map->floor_color);
	while (scroll_x < NB_RAYS)
	{
		while (scroll_y < DEFAULT_HEIGHT / 2)
		{

			my_mlx_pixel_put(info, scroll_x, scroll_y, info->map->ceiling_color);
			scroll_y++;
		}
		while (scroll_y < DEFAULT_HEIGHT)
		{
			my_mlx_pixel_put(info, scroll_x, scroll_y, info->map->floor_color);
			scroll_y++;
		}
		scroll_y = 0;
		scroll_x++;
	}
}

t_strip get_strip_info(t_cub3d *info, t_ray *ray)
{
	t_strip strip;
	double projected_distance;
	double ray_to_wall_distance;

	projected_distance = (DEFAULT_WIDTH / 2) / tan(FOV / 2);
	ray_to_wall_distance = ray->distance * cos(ray->angle - info->player->angle);
//	printf("ray->angle:%lf\n", ray->angle);
//	printf("info->player->angle:%lf\n", info->player->angle);
	strip.height = (TILE_SIZE / ray_to_wall_distance) * projected_distance;
	strip.top_pixel = (DEFAULT_HEIGHT / 2) - (strip.height / 2);
	if (strip.top_pixel < 0)
		strip.top_pixel = 0;
	strip.bottom_pixel = (DEFAULT_HEIGHT/ 2) + (strip.height / 2);
	if (strip.bottom_pixel > DEFAULT_HEIGHT)
		strip.bottom_pixel = DEFAULT_HEIGHT;
	return (strip);
}

t_image *choose_texture_image(t_cub3d *info, t_ray *ray)
{
	if (ray->wall_direction == north)
		return (info->texture_image[north]);
	if (ray->wall_direction == south)
		return (info->texture_image[south]);
	if (ray->wall_direction == west)
		return (info->texture_image[west]);
	if (ray->wall_direction == east)
		return (info->texture_image[east]);
//	else
//		return (NULL);
}

int get_texture_pixel(t_image *texture_image)
{
	int color;
	char *color_address;

//	printf("[%p]", texture_image->address);
//	printf("[%d]", texture_image->size_line);
	color_address = texture_image->address + (texture_image->size_line * (texture_image->bpp / 8));
	color = *(unsigned int *)color_address;
	return (color);
}

void put_wallpaper(t_cub3d *info)
{
	int scroll_x = 0;
	t_strip strip;
	int texture_color;
	t_image *texture;
	while(scroll_x < NB_RAYS)
	{
		strip = get_strip_info(info, info->ray[scroll_x]);
		int scroll_y = strip.top_pixel;
		while (scroll_y < strip.bottom_pixel)
		{
			texture = choose_texture_image(info, info->ray[scroll_x]);
			texture_color = get_texture_pixel(texture);
			my_mlx_pixel_put(info, scroll_x, scroll_y++,  texture_color);
		}
		scroll_y = 0;
		scroll_x++;
	}
}

int rendering(t_cub3d *info)
{
	drawing_ceiling_and_floor(info);
	//put_wallpaper(info);
	//mlx_put_image_to_window(info->mlx, info->window, \
								info->data->image, 0, 0);
}