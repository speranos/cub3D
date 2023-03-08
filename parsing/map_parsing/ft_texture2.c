#include "../cub_parsing.h"

void	ft_texture_exit(t_map *cub)
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
	exit(0);
}

void	ft_undifiende_error(t_map *cub)
{
	printf("ERROR...Undifiende character: %c\n", cub->c0);
	ft_texture_exit(cub);
}

void	ft_check_second_char(t_map *cub, char c0, char c1)
{
	if (c0 == 'N' && c1 == 'O')
		return ;
	else if (c0 == 'S' && c1 == 'O')
		return ;
	else if (c0 == 'W' && c1 == 'E')
		return ;
	else if (c0 == 'E' && c1 == 'A')
		return ;
	else
	{
		printf("ERROR...Element not valide\n");
		ft_texture_exit(cub);
	}
}

int	ft_end_check(t_map *cub)
{
	if (cub->ceilling_rgb && cub->e_t && cub->floor_rgb
		&& cub->n_t && cub->s_t && cub->w_t)
		return (1);
	return (0);
}

void	ft_to_vald_texture(char **map, t_map *cub)
{
	(*map)++;
	cub->c1 = *map[0];
	ft_valide_path(map, cub, cub->c0, cub->c1);
}
