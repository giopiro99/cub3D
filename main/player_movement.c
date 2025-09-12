/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:06:28 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/11 14:22:22 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_handle_movement_keys(t_map *map, float *dx, float *dy)
{
	if (map->keys->w_press)
	{
		*dx += map->p_data->dir_x_p;
		*dy += map->p_data->dir_y_p;
	}
	if (map->keys->s_press)
	{
		*dx -= map->p_data->dir_x_p;
		*dy -= map->p_data->dir_y_p;
	}
	if (map->keys->a_press)
	{
		*dx -= map->p_data->plane_x_p;
		*dy -= map->p_data->plane_y_p;
	}
	if (map->keys->d_press)
	{
		*dx += map->p_data->plane_x_p;
		*dy += map->p_data->plane_y_p;
	}
}

void	get_keys_and_move(t_map *map, float *dx, float *dy)
{
	if (map->keys->left_press)
		rotate_player(map, -ROT_SPEED);
	if (map->keys->right_press)
		rotate_player(map, ROT_SPEED);
	ft_handle_movement_keys(map, dx, dy);
	if (map->keys->e_press && !map->keys->q_press)
		ft_door_is_near(map, map->p_data->xp, map->p_data->yp);
}

void	move_player(t_map *map)
{
	float	dx;
	float	dy;
	float	length;
	float	new_x;
	float	new_y;

	dx = 0;
	dy = 0;
	length = 0;
	get_keys_and_move(map, &dx, &dy);
	length = sqrtf(dx * dx + dy * dy);
	if (length != 0)
	{
		dx = (dx / length) * SPEED;
		dy = (dy / length) * SPEED;
	}
	new_x = map->p_data->xp + dx;
	if (!check_wall_collision(map, new_x, map->p_data->yp))
		map->p_data->xp = new_x;
	new_y = map->p_data->yp + dy;
	if (!check_wall_collision(map, map->p_data->xp, new_y))
		map->p_data->yp = new_y;
}

void	rotate_player(t_map *map, double angle)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = map->p_data->dir_x_p;
	old_dir_y = map->p_data->dir_y_p;
	old_plane_x = map->p_data->plane_x_p;
	old_plane_y = map->p_data->plane_y_p;
	map->p_data->dir_x_p = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	map->p_data->dir_y_p = old_dir_x * sin(angle) + old_dir_y * cos(angle);
	map->p_data->plane_x_p = old_plane_x * cos(angle)
		- old_plane_y * sin(angle);
	map->p_data->plane_y_p = old_plane_x * sin(angle)
		+ old_plane_y * cos(angle);
}
