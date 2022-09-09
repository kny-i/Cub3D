/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 00:00:03 by vscabell          #+#    #+#             */
/*   Updated: 2020/07/28 03:30:41 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int	allocate_map(t_vars *vars)
{
	vars->map = ft_calloc(1, sizeof(t_map));
	vars->map->color_ceiling = -1;
	vars->map->color_floor = -1;
	vars->map->path = ft_calloc(5, sizeof(char *));
	vars->map->n_sprites = 0;
	vars->map->width = 0;
	vars->map->height = 0;
	vars->map->n_row = 0;
	vars->map->n_column = 0;
	if (!(vars->mlx = mlx_init()))
		return (ft_error(vars->map, -16));
	mlx_get_screen_size(vars->mlx, &vars->map->max_w, &vars->map->max_h);
	return (1);
}

int			close_program(void)
{
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_vars	vars;

	check_args(argc, argv);
	allocate_map(&vars);
	if (!read_file(argv[1], vars.map) || !(create_n_check(&vars)))
		return (0);
	init_game(&vars, argc);
	mlx_hook(vars.win, 2, (1l << 0), move_player_press, &vars);
	mlx_hook(vars.win, 17, (1l << 17), clean_before_close, &vars);
	mlx_loop_hook(vars.mlx, update_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}