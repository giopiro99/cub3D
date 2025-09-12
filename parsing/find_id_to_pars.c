/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_id_to_pars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:40:34 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/06/10 17:57:43 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_find_texture_id(t_map *map, char *trimmed_line)
{
	if (!ft_strncmp(trimmed_line, "NO ", 3))
	{
		if (!ft_extract_texture(&map->texture->no_tex, trimmed_line + 3))
			return (false);
	}
	else if (!ft_strncmp(trimmed_line, "EA ", 3))
	{
		if (!ft_extract_texture(&map->texture->ea_tex, trimmed_line + 3))
			return (false);
	}
	else if (!ft_strncmp(trimmed_line, "WE ", 3))
	{
		if (!ft_extract_texture(&map->texture->we_tex, trimmed_line + 3))
			return (false);
	}
	else if (!ft_strncmp(trimmed_line, "SO ", 3))
	{
		if (!ft_extract_texture(&map->texture->so_tex, trimmed_line + 3))
			return (false);
	}
	return (true);
}

bool	ft_find_color_id(t_map *map, char *trimmed_line, int *id_count)
{
	if (!ft_strncmp(trimmed_line, "F ", 2))
	{
		if (!ft_extract_color(map->floor_color, trimmed_line + 2))
			return (false);
		(*id_count)++;
	}
	else if (!ft_strncmp(trimmed_line, "C ", 2))
	{
		if (!ft_extract_color(map->ceiling_color, trimmed_line + 2))
			return (false);
		(*id_count)++;
	}
	return (true);
}
