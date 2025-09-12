/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:21:10 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:11:14 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free_doors(t_map *map)
{
	t_doors	*tmp;
	t_doors	*current;

	tmp = NULL;
	current = map->doors;
	while (current)
	{
		tmp = current->next_door;
		free(current);
		current = tmp;
	}
}

void	ft_free_all(t_map *map)
{
	if (map)
	{
		ft_free_texture(map);
		ft_free_color(map);
		ft_free_doors(map);
		ft_free_all_maps(map);
		if (map->mlx_data)
			ft_free_mlx(map);
		if (map->p_data)
			free(map->p_data);
		if (map->keys)
			free(map->keys);
		if (map->ray_line)
			free(map->ray_line);
		free(map);
	}
}

void	ft_close_window(t_map *map)
{
	ft_free_all(map);
	exit(1);
}

void	ft_error_exit(t_map *map, char *message, bool error)
{
	if (message)
		ft_printf(2, "%s", message);
	ft_free_all(map);
	if (error)
		exit(1);
	exit (0);
}
