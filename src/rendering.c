#include "cub3d.h"

static int	get_pixel_from_texture(t_image *texture, int x, int y)
{
	int		color;
	char	*color_addr;

	color_addr = \
		texture->address + (y * texture->size_line + x * (texture->bpp / 8));
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

int	get_texture_pixel(t_image *texture, t_ray *ray, int y, t_strip strip)
{
	int	color;
	int	texture_offset_x;
	int	texture_offset_y;
	int	distance_from_top;

	texture_offset_x = calc_texture_offset_x(ray, texture);
	distance_from_top = y + (strip.height / 2) - (WINDOW_HEIGHT / 2);
	texture_offset_y = \
	distance_from_top * ((double)texture->height / strip.height);
	color = get_pixel_from_texture \
	(texture, texture_offset_x, texture_offset_y);
	return (color);
}

void	put_wallpaper(t_cub3d *info)
{
	int		scroll_x;
	int		scroll_y;
	t_strip	strip;
	int		texture_color;
	t_image	*texture;

	scroll_x = 0;
	while (scroll_x < NB_RAYS)
	{
		strip = get_strip_info(info, info->ray[scroll_x]);
		scroll_y = strip.top_pixel;
		while (scroll_y < strip.bottom_pixel)
		{
			texture = choose_texture_image(info, info->ray[scroll_x]);
//			printf("%p\n", texture->address);
			texture_color = \
			get_texture_pixel(texture, info->ray[scroll_x], scroll_y, strip);
			my_mlx_pixel_put(info, scroll_x, scroll_y++, texture_color);
		}
		scroll_x++;
	}
}

int	rendering(t_cub3d *info)
{
	cast_all_rays(info, info->ray);
	drawing_ceiling_and_floor(info);
	put_wallpaper(info);
	mlx_put_image_to_window(info->mlx, info->window, info->data->image, 0, 0);
	return (42);
}
