/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:56:30 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/11 10:10:25 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define SCALE 32
# define SCALE2 8

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "parsing/ft_get_next_line/get_next_line.h"
# include "parsing/args_check/ft_args_check.h"
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*add_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_cast
{
	double	x_wall;
	double	y_wall;
	double	angle_ray;
	int		num_rays;
	double	dist;
	double	*dist_wall;
	double	*dist_wall2;
	double	*tab_x;
	double	*tab_y;
}	t_cast;

typedef struct player_s
{
	int		pos;
	double	angle;
	double	turn_direction;
	double	walk_direction;
	double	move_speed;
	double	turn_speed;
	double	rotation_speed;
	double	position_x_map;
	double	position_y_map;
	double	position_x;
	double	position_y;
	double	pos_x_m_map;
	double	pos_y_m_map;
	int		ad;
}	t_player;

typedef struct texture
{
	unsigned int	*image_data;
	void			*image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}	t_texture;

typedef struct map
{
	t_img		*imge;
	t_player	*play;
	t_cast		*cast;
	t_texture	create_pixel[4];
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	char		player;
	char		c0;
	char		c1;
	int			tmp;
	int			c_rgb;
	int			f_rgb;
	int			x;
	int			y;
	char		**map;
	int			*floor_rgb;
	int			*ceilling_rgb;
	char		*n_t;
	char		*s_t;
	char		*w_t;
	char		*e_t;
	int			offsetx;
	int			offsety;
	int			lowpixel;
	int			toppixel;

}	t_map;

int		set_tex_y(t_map *game, int mid, int i);
int		set_offsetx(t_map *game, int i, int d);
int		get_tex_color(t_map *game, int d, int index);
void	ft_rgb_to_hexa(t_map *cub, char c);
void	ft_read_map(char **av, t_map *cub);
void	ft_texture_check(char **map, t_map *cub);
void	ft_map_elem_check(char **map, t_map *cub);
void	ft_texture_check(char **map, t_map *cub);
int		ft_alpha(char c, char **map);
void	ft_valide_path(char **map, t_map *cub, char c0, char c1);
void	ft_rgb_valide(char **map, t_map *cub, char c);
void	ft_texture_exit(t_map *cub);
void	ft_skip_space(char **map);
int		ft_get_len_new_line(char *map);
void	ft_add_txr_struc(char *tmp, t_map *cub, char c);
void	ft_num_rgb(char *map, t_map *cub);
void	ft_rgb_error(t_map *cub);
void	ft_kama_check(int kama, t_map *cub);
void	ft_num_to_struct(t_map *cub, char **map, char c);
int		ft_rgb_atoi(char **map);
void	ft_add_floor(t_map *cub, char **map);
void	ft_add_ceilling(t_map *cub, char **map);
void	ft_map_error(t_map *cub, char c);
void	ft_validate(t_map *cub);
void	ft_undifiende_error(t_map *cub);
void	ft_check_second_char(t_map *cub, char c0, char c1);
int		ft_end_check(t_map *cub);
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
int		ft_len(char *str);
void	ft_texture_valid(char **map, t_map *cub);
void	put_pixels(t_map *game);

// RAYCASTING

int		ft_draw(t_map *game);
void	draw_walls(t_map *game);
void	floor_ceeling(t_map *cube);
void	ft_draw_player(t_map *game);
void	draw_circle(t_map *game);
void	update_player(t_player *player, t_map *game);
int		check_wall(t_map *game, int x, int y);
int		key_pressed(int key, t_player *player);
int		key_release(int key, t_player *player);
void	struct_initialisation(t_map *game);
void	player_init(t_map *game);
void	put_pixels(t_map *game);
void	print_rect(t_map *game, int x, int y, unsigned int color);
void	my_mlx_pixel_put(t_map *game, int x, int y, int color);
void	get_pos(t_map *game);
void	ft_img_init(t_img *img);
void	ft_image(t_map *game);
int		ft_strlen(char *s);
void	put_pixels_mini_map(t_map *game);
void	ft_draw_player_mini_map(t_map *game);
void	draw_circle_mini_map(t_map *game);
void	update_player_mini_map(t_player *player, t_map *game);
int		mouse_click(int key, int x, int y, t_map *game);
int		mouse_release(int key, int x, int y, t_map *game);
int		mouse_move(int x, int y, t_map *game);
void	texture_init(t_map *game);
void	get_distance(t_map *game, double *angle_ray, int j, double i);

#endif