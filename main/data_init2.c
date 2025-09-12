/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:24:04 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:16:03 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_data(t_map *map)
{
	ft_init_map_data(map);
	ft_color_init(map);
	ft_init_player_data(map);
	ft_init_ray_data(map);
}

void	ft_mlx_init(t_map *map)
{
	map->mlx_data->window = NULL;
	map->mlx_data->addr = NULL;
	map->mlx_data->bpp = 0;
	map->mlx_data->img = NULL;
	map->mlx_data->endian = 0;
	map->mlx_data->size_len = 0;
	map->mlx_data->connection = NULL;
}

void	ft_init_ray_data(t_map *map)
{
	map->ray_line = malloc(sizeof(t_ray));
	if (!map->ray_line)
		ft_error_exit(map, "Error\nMalloc error\n", true);
	ft_init_ray_line(map->ray_line);
}

void	ft_init_keys(t_map *map)
{
	map->keys->w_press = false;
	map->keys->a_press = false;
	map->keys->s_press = false;
	map->keys->d_press = false;
	map->keys->e_press = false;
	map->keys->q_press = false;
	map->keys->shift_sx = false;
	map->keys->left_press = false;
	map->keys->one_press = false;
	map->keys->two_press = false;
	map->keys->right_press = false;
	map->keys->mouse_sx = false;
}

void	ft_init_ray_line(t_ray *ray_line)
{
	ray_line->bresenham_data.done = 0;
	ray_line->bresenham_data.dx = 0;
	ray_line->bresenham_data.dy = 0;
	ray_line->bresenham_data.e2 = 0;
	ray_line->bresenham_data.err = 0;
	ray_line->bresenham_data.sx = 0;
	ray_line->bresenham_data.sy = 0;
	ray_line->dda_data.delta_dst_x = 0;
	ray_line->dda_data.delta_dst_y = 0;
	ray_line->dda_data.side_dst_x = 0;
	ray_line->dda_data.side_dst_y = 0;
	ray_line->angle_step = 0;
	ray_line->perp_wall = 0;
	ray_line->hit_x = 0;
	ray_line->hit_y = 0;
}
