/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:17:24 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/18 14:10:10 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_check_cub(char *file_name)
{
	int	i;

	i = 0;
	if (!file_name)
		return (ft_printf(2, "Error\nNo map file\n"), false);
	if (ft_strncmp(file_name + (ft_strlen(file_name) - 4), ".cub", 4) == 0)
		return (true);
	else
		return (ft_printf(2, "Error\nMap not .cub\n"), false);
}

bool	check_all_texture(t_texture *texture)
{
	if (!texture->no_tex || !texture->so_tex
		|| !texture->we_tex || !texture->ea_tex)
		return (false);
	return (true);
}

bool	check_color_value(t_map *map)
{
	if ((map->floor_color->b > 255 || map->floor_color->b == -1)
		|| (map->floor_color->r > 255 || map->floor_color->r == -1)
		|| (map->floor_color->g > 255 || map->floor_color->g == -1))
		return (false);
	if ((map->ceiling_color->b > 255 || map->ceiling_color->b == -1)
		|| (map->ceiling_color->r > 255 || map->ceiling_color->r == -1)
		|| (map->ceiling_color->g > 255
			|| map->ceiling_color->g == -1))
		return (false);
	return (true);
}

bool	ft_check_rgb_format(char **color_matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (color_matrix[i])
	{
		while (color_matrix[i][j])
		{
			if (!ft_isdigit(color_matrix[i][j])
				&& color_matrix[i][j] != '\n'
					&& !ft_isspace(color_matrix[i][j]))
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}
