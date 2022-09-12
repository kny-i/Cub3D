#include "cub3d.h"

/*
 * angleがマイナス値だった時には正の方向に一周回している
 */

double normalize_angle(double angle)
{
	angle = remainder(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

int return_ray_facing(int *direction, int way)
{
	int ret;

	ret = -1;
	if (way == ray_up)
		ret = (direction[ray_up]);
	if (way == ray_down)
		ret = (direction[ray_down]);
	if (way == ray_left)
		ret = (direction[ray_left]);
	if (way == ray_right)
		ret = (direction[ray_right]);
	free(direction);
	return (ret);
}

//directionのまちがいあるかも
int ray_facing(double angle, int way)
{
	int *direction;

	//decide down
	direction = malloc(sizeof(int) * 4);
	if (angle > 0 && angle < PI)
		direction[ray_down] = true;
	else
		direction[ray_down] = false;
	//decide up
	if (direction[ray_down] == 0)
		direction[ray_up] = true;
	else
		direction[ray_up] = false;
	//decide left
	if (angle > PI / 2 && angle < 3 * PI / 2)
		direction[ray_left] = true;
	else
		direction[ray_left] = false;
	//decide right
	if (direction[ray_left] == 0)
		direction[ray_right] = true;
	else
		direction[ray_right] = false;

	return (return_ray_facing(direction, way));
}

void horizontal_interception(t_cub3d *info, t_point *interception, double ray_angle, t_point *step)
{
	interception->y = floor(info->player->position->y / TILE_SIZE) * TILE_SIZE;
	if (ray_facing(ray_angle, ray_right) != 0)
		interception->x += TILE_SIZE;
	interception->y = info->player->position->y + (interception->x - info->player->position->x * tan(ray_angle));
	step->x = TILE_SIZE;
	if (ray_facing(ray_angle, ray_up) != 0)
		step->x *= -1;
	step->y = TILE_SIZE * tan(ray_angle);
	if (ray_facing(ray_angle, ray_left) != 0 && step->x > 0)
		step->x *= -1;
	if (ray_facing(ray_angle, ray_right) != 0 && step->x < 0)
		step->y *= -1;
}

void vertical_interception(t_cub3d *info, t_point *interception, double ray_angle, t_point *step)
{
	interception->x = floor(info->player->position->x / TILE_SIZE)* TILE_SIZE;
	if (ray_facing(ray_angle, ray_right) != 0)
		interception->x += TILE_SIZE;
	interception->y = info->player->position->y + (interception->x - info->player->position->x) * tan(ray_angle);
	step->x = TILE_SIZE;
	if (ray_facing(ray_angle, ray_left) != 0)
		step->x *= -1;
	step->y = TILE_SIZE * tan(ray_angle);
	if (ray_facing(ray_angle, ray_up) != 0 && step->y > 0 )
		step->y *= -1;
	if (ray_facing(ray_angle, ray_down) != 0 && step->y < 0 )
		step->y *= -1;
}

void prepare_ray_casting(t_cub3d *info, double ray_angle, int flag, t_point *next)
{
	t_point step;
	double x_check;
	double y_check;

	if (flag == HORIZONTAL)
		horizontal_interception(info, next, ray_angle, &step);
	if (flag == VERTICAL)
		horizontal_interception(info, next, ray_angle, &step);
	while (is_screen_edge(info->map, next->x, next->y) == true)
	{
		if ((next->x + (ray_facing(ray_angle, ray_left)) && flag == VERTICAL) == true)
			x_check = -1;
		else
			x_check = 0;
		if ((ray_facing(ray_angle, ray_right) && flag == VERTICAL) == true)
			x_check += 1;
		else
			x_check = 0;
		if ((next->y + (ray_facing(ray_angle, ray_down)) && flag == HORIZONTAL) == true)
			y_check = 1;
		else
			y_check = 0;
		if ((ray_facing(ray_angle, ray_up) && flag == HORIZONTAL) == true)
			y_check += -1;
		else
			y_check = 0;
		if (is_wall(info->map, x_check, y_check, '1') == true)
			break ;
		else
		{
			next->x += step.x;
			next->y += step.y;
		}
	}
}

/*
 * 何かしらの座標を受けとった平方根
 * 現状ではなんでbtwがなぜかわからない
 */

void allocate_ray(t_ray *ray, t_point *collision, double ray_distance_to_plane, int coordination)
{
	ray->collision->x = collision->x;
	ray->collision->y = collision->y;
	ray->ray_to_plane_distance = ray_distance_to_plane;
	ray->coordination = coordination;
}

void get_closest_wall_data(t_cub3d *info, t_ray *ray, double ray_angle) {
	t_point horizontal_interception;
	t_point vertical_interception;
	double horizontal_distance;
	double vertical_distance;
	/* INT_MAXに必ずなってしまうという部分がおかしい */
	prepare_ray_casting(info, ray_angle, HORIZONTAL, &horizontal_interception);
	prepare_ray_casting(info, ray_angle, VERTICAL, &vertical_interception);

	if (is_screen_edge(info->map, horizontal_interception.x, horizontal_interception.y) == true)
	{
		horizontal_distance = INT_MAX;
	}
	else
		horizontal_distance = distance_to_btw_points(info->player->position->x, info->player->position->y,
													 horizontal_interception.x, horizontal_interception.y);
	if (is_screen_edge(info->map, vertical_interception.x, vertical_interception.y) == true)
	{
		vertical_distance = INT_MAX;
	}
	else
		vertical_distance = distance_to_btw_points(info->player->position->x, info->player->position->y,
													vertical_interception.x, vertical_interception.y);
	if (horizontal_distance < vertical_distance)
		allocate_ray(ray, &horizontal_interception, horizontal_distance, HORIZONTAL);
	else
		allocate_ray(ray, &vertical_interception, vertical_distance, VERTICAL);
}

void ray_casting(t_cub3d *info)
{
	size_t i = 0;
	info->player->player_to_plane_distance = (info->map->width / 2) / (tan(FOV / 2));
	while (i < info->map->nb_ray)
	{
		info->ray[i]->angle = info->player->rotate_speed + atan2(i - info->map->nb_ray / 2, info->player->player_to_plane_distance);
		info->ray[i]->angle = normalize_angle(info->ray[i]->angle);
		get_closest_wall_data(info, info->ray[i], info->ray[i]->angle);
		i++;
	}
}

/* 座標の画素に対してcolorを割り当てるための関数 */
void x_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char *dest;
	int offset;

	offset = (y * data->size_line + x * (data->bpp / 8));
	dest = data->address + offset;
	*(unsigned int *)dest = color;
}

int			get_texture_color(t_texture *texture, int x, int y)
{
	int		offset;

	offset = (y * texture->data->size_line + x * (texture->data->bpp / 8));
	return (*(unsigned int *)(texture->data->address + 2) << 16 |
			*(unsigned int *)(texture->data->address + 1) << 8 |
			*(unsigned int *)(texture->data->address + 0) << 0);
}

int put_text(t_cub3d *info, int y, int index, double *limit)
{
	t_ray *ray;
	double ymin;
	double ymax;

	ray = NULL;
	ymin = limit[0];
	ymax = limit[1];

	ray = info->ray[index];
	if (ray_facing(ray->angle, ray_up) && ray->coordination == HORIZONTAL) {
		return (get_texture_color(info->texture[north],
								  (int)ray->collision->x % info->texture[north]->width, (y - ymin) * (info->texture[north]->height) / (ymax - ymin)));

	}
	else if (ray_facing(ray->angle, ray_down) && ray->coordination == HORIZONTAL) {
		return (get_texture_color(info->texture[south],
								  (int)ray->collision->x % info->texture[south]->width, (y - ymin) * (info->texture[south]->height) / (ymax - ymin)));
	}
	else if (ray_facing(ray->angle, ray_right) && ray->coordination == VERTICAL) {

		return (get_texture_color(info->texture[east],
								  (int)ray->collision->y % info->texture[east]->width, (y - ymin) * (info->texture[east]->height) / (ymax - ymin)));
	}
	else if (ray_facing(ray->angle, ray_left) && ray->coordination == VERTICAL) {
		return (get_texture_color(info->texture[west],
								  (int)ray->collision->y % info->texture[west]->width, (y - ymin) * (info->texture[west]->height / (ymax - ymin))));
	}
//	return (1);
}

void drawing_color(t_cub3d *info, double wall_height, size_t index)
{
	double choice[2];
	int x;
	int y;

	choice[0] = (info->map->height / 2) - (wall_height / 2);
	choice[1] = (info->map->height / 2) + (wall_height / 2);

	x = index * WALL_WIDTH;
	while (x < (index + 1) * WALL_WIDTH)
	{
		y = -1;
		while (++y <= choice[0] && y < info->map->height)
		{
			x_mlx_pixel_put(info->data, x, y, info->map->ceiling_color);
		}
		y--;
		while (++y <= choice[1] && y < info->map->height)
		{
			x_mlx_pixel_put(info->data, x, y, put_text(info, y, index, choice));
//			x_mlx_pixel_put(info->data, x, y, put_text(info, y, index, 0xFF));
		}
		y--;
		while (++y < info->map->height)
		{
			x_mlx_pixel_put(info->data, x, y, info->map->ceiling_color);
		}
		x++;
	}
}

/* skip this function understanding */
void drawing_3dmap(t_cub3d *info)
{
	double distance_to_plane;
	double wall_height;
	size_t i = 0;
	while (i < info->map->nb_ray)
	{
		distance_to_plane = info->ray[i]->ray_to_plane_distance * cos(info->ray[i]->angle - info->player->angle);
		wall_height = TILE_SIZE / distance_to_plane * info->player->player_to_plane_distance;
		drawing_color(info, wall_height, i);
		i++;
	}
}

void start_cub3d(t_cub3d *info)
{
	ray_casting(info);
	drawing_3dmap(info);
	info->window = mlx_new_window(info->mlx, info->map->width, info->map->height, "CUB3D by teamCRI");
	mlx_put_image_to_window(info->mlx, info->window, info->data->image, 0, 0);
}
