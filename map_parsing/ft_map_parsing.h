#ifndef	FT_MAP_PARSING_H
#define	FT_MAP_PARSING_H

typedef struct map
{
	char	c0;
	char	c1;
	char	player;
	int		tmp;
	int		x;
	int		y;
	char **map;
	int  *floor_rgb;
	int  *ceilling_rgb;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;

}	t_map;

void    ft_map_parsing(char **av, t_map *cub);
void    ft_map_elem_check(char  **map, t_map *cub);
void    ft_texture_check(char **map, t_map *cub);
int		ft_alpha(char c, char **map);
void	ft_valide_path(char **map, t_map *cub, char c0, char c1);
void	ft_rgb_valide(char **map, t_map *cub, char c);
void	ft_texture_exit(t_map *cub);
void	ft_skip_space(char **map);
int		ft_get_len_new_line(char *map);
void	ft_add_txr_struc(char *tmp, t_map  *cub, char c);
void	ft_num_rgb(char *map, t_map *cub);
void	ft_rgb_error(t_map *cub);
void	ft_kama_check(int kama, t_map *cub);
void	ft_num_to_struct(t_map *cub, char **map, char c);
int		ft_rgb_atoi(char **map);
void	ft_add_floor(t_map *cub, char **map);
void	ft_add_ceilling(t_map *cub, char **map);
void    ft_map_error(t_map *cub, char c);
void    ft_validate(t_map *cub);
void	ft_undifiende_error(t_map *cub);
void	ft_check_second_char(t_map *cub, char c0, char c1);
int		ft_end_check(t_map *cub);
void	ft_to_vald_texture(char **map, t_map *cub);
void	ft_add_map_to_strc(t_map *cub, char **map);
int		ft_get_gbl_len_of_line(char *map);
int		ft_get_num_of_line(char *mp);
void	ft_skip_new_line(t_map *cub, char **map);
void	ft_wall_error(t_map *cub);
void	ft_map_to_map(t_map *cub, char *map, int num_of_line, int len);
int		ft_stars(t_map *cub, int a, int line, int len);
void	ft_map_char_check(char *map, t_map *cub);
void	ft_diff_element(t_map *cub, char c);
void	ft_player_erro(t_map *cub);
void	ft_wall_check(t_map *cub);
void	ft_zero_check(t_map *cub, int line, int i);
void	ft_p_check(t_map *cub, int line, int i);
void	ft_last_check(t_map *cub);
void	ft_zero_error(t_map *cub);
void	ft_p_error(t_map *cub);
char	ft_wall_zero(t_map *cub, int line);
char	ft_wall_end(t_map *cub, int line);
void	ft_first_wall(t_map *cub);
void	ft_last_wall(t_map *cub, int line);
void	ft_free_map(t_map *cub);
void	ft_free_element(t_map *cub);
void	ft_rm_rf(t_map *cub);

#endif