/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:12:48 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:18:14 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_init_open_doors_frame(t_map *map)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		map->texture->open_doors_texture[i].addr = 0;
		map->texture->open_doors_texture[i].bpp = 0;
		map->texture->open_doors_texture[i].endian = 0;
		map->texture->open_doors_texture[i].img = 0;
		map->texture->open_doors_texture[i].size_len = 0;
		map->texture->open_doors_texture[i].height = 0;
		map->texture->open_doors_texture[i].width = 0;
		i++;
	}
}

void	ft_init_texture_data(t_map *map)
{
	int	i;

	i = 0;
	map->texture->no_tex = NULL;
	map->texture->we_tex = NULL;
	map->texture->ea_tex = NULL;
	map->texture->so_tex = NULL;
	while (i < 10)
	{
		map->texture->load_texture[i].addr = 0;
		map->texture->load_texture[i].bpp = 0;
		map->texture->load_texture[i].endian = 0;
		map->texture->load_texture[i].img = 0;
		map->texture->load_texture[i].size_len = 0;
		map->texture->load_texture[i].height = 0;
		map->texture->load_texture[i].width = 0;
		i++;
	}
	ft_init_open_doors_frame(map);
}
