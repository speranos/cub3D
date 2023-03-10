#include "../cub_parsing.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_rgb_to_hexa(t_map *cub, char c)
{
	if(c == 'c')
		cub->c_rgb = create_trgb(cub->ceilling_rgb[0], cub->ceilling_rgb[1], cub->ceilling_rgb[2]);
	else
		cub->f_rgb = create_trgb(cub->floor_rgb[0], cub->floor_rgb[1], cub->floor_rgb[2]);
}