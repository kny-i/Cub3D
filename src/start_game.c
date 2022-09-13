#include "cub3d.h"

double	normalize_angle(double ray_angle)
{
	double	normalized_angle;

	normalized_angle = remainder(ray_angle, M_PI * 2);
	if (normalized_angle < 0)
		normalized_angle += M_PI * 2;
	return (normalized_angle);
}

void set_ray_direction(t_ray *ray, double ray_angle)
{
	/*
	 * normalize_angleの
	 * 処理に関して質問したい
	 * <1>ray_facing_up/down/left/rightは方角と一致しているのか
	 * <2>単位円が常に一定のものを採用しているのかどうかについて質問したい
	 */
	ray->angle = normalize_angle(ray_angle);
	if (M_PI < ray->angle && ray->angle < M_PI * 2)
		ray->is_face_up = true;
	if (ray->is_face_up == false)
		ray->is_face_down = true;
	if (M_PI / 2 < ray->angle && ray->angle < 2 * M_PI / 3)
		ray->is_face_left = true;
	if (ray->is_face_left == false)
		ray->is_face_right = true;
}

static double	pythagorean_theorem(t_point *p1, t_point *p2)
{
	double	dx;
	double	dy;

	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	return (sqrt(dx * dx + dy * dy));
}

void get_closest_wall_hit(t_ray *ray, t_point *horizontal_wall_hit, t_point *vertical_wall_hit)
{
	double	horiz_distance;
	double	vert_distance;

	horiz_distance = pythagorean_theorem(horizontal_wall_hit, ray->light_source);
	vert_distance = pythagorean_theorem(vertical_wall_hit, ray->light_source);
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

t_point	find_interception(t_ray *ray)
{
	t_point	interception;

	interception.y = floor(ray->light_source->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_face_down)
		interception.y += TILE_SIZE;
	interception.x = ray->light_source->x + \
					(interception.y - ray->light_source->y) / tan(ray->angle);
	return (interception);
}

t_point get_horizontal_wall_hit(t_ray *ray, t_map *map)
{
	t_point interception;
	t_point wall_hit;

	interception = find_interception(ray);
//	wall_hit = find_wall_hit(ray, map, interception);
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
//	horizotal_wall_hit = get_horizontal_wall_hit(ray, map);
//	vertical_wall_hit = get_vertical_wall_hit(ray, map);
	get_closest_wall_hit(ray, &horizotal_wall_hit, &vertical_wall_hit);
	get_hit_wall_direction(ray);//get  direction that this ray crashed
	return (ray);
}


t_ray **cast_all_rays(t_cub3d *info, t_ray **ray)
{
	double ray_angle;
	size_t  i;

	/* 0 <= info->player->angle <= 2π*/
	ray_angle = info->player->angle - (FOV / 2);
//	printf("%lf\n", info->player->angle);
	i = 0;
	while (i < NB_RAYS)
	{
//		ray[i] = cast_ray(ray[i], info, ray_angle);
		ray_angle += info->player->angle / (NB_RAYS - 1);
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
//	info->texture = initialize_texture(info->mlx, info->map->path);
//	info->point = initialize_point(OFFSET, OFFSET, WALL_COLOR);

	info->data = initialize_image_data(info->mlx, info->map);
	info->player = initialize_player(info);
	info->ray = initialize_ray(info);
}

void main_loop(t_cub3d *info)
{
	;
}

void start_game(t_cub3d *info)
{
	//init game
	initialize_object(info);
	//game start!!!!!!
//	main_loop(info);
}
