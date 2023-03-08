#include "../cub_parsing.h"

void	ft_add_txr_struc(char *tmp, t_map *cub, char c)
{
	int	fd;

	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR...'%s' Invalid texture path !!!\n", tmp);
		ft_texture_exit(cub);
	}
	if (c == 'N' && !cub->n_t)
		cub->n_t = tmp;
	else if (c == 'S' && !cub->s_t)
		cub->s_t = tmp;
	else if (c == 'W' && !cub->w_t)
		cub->w_t = tmp;
	else if (c == 'E' && !cub->e_t)
		cub->e_t = tmp;
	else
	{
		printf("ERROR...Texture entered twice\n");
		ft_texture_exit(cub);
	}
}

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