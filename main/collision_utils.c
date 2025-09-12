/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:25:25 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:36:28 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	ft_get_collision(t_map *map, const float offsets[8][2],
	float new_x, float new_y)
{
	char	cell;
	int		i;
	int		check_x;
	int		check_y;
	t_doors	*current_door;

	i = 0;
	cell = 0;
	while (i < 8)
	{
		check_x = (int)(new_x + offsets[i][0]);
		check_y = (int)(new_y + offsets[i][1]);
		current_door = ft_find_door(map->doors, check_x, check_y);
		if (check_x < 0 || check_y < 0
			|| check_y >= map->count_line
			|| check_x >= map->max_len)
			return (true);
		cell = map->real_map[check_y][check_x];
		if (cell == '1' || cell == ' '
			|| (current_door && !current_door->is_open))
			return (true);
		i++;
	}
	return (false);
}

bool	check_wall_collision(t_map *map, float new_x, float new_y)
{
	static const float	offsets[8][2] = {
	{-PADDING_SQUARE, -PADDING_SQUARE}, {0, -PADDING_SQUARE},
	{+PADDING_SQUARE, -PADDING_SQUARE}, {-PADDING_SQUARE, 0},
	{+PADDING_SQUARE, 0}, {-PADDING_SQUARE, +PADDING_SQUARE},
	{0, +PADDING_SQUARE}, {+PADDING_SQUARE, +PADDING_SQUARE}};

	if (ft_get_collision(map, offsets, new_x, new_y))
		return (true);
	return (false);
}
