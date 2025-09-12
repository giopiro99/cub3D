/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_external_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:11:19 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:14:36 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	external_flood_fill(t_map *map, int y, int x, char replace)
{
	if (y < 0 || y >= map->count_line || x < 0 || x >= map->max_len)
		return ;
	if (map->padded_map[y][x] == '1' || map->padded_map[y][x] == 'V')
		return ;
	if (map->padded_map[y][x] == '0')
		ft_error_exit(map, "Error\nMap not closed\n", true);
	map->padded_map[y][x] = replace;
	external_flood_fill(map, y + 1, x, 'V');
	external_flood_fill(map, y - 1, x, 'V');
	external_flood_fill(map, y, x + 1, 'V');
	external_flood_fill(map, y, x - 1, 'V');
	return ;
}

void	ft_check_external_spaces(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->max_len)
	{
		if (map->padded_map[0][x] == ' ')
			external_flood_fill(map, 0, x, 'V');
		if (map->padded_map[map->count_line - 1][x] == ' ')
			external_flood_fill(map, map->count_line - 1, x, 'V');
		x++;
	}
	while (y < map->count_line)
	{
		if (map->padded_map[y][0] == ' ')
			external_flood_fill(map, y, 0, 'V');
		if (map->padded_map[y][map->max_len - 1] == ' ')
			external_flood_fill(map, y, map->max_len - 1, 'V');
		y++;
	}
}
