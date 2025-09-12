/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:21:55 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 10:26:18 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	mouse_move(int x, int y, void *param)
{
	t_map	*map;

	(void)y;
	map = (t_map *)param;
	map->mouse.center_x = WIDTH / 2;
	map->mouse.delta_x = x - map->mouse.center_x;
	if (map->mouse.delta_x && !map->keys->q_press)
	{
		mlx_mouse_move(map->mlx_data->connection,
			map->mlx_data->window, map->mouse.center_x, HIGHT / 2);
		rotate_player(map, map->mouse.delta_x * 0.001);
	}
	return (0);
}

void	mouse_handler(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (button == 1 && !map->keys->q_press)
	{
		map->shooting = true;
		map->shooting_time = get_time_in_ms();
	}
	if (button == 3 && !map->keys->q_press)
	{
		if (!map->keys->shift_sx)
			map->keys->shift_sx = true;
		else
			map->keys->shift_sx = false;
	}
}

int	mouse_release(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	if (button == 3 && !map->keys->q_press)
		map->keys->shift_sx = false;
	return (0);
}
