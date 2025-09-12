/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:08:28 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/07/16 12:04:37 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//correzione fish eye
static void	ft_calculate_wall_x_impact(t_map *map, t_3d *_3d_data)
{
	if (map->hit_side == 0)
	{
		ft_define_texture(_3d_data, map->hit_side);
		_3d_data->wall_x = map->p_data->yp + _3d_data->dist_to_wall
			* _3d_data->ray_dir_y;
	}
	else
	{
		ft_define_texture(_3d_data, map->hit_side);
		_3d_data->wall_x = map->p_data->xp + _3d_data->dist_to_wall
			* _3d_data->ray_dir_x;
	}
	_3d_data->wall_x -= floor(_3d_data->wall_x);
}

static void	ft_calculate_wall_dimensions(t_3d *_3d_data)
{
	_3d_data->line_height = (int)(HIGHT / _3d_data->dist_to_wall);
	_3d_data->draw_start = -_3d_data->line_height / 2 + HIGHT / 2;
	_3d_data->draw_end = _3d_data->line_height / 2 + HIGHT / 2;
	if (_3d_data->draw_start < 0)
		_3d_data->draw_start = 0;
	if (_3d_data->draw_end >= HIGHT)
		_3d_data->draw_end = HIGHT - 1;
}

void	ft_define_3d_values(t_3d *_3d_data, t_map *map, int *x)
{
	_3d_data->is_door = false;
	_3d_data->camera_x = 2.0 * *x / (double)WIDTH - 1;
	_3d_data->ray_dir_x = map->p_data->dir_x_p + _3d_data->plane_x
		* _3d_data->camera_x;
	_3d_data->ray_dir_y = map->p_data->dir_y_p + _3d_data->plane_y
		* _3d_data->camera_x;
}

void	render_3d_view(t_map *map, t_mlx *mlx)
{
	t_3d			*_3d_data;
	t_texture_data	*tex;
	int				x;

	_3d_data = &map->_3d_data;
	x = 0;
	_3d_data->plane_x = -map->p_data->dir_y_p * 0.66;
	_3d_data->plane_y = map->p_data->dir_x_p * 0.66;
	while (x < WIDTH)
	{
		ft_define_3d_values(_3d_data, map, &x);
		_3d_data->dist_to_wall = ft_ray_casting(map,
				_3d_data->ray_dir_x, _3d_data->ray_dir_y);
		ft_calculate_wall_x_impact(map, _3d_data);
		tex = &map->texture->load_texture[_3d_data->tex_index];
		_3d_data->tex_x = (int)(_3d_data->wall_x * (double)tex->width);
		if ((map->hit_side == 0 && _3d_data->ray_dir_x < 0)
			|| (map->hit_side == 1 && _3d_data->ray_dir_y > 0))
			_3d_data->tex_x = tex->width - _3d_data->tex_x - 1;
		ft_calculate_wall_dimensions(_3d_data);
		draw_textured_column(mlx, x, _3d_data, map->texture);
		x++;
	}
}
