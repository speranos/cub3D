#include "../cub_parsing.h"

char	ft_wall_zero(t_map *cub, int line)
{
	int		i;
	char	c;

	i = 0;
	while (cub->map[line][i] && cub->map[line][i] <= 32)
		i++;
	c = cub->map[line][i];
	return (c);
}

char	ft_wall_end(t_map *cub, int line)
{
	int		i;
	char	c;

	i = 0;
	while (cub->map[line][i] && cub->map[line][i] != '*')
		i++;
	if (i <= 0)
		ft_wall_error(cub);
	c = cub->map[line][i - 1];
	return (c);
}

void	ft_first_wall(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map[0][i] != '*')
	{
		if (cub->map[0][i] >= 32 || cub->map[0][i] == 49)
			i++;
		else
			ft_wall_error(cub);
	}
}

void	ft_last_wall(t_map *cub, int line)
{
	int	i;

	i = 0;
	while (cub->map[line][i] != '*')
	{
		if (cub->map[line][i] <= 32 || cub->map[line][i] == 49)
			i++;
		else
			ft_wall_error(cub);
	}
}
