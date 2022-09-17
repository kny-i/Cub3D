#include "cub3d.h"

void	initialize_mlx(t_cub3d *info)
{
	info->mlx = mlx_init();
	info->window = mlx_new_window \
	(info->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "team:CRI");
}

int	lonely_together(int argc, char **argv)
{
	t_cub3d	*info;

	if (argc != 2)
		error_message("INVALID ARGUMENT COUNT!");
	info = xcalloc(1, sizeof(t_cub3d));
	info = parser(argv[1], info);
//	info = (t_cub3d *){0};
	is_valid_map(info->map);
	if (TEST == true)
	{
		initialize_mlx(info);
		initialize_object(info);
		play_gaming(info);
		mlx_loop(info->mlx);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);
	lonely_together(argc, argv);
}
