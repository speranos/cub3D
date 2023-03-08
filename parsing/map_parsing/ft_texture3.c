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
