/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:05:54 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/11 14:22:28 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_add_node(t_map *map, t_doors **doors, int x, int y)
{
	t_doors	*new_door;

	new_door = NULL;
	new_door = malloc(sizeof(t_doors));
	if (!new_door)
		return ;
	new_door->x = x;
	new_door->y = y;
	new_door->is_open = false;
	new_door->center_x = 0;
	new_door->center_y = 0;
	new_door->distance = 0;
	new_door->dx = 0;
	new_door->dy = 0;
	new_door->_3d_data = &map->_3d_data;
	new_door->next_door = *doors;
	*doors = new_door;
}

t_doors	*ft_find_door(t_doors *door, int x, int y)
{
	while (door)
	{
		if (door->x == x && door->y == y)
			return (door);
		door = door->next_door;
	}
	return (NULL);
}

void	ft_door_is_near(t_map *map, double x, double y)
{
	t_doors	*door;
	double	max_distance;
	double	min_distance;

	min_distance = 1.25;
	max_distance = 1.5;
	door = map->doors;
	while (door)
	{
		door->center_x = door->x + 0.5;
		door->center_y = door->y + 0.5;
		door->dx = door->center_x - x;
		door->dy = door->center_y - y;
		door->distance = sqrt(door->dx * door->dx + door->dy * door->dy);
		if (door->distance < max_distance && door->distance > min_distance)
		{
			if (door->is_open)
				door->is_open = false;
			else
				door->is_open = true;
		}
		door = door->next_door;
	}
}
