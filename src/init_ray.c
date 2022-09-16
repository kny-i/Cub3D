#include "cub3d.h"

t_ray	**cast_all_rays(t_cub3d *info, t_ray **ray)
{
	double	ray_angle;
	size_t	i;

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

t_ray	**initialize_ray(t_cub3d *info)
{
	t_ray	**ray;
	size_t	i;

	ray = ft_calloc(NB_RAYS, sizeof(t_ray *));
	i = 0;
	while (i < NB_RAYS)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		i++;
	}
	ray = cast_all_rays(info, ray);
	return (ray);
}