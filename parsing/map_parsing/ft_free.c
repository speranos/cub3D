#include "../cub_parsing.h"

void	ft_rm_rf(t_map *cub)
{
	ft_free_map(cub);
	ft_free_element(cub);
}

void	ft_free_map(t_map *cub)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (cub->map[line])
	{
		free(cub->map[line++]);
	}
	free(cub->map);
}

void	ft_free_element(t_map *cub)
{
	if (cub->n_t)
		free(cub->n_t);
	if (cub->e_t)
		free(cub->e_t);
	if (cub->s_t)
		free(cub->s_t);
	if (cub->w_t)
		free(cub->w_t);
	if (cub->ceilling_rgb)
		free(cub->ceilling_rgb);
	if (cub->floor_rgb)
		free(cub->floor_rgb);
}
