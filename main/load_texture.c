/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:08:12 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/09/10 12:57:54 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_load_open_door_texture(t_map *map)
{
	t_texture_data	*tmp_tex;
	int				i;
	char			*path;

	i = 0;
	path = ft_strdup("./textures/DOOR_ANM_XPM/OPN_DOOR_00.xpm");
	while (i < 11)
	{
		path[33] = '0' + (i / 10);
		path[34] = '0' + (i % 10);
		tmp_tex = &map->texture->open_doors_texture[i];
		tmp_tex->img = mlx_xpm_file_to_image(map->mlx_data->connection,
				path, &tmp_tex->width, &tmp_tex->height);
		if (!tmp_tex->img)
			return (-1);
		tmp_tex->addr = mlx_get_data_addr(tmp_tex->img,
				&tmp_tex->bpp, &tmp_tex->size_len, &tmp_tex->endian);
		if (!tmp_tex->addr)
			return (-1);
		i++;
	}
	free(path);
	return (0);
}

void	ft_load_doors(t_map *map)
{
	if (ft_load_texture(map, "./textures/CLS_DOOR.xpm", CLS_DOOR))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map,
			"./textures/DOOR_ANM_XPM/OPN_DOOR_05.xpm", OPN_DOOR))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_open_door_texture(map))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
}

void	ft_load_all_texture(t_map *map)
{
	if (ft_load_texture(map, map->texture->no_tex, NORTH))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map, map->texture->so_tex, SOUTH))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map, map->texture->ea_tex, EAST))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map, map->texture->we_tex, WEST))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (map->doors)
		ft_load_doors(map);
	if (ft_load_texture(map, "./textures/GUN_TEX.xpm", MINI_GUN_TEX))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map, "./textures/SCOPE.xpm", GUN_SCOPE))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map, "./textures/BIG_RIFLE.xpm", RIFLE_TEX))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
	if (ft_load_texture(map, "./textures/SNIPER_FIRE.xpm", FIRE_SNIPER))
		ft_error_exit(map, "Error\nFailure loading texture\n", true);
}

int	ft_load_texture(t_map *map, char *path, int direction)
{
	t_texture_data	*tmp_tex;

	tmp_tex = &map->texture->load_texture[direction];
	tmp_tex->img = mlx_xpm_file_to_image(map->mlx_data->connection, path,
			&tmp_tex->width, &tmp_tex->height);
	if (!tmp_tex->img)
		return (-1);
	tmp_tex->addr = mlx_get_data_addr(tmp_tex->img,
			&tmp_tex->bpp, &tmp_tex->size_len, &tmp_tex->endian);
	if (!tmp_tex->addr)
		return (-1);
	return (0);
}
