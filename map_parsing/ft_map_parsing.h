#ifndef	FT_MAP_PARSING_H
#define	FT_MAP_PARSING_H

typedef struct map
{
	char **map;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	char *floor_color;

}	t_map;

void    ft_map_parsing(char **av);
void    ft_map_elem_check(char  *map, t_map *cub);
void    ft_texture_check(char *map, t_map *cub);
int		ft_alpha(char c, char **map);
void	ft_valide_path(char **map, t_map *cub, char c);
void	ft_rgb_valide(char *map, t_map *cub);
void	ft_texture_exit(t_map *cub);
void	ft_skip_space(char **map);
int		ft_get_len_new_line(char *map);
void	ft_add_txr_struc(char *tmp, t_map  *cub, char c);
void	ft_num_rgb(char *map, t_map *cub);
void	ft_rgb_error(t_map *cub, int kama);

#endif