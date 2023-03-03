#include "cub3d.h"

int main(int ac, char **av)
{
	t_map *game;

	game = malloc(sizeof(t_map));
	game->play = malloc(sizeof(t_player));
	game->imge = malloc(sizeof(t_img));
	game->cast = malloc(sizeof(t_cast));
	ft_check_arg(ac, av);
	cub3d(av, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D ALI FANBOY");
	struct_initialisation(game);
	ft_draw(game);
	mlx_hook(game->win, 02, (1L << 0), key_pressed, game->play);
	mlx_hook(game->win, 03, (1L << 1), key_release, game->play);
	mlx_loop_hook(game->mlx, ft_draw, game);
	mlx_loop(game->mlx);
	ft_rm_rf(game);
}