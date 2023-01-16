#include "../cub.h"

void    ft_map_elem_check(char  **map, t_map *cub)
{
	(void)map;
	ft_validate(cub);
	
}

void    ft_validate(t_map *cub)
{
	// printf("texture ========================= %s\n", cub->east_texture);
	if(!cub->ceilling_rgb || !cub->floor_rgb)
		ft_map_error(cub, 'c');
	if(!cub->east_texture || !cub->north_texture
		|| !cub->south_texture || !cub->west_texture)
		ft_map_error(cub, 't');
}

void    ft_map_error(t_map *cub, char c)
{
	if(c == 'c')
		printf("ERROR...Missing color\n");
	else if(c == 't')
		printf("ERROR...Missing texture\n");
	// else if()
	ft_texture_exit(cub);
}