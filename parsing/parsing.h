/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:06:46 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:11:41 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

# ifndef MPI
#  define MPI 3.14159265358979323846

# endif

typedef struct s_doors	t_doors;

typedef enum s_textures_enum
{
	SOUTH,
	NORTH,
	EAST,
	WEST,
	CLS_DOOR,
	MINI_GUN_TEX,
	GUN_SCOPE,
	RIFLE_TEX,
	FIRE_SNIPER,
	OPN_DOOR,
}	t_textures_enum;

typedef struct s_column
{
	int		y;
	int		color;
	int		offset;
	double	step;
	double	tex_pos;
}	t_column;

typedef struct s_3d
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	dist_to_wall;
	double	line_height;
	double	draw_start;
	double	draw_end;
	double	wall_x;
	bool	is_door;
	bool	is_open_door;
	int		tex_x;
	int		tex_y;
	int		tex_index;
}	t_3d;

typedef struct s_doors
{
	int		x;
	int		y;
	bool	is_open;
	double	center_x;
	double	center_y;
	double	dx;
	double	dy;
	double	distance;
	t_3d	*_3d_data;
	t_doors	*next_door;
}				t_doors;

typedef struct s_mouse_data
{
	int		delta_x;
	int		last_x;
	int		current_x;
	double	center_x;
	int		center_y;
}				t_mouse_data;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		done;
	int		ray_x0;
	int		ray_x1;
	int		ray_y0;
	int		ray_y1;
}	t_bresenham;

typedef struct s_dda
{
	double	delta_dst_x;
	double	delta_dst_y;
	double	side_dst_x;
	double	side_dst_y;
	int		step_x;
	int		step_y;
}	t_dda;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	double		angle_step;
	double		perp_wall;
	double		dir_x;
	double		dir_y;
	double		hit_x;
	double		hit_y;
	t_bresenham	bresenham_data;
	t_dda		dda_data;
}	t_ray;

typedef struct s_key
{
	bool	w_press;
	bool	a_press;
	bool	s_press;
	bool	d_press;
	bool	e_press;
	bool	q_press;
	bool	shift_sx;
	bool	one_press;
	bool	two_press;
	bool	mouse_sx;
	bool	left_press;
	bool	right_press;
}	t_key;

typedef struct s_mlx
{
	void	*connection;
	void	*window;
	void	*img;
	char	*addr;
	int		size_len;
	int		endian;
	int		bpp;
}	t_mlx;

typedef struct s_texture_data
{
	void	*img;
	char	*addr;
	int		size_len;
	int		endian;
	int		bpp;
	int		width;
	int		height;
}	t_texture_data;

typedef struct s_texture
{
	char			*no_tex;
	char			*so_tex;
	char			*we_tex;
	char			*ea_tex;
	int				frame;
	double			open_door_timer;
	double			open_door_delay;
	t_textures_enum	texture_type;
	t_texture_data	open_doors_texture[11];
	t_texture_data	load_texture[11];
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	float	xp;
	float	yp;
	float	dir_x_p;
	float	dir_y_p;
	float	angle;
	float	fov;
	float	plane_x_p;
	float	plane_y_p;
}	t_player;

typedef enum e_weapon
{
	WEAPON_NONE,
	WEAPON_GUN,
	WEAPON_SNIPER
}	t_weapon;

typedef struct s_map
{
	t_texture		*texture;
	t_color			*floor_color;
	t_color			*ceiling_color;
	t_mlx			*mlx_data;
	t_player		*p_data;
	t_key			*keys;
	t_ray			*ray_line;
	t_mouse_data	mouse;
	t_doors			*doors;
	t_3d			_3d_data;
	t_weapon		current_weapon;
	bool			shooting;
	int				shooting_time;
	char			**padded_map;
	char			**real_map;
	char			*file_name;
	int				max_len;
	int				count_line;
	int				number_p;
	int				hit_side;
}	t_map;

//parsing
void	ft_parsing(t_map *map);
bool	ft_parsing_texture(t_map *map);
bool	ft_parsing_color(t_map *map);
bool	ft_parsing_file(char *file);
//extract_data
bool	ft_extract_color(t_color *color, char *line);
bool	ft_extract_texture(char **texture, char *line);
//check_data
bool	ft_check_cub(char *file_name);
bool	check_all_texture(t_texture *texture);
bool	check_color_value(t_map *map);
bool	ft_check_rgb_format(char **color_matrix);
//find_id_to_pars
bool	ft_find_texture_id(t_map *map, char *trimmed_line);
bool	ft_find_color_id(t_map *map, char *trimmed_line, int *id_count);
//map check
bool	ft_is_only_spaces_tabs(char *line);
bool	ft_is_empty_line(char *line);
bool	process_map_line(t_map *map, char *line,
			bool *map_ended, bool *space_line_after_map);
void	check_double_map(t_map *map);
void	init_padded_map(t_map *map);
void	get_padded_map(t_map *map);
int		get_n_line(t_map *map);
int		get_max_len(t_map *map);
int		take_max_len(char **trimmed_line, int *len, char **line, int fd);
void	skip_until_map(char **line, int fd);
bool	ft_is_line_map(char *line);
void	find_player_and_count(t_map *map);
void	ft_fill_real_map(t_map *map);
void	flood_fill(t_map *map, int y, int x, char replace);
bool	ft_is_cardinal_point(char point);
bool	ft_is_map_element(char point);
bool	ft_is_color(char point);
int		ft_count_commas(char *line);
void	ft_error_exit(t_map *map, char *message, bool error);
//mlx_function
void	ft_fill_mlx(t_map *map);
void	ft_draw(t_map *map);
void	set_player_orientation(t_map *map, char orientation);
//doors utils
t_doors	*ft_find_door(t_doors *door, int x, int y);
void	ft_add_node(t_map *map, t_doors **doors, int x, int y);
void	ft_door_is_near(t_map *map, double x, double y);
//external checks
void	external_flood_fill(t_map *map, int y, int x, char replace);
void	ft_check_external_spaces(t_map *map);
#endif
