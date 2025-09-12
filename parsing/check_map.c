/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:49:35 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:14:32 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdbool.h>

void	flood_fill(t_map *map, int y, int x, char replace)
{
	if (y < 0 || y >= map->count_line || x < 0 || x >= map->max_len)
		ft_error_exit(map, "Error\nMap not closed\n", true);
	if (map->padded_map[y][x] == '1' || map->padded_map[y][x] == 'V')
		return ;
	if (map->padded_map[y][x] == ' ')
		ft_error_exit(map, "Error\nMap not closed\n", true);
	map->padded_map[y][x] = replace;
	flood_fill(map, y + 1, x, 'V');
	flood_fill(map, y - 1, x, 'V');
	flood_fill(map, y, x + 1, 'V');
	flood_fill(map, y, x - 1, 'V');
	return ;
}

static bool	set_n_or_s_orientation(t_map *map, char orientation)
{
	if (orientation == 'N')
	{
		map->p_data->dir_x_p = 0;
		map->p_data->dir_y_p = -1;
		map->p_data->plane_x_p = 0.66;
		map->p_data->plane_y_p = 0;
		return (true);
	}
	else if (orientation == 'S')
	{
		map->p_data->dir_x_p = 0;
		map->p_data->dir_y_p = 1;
		map->p_data->plane_x_p = -0.66;
		map->p_data->plane_y_p = 0;
		return (true);
	}
	return (false);
}

void	set_player_orientation(t_map *map, char orientation)
{
	if (set_n_or_s_orientation(map, orientation))
		return ;
	else if (orientation == 'E')
	{
		map->p_data->dir_x_p = 1;
		map->p_data->dir_y_p = 0;
		map->p_data->plane_x_p = 0;
		map->p_data->plane_y_p = 0.66;
	}
	else if (orientation == 'W')
	{
		map->p_data->dir_x_p = -1;
		map->p_data->dir_y_p = 0;
		map->p_data->plane_x_p = 0;
		map->p_data->plane_y_p = -0.66;
	}
}

void	ft_init_player_angle(t_map *map, int y, int x, char point)
{
	map->p_data->xp = x + 0.51f;
	map->p_data->yp = y + 0.51f;
	map->number_p++;
	set_player_orientation(map, point);
}

void	find_player_and_count(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->padded_map[y])
	{
		x = 0;
		while (map->padded_map[y][x])
		{
			if (ft_is_cardinal_point(map->padded_map[y][x]))
				ft_init_player_angle(map, y, x, map->padded_map[y][x]);
			else if (map->padded_map[y][x] == 'D')
				ft_add_node(map, &map->doors, x, y);
			else if (!ft_is_cardinal_point(map->padded_map[y][x])
					&& !ft_is_map_element(map->padded_map[y][x]))
				ft_error_exit(map, "Error\nInvalid element in the map\n", true);
			x++;
		}
		y++;
	}
	if (map->number_p > 1 || map->number_p == 0)
		ft_error_exit(map, "Error\nInvalid number of player\n", true);
}
