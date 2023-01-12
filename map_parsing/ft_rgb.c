#include "../cub.h"

void	ft_rgb_valide(char *map, t_map *cub)
{
	(void)map;
	(void)cub;
	// map++;
	// ft_num_rgb(map, cub);
   // ft_num_to_struct(map, cub);
}

void	ft_num_rgb(char *map, t_map *cub)
{
	int	i;
	int	kama;
	
	i = 0;
	kama = 0;
	while(map[i] != '\n')
	{
		if(map[i] == ',')
			kama++;
		else if(map[i] <= 48 || map[i] >= 57)
            ft_rgb_error(cub, kama);
		else if(kama > 3)
		{
			printf("ERORR...RGB\n");
			ft_texture_exit(cub);
		}
		else
		{
			printf("ERORR...RGB\n");
			ft_texture_exit(cub);
		}
	}
}

void	ft_rgb_error(t_map *cub, int kama)
{
	(void)cub;
	(void)kama;
	exit(0);
}