#include "cub3d.h"

double	normalize_angle(double ray_angle)
{
	double	normalized_angle;

	normalized_angle = remainder(ray_angle, M_PI * 2); // 2PIの範囲内に値を変換
	if (normalized_angle < 0)
		normalized_angle += M_PI * 2;
	return (normalized_angle);
}

void set_ray_direction(t_ray *ray, double ray_angle)
{
	ray->angle = normalize_angle(ray_angle);
	if (M_PI < ray->angle && ray->angle < M_PI * 2)
		ray->is_face_up = true;
	if (ray->is_face_up == false)
		ray->is_face_down = true;
	if (M_PI / 2 < ray->angle && ray->angle < 3 * M_PI / 2)
		ray->is_face_left = true;
	if (ray->is_face_left == false)
		ray->is_face_right = true;
}

static double	pythagorean_theorem_for_delta(t_point *light_source, t_point *interception)
{
	double	dx;
	double	dy;

	dx = light_source->x - interception->x;
	dy = light_source->y - interception->y;
	return (sqrt(dx * dx + dy * dy));
}

void get_closest_wall_hit(t_ray *ray, t_point *horizontal_wall_hit, t_point *vertical_wall_hit)
{
	double	horiz_distance;
	double	vert_distance;

	horiz_distance = pythagorean_theorem_for_delta(horizontal_wall_hit, ray->light_source);
	vert_distance = pythagorean_theorem_for_delta(vertical_wall_hit, ray->light_source);
	if (horiz_distance < vert_distance)
	{
		ray->wall_hit = *horizontal_wall_hit;
		ray->distance = horiz_distance;
		ray->horizontal_or_vertical = HORIZONTAL;
	}
	else
	{
		ray->wall_hit = *vertical_wall_hit;
		ray->distance = vert_distance;
		ray->horizontal_or_vertical = VERTICAL;
	}

}

t_point	find_first_horizontal_interception(t_ray *ray)
{
	t_point	first_horizontal_interception;

	first_horizontal_interception.y = floor(ray->light_source->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_face_down == true)
		first_horizontal_interception.y += TILE_SIZE;
	first_horizontal_interception.x = ray->light_source->x + (first_horizontal_interception.y - ray->light_source->y) / tan(ray->angle);
	return (first_horizontal_interception);
}

t_point find_first_vertical_interception(t_ray *ray)
{
	t_point	first_horizontal_interception;

	first_horizontal_interception.x = floor(ray->light_source->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_face_right == true)
		first_horizontal_interception.x += TILE_SIZE;
	first_horizontal_interception.y = ray->light_source->y + (first_horizontal_interception.x - ray->light_source->x) * tan(ray->angle);
	return (first_horizontal_interception);
}

t_point find_horizontal_wall_hit(t_ray *ray, t_map *map, t_point interceptopn)
{
	double x_step;
	double y_step;
	t_point point;

	x_step = TILE_SIZE / tan(ray->angle);
	y_step = TILE_SIZE;

	point.x = interceptopn.x;
	point.y = interceptopn.y;
	while (true)
	{
		if (point.x < 0.0 || (double)map->nb_row * TILE_SIZE < point.x
		|| point.y < 0.0 || (double)map->nb_col * TILE_SIZE < point.y)
			return (point);
//		printf("%d\n", (int)point.x);
//		printf("%d\n", (int)point.y);
		if (map->grid[(int)point.y / TILE_SIZE][(int)point.x / TILE_SIZE] == '1')
			return (point);
		point.x += x_step;
		point.y += y_step;
	}
}

t_point find_vertical_wall_hit(t_ray *ray, t_map *map, t_point interceptopn)
{
	double x_step;
	double y_step;
	t_point point;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(ray->angle);
	point.x = interceptopn.x;
	point.y = interceptopn.y;
	while (true)
	{
		if (point.x < 0.0 || (double )map->nb_row * TILE_SIZE < point.x
		|| point.y < 0.0 || (double )map->nb_col * TILE_SIZE < point.y)
			return (point);
		if (map->grid[(int)point.y / TILE_SIZE][(int)point.x / TILE_SIZE] == '1')
			return (point);
		point.x += x_step;
		point.y += y_step;
	}
}

t_point get_horizontal_wall_hit(t_ray *ray, t_map *map)
{
	t_point interception;
	t_point wall_hit;

	interception = find_first_horizontal_interception(ray);
	wall_hit = find_horizontal_wall_hit(ray, map, interception);
	return (wall_hit);
}

t_point get_vertical_wall_hit(t_ray *ray, t_map *map)
{
	t_point interception;
	t_point wall_hit;

	interception = find_first_vertical_interception(ray);
	wall_hit = find_vertical_wall_hit(ray, map, interception);
	return (wall_hit);
}

void get_hit_wall_direction(t_ray *ray)
{
	if (ray->horizontal_or_vertical == VERTICAL)
	{
		if (ray->is_face_left)
			ray->wall_direction = west;
		else
			ray->wall_direction = east;
	}
	else
	{
		if (ray->is_face_up)
			ray->wall_direction = north;
		else
			ray->wall_direction = south;
	}
}

t_ray *cast_ray(t_ray *ray, t_cub3d *info, double ray_angle)
{
	t_point horizotal_wall_hit;
	t_point vertical_wall_hit;

	set_ray_direction(ray, ray_angle);
	horizotal_wall_hit = get_horizontal_wall_hit(ray, info->map);
	vertical_wall_hit = get_vertical_wall_hit(ray, info->map);
	get_closest_wall_hit(ray, &horizotal_wall_hit, &vertical_wall_hit);
	get_hit_wall_direction(ray);//get  direction that this ray crashed
	return (ray);
}

t_ray **cast_all_rays(t_cub3d *info, t_ray **ray)
{
	double ray_angle;
	size_t  i;

	ray_angle = info->player->angle - (FOV / 2);

	i = 0;
	while (i < NB_RAYS)
	{
		ray[i]->light_source = info->player->position;
		ray[i] = cast_ray(ray[i], info, ray_angle);
		ray_angle += FOV / NB_RAYS;
		i++;
	}
	return (ray);
}

t_ray **initialize_ray(t_cub3d *info)
{
	t_ray **ray;

	ray = ft_calloc(NB_RAYS, sizeof(t_ray *));
	size_t i = 0;
	while (i < NB_RAYS)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		i++;
	}
	ray = cast_all_rays(info, ray);
	return (ray);
}

void initialize_object(t_cub3d *info)
{
	/* 不要 */
//	info->point = initialize_point(OFFSET, OFFSET, WALL_COLOR);
	info->texture_image = initialize_texture(info->mlx, info->map->path);
	info->data = initialize_image_data(info->mlx, info->map);
	info->player = initialize_player(info);
	info->ray = initialize_ray(info);
}
