/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:43:54 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/11 15:23:20 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_define_delta_dist(t_map *map, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x == 0)
		map->ray_line->dda_data.delta_dst_x = 1e30;
	else
		map->ray_line->dda_data.delta_dst_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		map->ray_line->dda_data.delta_dst_y = 1e30;
	else
		map->ray_line->dda_data.delta_dst_y = fabs(1 / ray_dir_y);
}

void	ft_define_side_dist(t_map *map, double ray_dir_x,
	double ray_dir_y, int map_pos[2])
{
	if (ray_dir_x < 0)
	{
		map->ray_line->dda_data.step_x = -1;
		map->ray_line->dda_data.side_dst_x = (map->p_data->xp - map_pos[0])
			* map->ray_line->dda_data.delta_dst_x;
	}
	else
	{
		map->ray_line->dda_data.step_x = 1;
		map->ray_line->dda_data.side_dst_x = (map_pos[0] + 1 - map->p_data->xp)
			* map->ray_line->dda_data.delta_dst_x;
	}
	if (ray_dir_y < 0)
	{
		map->ray_line->dda_data.step_y = -1;
		map->ray_line->dda_data.side_dst_y = (map->p_data->yp - map_pos[1])
			* map->ray_line->dda_data.delta_dst_y;
	}
	else
	{
		map->ray_line->dda_data.step_y = 1;
		map->ray_line->dda_data.side_dst_y = (map_pos[1] + 1 - map->p_data->yp)
			* map->ray_line->dda_data.delta_dst_y;
	}
}

void	ft_define_hit_side_and_map_x_y(t_map *map, int *map_x, int *map_y)
{
	if (map->ray_line->dda_data.side_dst_x
		< map->ray_line->dda_data.side_dst_y)
	{
		map->ray_line->dda_data.side_dst_x
			+= map->ray_line->dda_data.delta_dst_x;
		*map_x += map->ray_line->dda_data.step_x;
		map->hit_side = 0;
	}
	else
	{
		map->ray_line->dda_data.side_dst_y
			+= map->ray_line->dda_data.delta_dst_y;
		*map_y += map->ray_line->dda_data.step_y;
		map->hit_side = 1;
	}
}

void	ft_ray_cicle(t_map *map, int *hit, int *map_x, int *map_y)
{
	t_doors	*current_doors;

	current_doors = NULL;
	while (*hit == 0)
	{
		ft_define_hit_side_and_map_x_y(map, map_x, map_y);
		if (*map_x < 0 || *map_y < 0
			|| *map_y >= map->count_line || *map_x >= map->max_len)
			break ;
		current_doors = ft_find_door(map->doors, *map_x, *map_y);
		if (map->real_map[*map_y][*map_x] == '1')
			*hit = 1;
		else if (current_doors && !current_doors->is_open)
		{
			map->_3d_data.is_door = true;
			map->_3d_data.is_open_door = false;
			*hit = 1;
		}
		else if (current_doors && current_doors->is_open)
		{
			map->_3d_data.is_door = true;
			map->_3d_data.is_open_door = true;
			*hit = 1;
		}
	}
}

double	ft_ray_casting(t_map *map, double ray_dir_x, double ray_dir_y)
{
	int		map_x;
	int		map_y;
	int		map_pos[2];
	int		hit;

	map_y = (int)map->p_data->yp;
	map_x = (int)map->p_data->xp;
	hit = 0;
	map_pos[0] = map_x;
	map_pos[1] = map_y;
	ft_define_delta_dist(map, ray_dir_x, ray_dir_y);
	ft_define_side_dist(map, ray_dir_x, ray_dir_y, map_pos);
	ft_ray_cicle(map, &hit, &map_x, &map_y);
	if (hit == 0)
		return (0);
	if (map->hit_side == 0)
		return ((map_x - map->p_data->xp
				+ (1.0 - (double)map->ray_line->dda_data.step_x) / 2.0)
			/ ray_dir_x);
	else
		return ((map_y - map->p_data->yp
				+ (1.0 - (double)map->ray_line->dda_data.step_y) / 2.0)
			/ ray_dir_y);
}
