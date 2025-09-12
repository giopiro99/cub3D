/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:25:24 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 13:09:05 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free_doors_frame(t_map *map)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (map->texture->open_doors_texture[i].img)
			mlx_destroy_image(map->mlx_data->connection,
				map->texture->open_doors_texture[i].img);
		i++;
	}
}

void	ft_free_texture(t_map *map)
{
	int	i;

	i = 0;
	if (map->texture->no_tex)
		free(map->texture->no_tex);
	if (map->texture->so_tex)
		free(map->texture->so_tex);
	if (map->texture->we_tex)
		free(map->texture->we_tex);
	if (map->texture->ea_tex)
		free(map->texture->ea_tex);
	while (i < 10)
	{
		if (map->texture->load_texture[i].img)
			mlx_destroy_image(map->mlx_data->connection,
				map->texture->load_texture[i].img);
		i++;
	}
	ft_free_doors_frame(map);
	if (map->texture)
		free(map->texture);
}

void	ft_free_color(t_map *map)
{
	if (map->ceiling_color)
		free(map->ceiling_color);
	if (map->floor_color)
		free(map->floor_color);
}

void	ft_free_all_maps(t_map *map)
{
	if (map->padded_map)
		ft_free_matrix(map->padded_map);
	if (map->real_map)
		ft_free_matrix(map->real_map);
}

void	ft_free_mlx(t_map *map)
{
	if (map->mlx_data == NULL)
		return ;
	if (map->mlx_data->img)
	{
		mlx_destroy_image(map->mlx_data->connection, map->mlx_data->img);
		map->mlx_data->img = NULL;
	}
	if (map->mlx_data->window)
	{
		mlx_destroy_window(map->mlx_data->connection, map->mlx_data->window);
		map->mlx_data->window = NULL;
	}
	if (map->mlx_data->connection)
	{
		mlx_destroy_display(map->mlx_data->connection);
		free(map->mlx_data->connection);
		map->mlx_data->connection = NULL;
	}
	free(map->mlx_data);
}
