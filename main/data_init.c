/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:20:06 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:16:46 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_map_data(t_map *map)
{
	map->texture = malloc(sizeof(t_texture));
	if (!map->texture)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	ft_init_texture_data(map);
	map->keys = malloc(sizeof(t_key));
	if (!map->keys)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	ft_init_keys(map);
	map->mlx_data = NULL;
	map->number_p = 0;
	map->padded_map = NULL;
	map->real_map = NULL;
	map->file_name = NULL;
	map->max_len = 0;
	map->count_line = 0;
	map->doors = NULL;
	map->current_weapon = 0;
	map->shooting = false;
	map->shooting_time = 0;
}

void	ft_init_player_data(t_map *map)
{
	map->p_data = malloc(sizeof(t_player));
	if (!map->p_data)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	map->p_data->xp = 0;
	map->p_data->yp = 0;
	map->p_data->angle = 0;
	map->p_data->fov = 0;
	map->p_data->dir_x_p = 0;
	map->p_data->dir_y_p = 0;
}

void	ft_color_init(t_map *map)
{
	map->floor_color = malloc(sizeof(t_color));
	if (!map->floor_color)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	map->floor_color->r = -1;
	map->floor_color->g = -1;
	map->floor_color->b = -1;
	map->ceiling_color = malloc(sizeof(t_color));
	if (!map->ceiling_color)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	map->ceiling_color->r = -1;
	map->ceiling_color->g = -1;
	map->ceiling_color->b = -1;
}

void	ft_fill_mlx(t_map *map)
{
	map->mlx_data = malloc(sizeof(t_mlx));
	if (!map->mlx_data)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	ft_mlx_init(map);
	map->mlx_data->connection = mlx_init();
	if (!map->mlx_data->connection)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	map->mlx_data->img = mlx_new_image(map->mlx_data->connection,
			WIDTH, HIGHT);
	if (!map->mlx_data->img)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	map->mlx_data->addr = mlx_get_data_addr(map->mlx_data->img,
			&map->mlx_data->bpp, &map->mlx_data->size_len,
			&map->mlx_data->endian);
	if (!map->mlx_data->addr)
		ft_error_exit (map, "Error\nMalloc error\n", true);
	ft_load_all_texture(map);
	map->mlx_data->window = mlx_new_window(map->mlx_data->connection,
			WIDTH, HIGHT, "CUB3D");
	if (!map->mlx_data->window)
		ft_error_exit (map, "Error\nMalloc error\n", true);
}
