/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:34:04 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:21:48 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <sys/time.h>
# define BLOCK_SIZE 9
# define SPEED 0.1
# define ROT_SPEED 0.05
# define PADDING_SQUARE 0.449
# define FOV 60
# define RAY_FOR_FOV 600
# define WIDTH 1920.0
# define HIGHT 994.0
# define TEXTURE_H 64
# define TEXTURE_W 64
# define DOOR_FRAMES 11
# define FRAME_DURATION 150
# define RADIUS 50

//data init
void	ft_init_map_data(t_map *map);
void	ft_color_init(t_map *map);
void	ft_init_data(t_map *map);
void	ft_init_ray_line(t_ray *ray_line);
void	ft_init_player_data(t_map *map);
void	ft_init_ray_data(t_map *map);
void	ft_init_keys(t_map *map);
void	ft_mlx_init(t_map *map);
void	ft_init_texture_data(t_map *map);
//free function
void	ft_free_all(t_map *map);
void	ft_free_texture(t_map *map);
void	ft_free_color(t_map *map);
void	ft_free_all_maps(t_map *map);
void	ft_free_mlx(t_map *map);
void	ft_close_window(t_map *map);
//player movement
void	rotate_player(t_map *map, double angle);
bool	check_wall_collision(t_map *map, float new_x, float new_y);
void	move_player(t_map *map);
void	rotate_player(t_map *map, double angle);
//handle keys
int		key_press(int keysym, t_map *map);
int		key_release(int keysym, t_map *map);
//drawing utils
void	render_3d_view(t_map *map, t_mlx *mlx);
void	draw_textured_column(t_mlx *mlx, int x, t_3d *_3d_data, t_texture *tex);
void	ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void	ft_draw_player(t_map *map);
void	draw_line(t_map *map, t_ray *ray_line, int color);
void	draw_ray_on_minimap(t_map *map);
double	ft_ray_casting(t_map *map, double ray_dir_x, double ray_dir_y);
void	my_put_image(t_mlx *mlx, t_texture_data *tex, int d_x, int d_y);
void	ft_draw_scope(t_map *map);
int		convert_color(int r, int g, int b);
void	ft_draw_block(t_mlx *mlx, int x, int y, int color);
int		is_inside_circle(int x, int y, int center_x, int center_y);
void	ft_draw_circle(int x, int y, t_map *map);
void	ft_draw_door_frame(t_mlx *mlx, int x, t_3d *_3d_data, t_texture *tex);
void	draw_circular_minimap(t_map *map);
//mouse function
int		mouse_move(int x, int y, void *param);
void	mouse_handler(int button, int x, int y, t_map *map);
int		mouse_release(int button, int x, int y, t_map *map);
//weapon utils
void	ft_draw_mini_gun(t_map *map);
void	ft_draw_sniper(t_map *map);
void	ft_draw_scope(t_map *map);
void	ft_define_weapon(t_map *map);
//texture utils
void	ft_load_all_texture(t_map *map);
int		ft_load_texture(t_map *map, char *path, int direction);
void	ft_define_texture(t_3d *_3d_data, int hit_flag);
//animation
int		get_time_in_ms(void);
int		calculate_frame(void);
int		update_door_animation(t_map *map);
void	draw_player_direction_ray(t_map *map, t_ray *ray);
#endif
