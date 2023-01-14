#include "../cub.h"

void	ft_rgb_valide(char **map, t_map *cub)
{
	(void)map;
	(void)cub;
	(*map)++;
	ft_num_rgb(*map, cub);
	ft_num_to_struct(cub, map);
}

void	ft_num_rgb(char *map, t_map *cub)
{
	int	i;
	int	kama;
	
	i = 0;
	kama = 0;
	while(map[i] != '\n')
	{
		if(map[i] == ',' && (map[i - 1] >= 48 && map[i - 1] <= 57)
			&& (map[i + 1] >= 48 && map[i + 1] <= 57))
		{
			kama++;
			i++;
		}
		else if(map[i] >= 48 && map[i] <= 57)
			i++;
		else
			ft_rgb_error(cub, kama);
	}
	ft_kama_check(kama, cub);
}

void	ft_kama_check(int kama, t_map *cub)
{
	if(kama != 2)
		ft_rgb_error(cub, kama);
}

void	ft_rgb_error(t_map *cub, int kama)
{
	(void)kama;
	printf("ERORR...RGB\n");
	ft_texture_exit(cub);
}
 
void	ft_num_to_struct(t_map *cub, char **map)
{
	int	i;
	
	i = 0;
	(void)cub;
	while (*map[0] != '\n')
	{
		i = ft_rgb_atoi(map);
		printf("i ================ %d\n", i);
		if(*map[0] == '\n')
			break;
		(*map)++;
	}
	(*map)++;
	

}

int	ft_rgb_atoi(char **map)
{
	int	res;

	res = 0;
	while(*map[0] != ',' && *map[0] != '\n')
	{
		res = res * 10 + (*map[0] - 48);
		(*map)++;
		// printf("res ================ %d\n", res);
		// printf("map[0] =================== %c\n", *map[0]);
	}
	return(res);
}