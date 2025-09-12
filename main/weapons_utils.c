/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:16:21 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:17:48 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_draw_mini_gun(t_map *map)
{
	t_texture_data	*gun_texture;

	gun_texture = &map->texture->load_texture[5];
	my_put_image(map->mlx_data, gun_texture, WIDTH - 1500, HIGHT - 603);
}

void	ft_draw_sniper(t_map *map)
{
	t_texture_data	*gun_texture;

	gun_texture = &map->texture->load_texture[7];
	my_put_image(map->mlx_data, gun_texture, WIDTH - 1440, HIGHT - 900);
}

void	ft_draw_scope(t_map *map)
{
	t_texture_data	*scope_texture;

	scope_texture = &map->texture->load_texture[6];
	my_put_image(map->mlx_data, scope_texture, 0, 0);
}

void	ft_define_weapon(t_map *map)
{
	if (map->keys->one_press)
	{
		if (map->current_weapon == WEAPON_GUN)
			map->current_weapon = WEAPON_NONE;
		else
			map->current_weapon = WEAPON_GUN;
		map->keys->one_press = false;
	}
	else if (map->keys->two_press)
	{
		if (map->current_weapon == WEAPON_SNIPER)
			map->current_weapon = WEAPON_NONE;
		else
			map->current_weapon = WEAPON_SNIPER;
		map->keys->two_press = false;
	}
}
