#include "cub3d.h"

int free_all(t_info *info)
{
	//should deal with ft_free
	return (1);
}

void mlx_hooks_and_loop(t_info info)
{
	mlx_hook(info.win_ptr, 2, 1L << 0, keymap, &info);
	//info is param of keymap function.
	mlx_hook(info.win_ptr, 33, 1L << 17, free_all, &info);
//	mlx_hook(info.win_ptr, 12, 1L < 15, rendering, &info);
	mlx_loop(info.mlx_ptr);
}

void init_info(t_info *info)
{
	info = calloc(sizeof(t_info), 1);
	info->player.x_pos = 100;//have no meaning.
	info->player.y_pos = 100;
	//not perfect.
}

int usage(void)
{
	printf(RED"invalid argument.\n"
		   "./cub [.cub file]\n"STOP);
	exit(EXIT_FAILURE);
}

char **init_map(char *map_str, t_info *info)
{

//	info->map.map_strs = NULL;
	return (info->map.map_strs);
}
void gnl_test(int argc, char **argv);
void launch_cub(int argc, char **argv);
int main(int argc, char **argv)
{
//	gnl_test(argc, argv);//this is only test...
	launch_cub(argc, argv);
}

void	launch_cub(int argc, char **argv)
{
	if (argc != 2)
		usage();//exit 1
	t_info info;
	init_info(&info);
	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr, 1000, 1000, "cub3d");//1000 have no meaning size.
	info.map.map_strs = init_map(argv[1], &info);
	mlx_hooks_and_loop(info);//↑want to get all info.
}

//void gnl_test(int argc, char **argv)
//{
//	char *file_path = argv[1];
//	int fd = open(file_path, O_RDONLY);
//	char *s = get_next_line(fd);
//	char *n2 = get_next_line(fd);
//	free(s);
//	free(n2);
//
//	char *s = get_next_line(fd);
//	printf("%s", s);
//	free(s);
//	while (s)//why leak
//	{
//		char *s = get_next_line(fd);
//		if (s == NULL)
//			return ;
//		printf("%s", s);
//		free(s);
//	}
//}
