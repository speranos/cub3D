#include "../cub_parsing.h"

void	ft_zero_check(t_map *cub, int line, int i)
{
	if (cub->map[line][i + 1] != '0' && cub->map[line][i + 1] != '1'
		&& cub->map[line][i + 1] != cub->player)
		ft_zero_error(cub);
	else if (cub->map[line][i - 1] != '0' && cub->map[line][i - 1] != '1'
		&& cub->map[line][i - 1] != cub->player)
		ft_zero_error(cub);
	else if (cub->map[line + 1][i] != '0' && cub->map[line + 1][i] != '1'
		&& cub->map[line + 1][i] != cub->player)
		ft_zero_error(cub);
	else if (cub->map[line - 1][i] != '0' && cub->map[line - 1][i] != '1'
		&& cub->map[line - 1][i] != cub->player)
		ft_zero_error(cub);
}

void	ft_p_check(t_map *cub, int line, int i)
{
	if (cub->map[line][i + 1] != '0' && cub->map[line][i + 1] != '1')
		ft_p_error(cub);
	else if (cub->map[line][i - 1] != '0' && cub->map[line][i - 1] != '1')
		ft_p_error(cub);
	else if (cub->map[line + 1][i] != '0' && cub->map[line + 1][i] != '1')
		ft_p_error(cub);
	else if (cub->map[line - 1][i] != '0' && cub->map[line - 1][i] != '1')
		ft_p_error(cub);
}

void	ft_zero_error(t_map *cub)
{
	printf("ERROR...'0' Should be surrounded by '0' or '1' or 'player'\n");
	ft_texture_exit(cub);
}

void	ft_p_error(t_map *cub)
{
	printf("ERROR...Player should be surrounded by '0' or '1'\n");
	ft_texture_exit(cub);
}
