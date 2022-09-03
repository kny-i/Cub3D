#include "cub3d.h"

bool is_valid_args(int argc, char **argv)
{
	if (argc != 3)
		return (false);
	return (true);
}

int usage(void)
{
	printf(RED"[USAGE]\n"
			  "./cub3d [map.cub3d]\n"STOP);
	return (FAILURE);
}

void init_map(t_map *map)
{
	map = ft_calloc(1, sizeof (t_map));
	map->start_position = NULL;
	map->ceiling_color = INIT_COLOR;
	map->floor_color = INIT_COLOR;
	map->path[north] = NULL;
	map->path[south] = NULL;
	map->path[east] = NULL;
	map->path[west] = NULL;
	map->path[sprite] = NULL;
	map->sprite_position = NULL;
	map->grid = NULL;
	map->nb_sprites = SIZE_T_MAX;
	map->width = SIZE_T_MAX;
	map->height = SIZE_T_MAX;
	map->nb_row = SIZE_T_MAX;
	map->nb_col = SIZE_T_MAX;
}
void init(t_cub3d *info)
{
	init_map(info->map);
	init_mlx(info);
}

int launch_cub3d(int argc, char **argv)
{
	t_cub3d game_info;
	if (is_valid_args(argc, argv) == true)
		return (usage());
	init(&game_info);


	return (SUCCESS);
}

int main(int argc, char **argv)
{
	launch_cub3d(argc, argv);
}

