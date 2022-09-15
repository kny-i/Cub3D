#include "cub3d.h"

void drawing_ceiling_and_floor(t_cub3d *info)
{
	int scroll_x = 0;
	int scroll_y = 0;
	while (scroll_x < NB_RAYS)
	{
		while (scroll_y < DEFAULT_HEIGHT)
		{
			if (scroll_y < DEFAULT_HEIGHT / 2)
				my_mlx_pixel_put(info, scroll_x, scroll_y, info->map->ceiling_color);
			else
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
//	printf("distance[%lf]\n", ray->distance);
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
	{

		return (info->texture_image[north]);
	}
	if (ray->wall_direction == south)
	{

		return (info->texture_image[south]);
	}
	if (ray->wall_direction == west)
	{

		return (info->texture_image[west]);
	}
	if (ray->wall_direction == east)
	{

		return (info->texture_image[east]);
	}

//	else
//		return (NULL);
}

static int	get_pixel_from_texture(t_image *tex, int x, int y)
{
	int		color;
	char	*color_addr;

	color_addr = \
		tex->address + (y * tex->size_line + x * (tex->bpp / 8));
	color = *(unsigned int *)color_addr;
	return (color);
}

static int	calc_texture_offset_x(t_ray *ray, t_image *texture)
{
	int	tex_offset_x;
	int	left_edge;

	if (ray->wall_direction == north)
	{
		tex_offset_x = (int)ray->wall_hit.x % TILE_SIZE;
	}
	else if (ray->wall_direction == south)
	{
		left_edge = ((int)ray->wall_hit.x / TILE_SIZE + 1) * TILE_SIZE - 1;
		tex_offset_x = left_edge - (int)ray->wall_hit.x;
	}
	else if (ray->wall_direction == west)
	{
		left_edge = ((int)ray->wall_hit.y / TILE_SIZE + 1) * TILE_SIZE - 1;
		tex_offset_x = left_edge - (int)ray->wall_hit.y;
	}
	else
	{
		tex_offset_x = (int)ray->wall_hit.y % TILE_SIZE;
	}
	tex_offset_x *= ((double)texture->width / TILE_SIZE);
	return (tex_offset_x);
}
int get_texture_pixel(t_image *texture, t_ray *ray, int y, t_strip strip)
{
	int	color;
	int	texture_offset_x;
	int	texture_offset_y;
	int	distance_from_top;

	texture_offset_x = calc_texture_offset_x(ray, texture);
	distance_from_top = y + (strip.height / 2) - (DEFAULT_HEIGHT / 2);
	texture_offset_y = distance_from_top * ((double)texture->height / strip.height);
	color = get_pixel_from_texture(texture, texture_offset_x, texture_offset_y);
	return (color);
}

void debug_strip(t_strip strip)
{
	printf("height = [%d]\n", strip.height);
	printf("bottom = [%d]\n", strip.bottom_pixel);
	printf("top = [%d]\n", strip.top_pixel);
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
		//debug_strip(strip);
		while (scroll_y < strip.bottom_pixel)
		{
			texture = choose_texture_image(info, info->ray[scroll_x]);
			texture_color = get_texture_pixel(texture, info->ray[scroll_x], scroll_y, strip);
			my_mlx_pixel_put(info, scroll_x, scroll_y++,  texture_color);
		}
		scroll_x++;
	}
}

int rendering(t_cub3d *info)
{
	drawing_ceiling_and_floor(info);
	put_wallpaper(info);
	mlx_put_image_to_window(info->mlx, info->window, \
								info->data->image, 0, 0);
}
