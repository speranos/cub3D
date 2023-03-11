/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 07:45:47 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/11 12:14:29 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	ft_malloc(t_map *game)
{
	game->play = malloc(sizeof(t_player));
	game->imge = malloc(sizeof(t_img));
	game->cast = malloc(sizeof(t_cast));
	game->cast->dist_wall = malloc(sizeof(double) * 1080);
	game->cast->dist_wall2 = malloc(sizeof(double) * 1080);
	game->cast->tab_x = malloc(sizeof(double) * 1080);
	game->cast->tab_y = malloc(sizeof(double) * 1080);
}

int	main(int ac, char **av)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	ft_malloc(game);
	ft_check_arg(ac, av);
	ft_read_map(av, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	struct_initialisation(game);
	ft_draw(game);
	mlx_hook(game->win, 04, (1L << 2), mouse_click, game);
	mlx_hook(game->win, 05, (1L << 3), mouse_release, game);
	mlx_hook(game->win, 06, (1L << 9), mouse_move, game);
	mlx_hook(game->win, 02, (1L << 0), key_pressed, game->play);
	mlx_hook(game->win, 03, (1L << 1), key_release, game->play);
	mlx_hook(game->win, 17, 0, ft_close, game);
	mlx_loop_hook(game->mlx, ft_draw, game);
	mlx_loop(game->mlx);
	ft_rm_rf(game);
}
