/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:42:04 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:15:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handle_wasd(int keysym, t_map *map)
{
	if (keysym == XK_w)
		map->keys->w_press = true;
	else if (keysym == XK_a)
		map->keys->a_press = true;
	else if (keysym == XK_s)
		map->keys->s_press = true;
	else if (keysym == XK_d)
		map->keys->d_press = true;
}

void	handle_arrows(int keysym, t_map *map)
{
	if (keysym == XK_Left)
		map->keys->left_press = true;
	else if (keysym == XK_Right)
		map->keys->right_press = true;
}

void	handle_one_and_two(int keysym, t_map *map)
{
	if (keysym == XK_1)
	{
		if (!map->keys->one_press)
			map->keys->one_press = true;
		else if (map->keys->one_press)
			map->keys->one_press = false;
	}
	else if (keysym == XK_2)
	{
		if (!map->keys->two_press)
			map->keys->two_press = true;
		else if (map->keys->two_press)
			map->keys->two_press = false;
	}
}

int	key_press(int keysym, t_map *map)
{
	handle_wasd(keysym, map);
	handle_arrows(keysym, map);
	handle_one_and_two(keysym, map);
	if (keysym == XK_e)
		map->keys->e_press = true;
	else if (keysym == XK_q)
	{
		if (!map->keys->q_press)
			map->keys->q_press = true;
		else if (map->keys->q_press)
			map->keys->q_press = false;
	}
	else if (keysym == XK_Shift_L)
		map->keys->shift_sx = true;
	else if (keysym == XK_Escape)
		ft_error_exit(map, "", false);
	return (0);
}

int	key_release(int keysym, t_map *map)
{
	if (keysym == XK_w)
		map->keys->w_press = false;
	else if (keysym == XK_a)
		map->keys->a_press = false;
	else if (keysym == XK_s)
		map->keys->s_press = false;
	else if (keysym == XK_d)
		map->keys->d_press = false;
	else if (keysym == XK_Left)
		map->keys->left_press = false;
	else if (keysym == XK_e)
		map->keys->e_press = false;
	else if (keysym == XK_Right)
		map->keys->right_press = false;
	else if (keysym == XK_Shift_L)
		map->keys->shift_sx = false;
	return (0);
}
