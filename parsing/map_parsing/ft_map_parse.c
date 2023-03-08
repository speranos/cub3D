#include "../cub_parsing.h"

void	ft_map_elem_check(char **map, t_map *cub)
{
	ft_validate(cub);
	ft_skip_new_line(cub, map);
	ft_map_char_check(*map, cub);
	ft_add_map_to_strc(cub, map);
	ft_wall_check(cub);
	ft_last_check(cub);
}

void	ft_validate(t_map *cub)
{
	if (!cub->ceilling_rgb || !cub->floor_rgb)
		ft_map_error(cub, 'c');
	if (!cub->e_t || !cub->n_t || !cub->s_t || !cub->w_t)
		ft_map_error(cub, 't');
}

void	ft_map_error(t_map *cub, char c)
{
	if (c == 'c')
		printf("ERROR...Missing color\n");
	else if (c == 't')
		printf("ERROR...Missing texture\n");
	ft_texture_exit(cub);
}

