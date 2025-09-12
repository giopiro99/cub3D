/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:22:42 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:23:52 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_define_vertical_texture(t_3d *_3d_data)
{
	if (_3d_data->is_door && !_3d_data->is_open_door)
		_3d_data->tex_index = CLS_DOOR;
	else if (_3d_data->is_door && _3d_data->is_open_door)
		_3d_data->tex_index = OPN_DOOR;
	else
	{
		if (_3d_data->ray_dir_x > 0)
			_3d_data->tex_index = EAST;
		else
			_3d_data->tex_index = WEST;
	}
}

static void	ft_define_horizontal_texture(t_3d *_3d_data)
{
	if (_3d_data->is_door && !_3d_data->is_open_door)
		_3d_data->tex_index = CLS_DOOR;
	else if (_3d_data->is_door && _3d_data->is_open_door)
		_3d_data->tex_index = OPN_DOOR;
	else
	{
		if (_3d_data->ray_dir_y > 0)
			_3d_data->tex_index = SOUTH;
		else
			_3d_data->tex_index = NORTH;
	}
}

void	ft_define_texture(t_3d *_3d_data, int hit_flag)
{
	if (hit_flag == 0)
		ft_define_vertical_texture(_3d_data);
	else
		ft_define_horizontal_texture(_3d_data);
}
