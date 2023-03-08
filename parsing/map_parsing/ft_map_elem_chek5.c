#include "../cub_parsing.h"

void	ft_skip_new_line(t_map *cub, char **map)
{
	int	i;

	i = 0;
	while ((*map)[i] && (*map)[i] != '\n')
	{
		if ((*map)[i] >= 48 && (*map)[i] <= 57)
			break ;
		else if ((*map)[i] > 32)
			ft_wall_error(cub);
		i++;
	}
	if ((*map)[i] == '\n')
	{
		while (i >= 0)
		{
			(*map)++;
			i--;
		}
		ft_skip_new_line(cub, map);
	}
}
