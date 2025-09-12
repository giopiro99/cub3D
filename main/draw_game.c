/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:44:44 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 18:41:39 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_define_column_value(t_column *column, t_3d *_3d_data, t_texture *tex)
{
	column->step = 1.0 * tex->load_texture[_3d_data->tex_index].height
		/ _3d_data->line_height;
	column->tex_pos = (_3d_data->draw_start
			- HIGHT / 2 + _3d_data->line_height / 2) * column->step;
	column->y = _3d_data->draw_start;
	column->color = 0;
	column->offset = 0;
}

void	draw_textured_column(t_mlx *mlx, int x, t_3d *_3d_data, t_texture *tex)
{
	t_column	column;

	if (_3d_data->tex_index == OPN_DOOR)
		ft_draw_door_frame(mlx, x, _3d_data, tex);
	else
	{
		ft_define_column_value(&column, _3d_data, tex);
		while (column.y < _3d_data->draw_end)
		{
			_3d_data->tex_y = (int)column.tex_pos
				& (tex->load_texture[_3d_data->tex_index].height - 1);
			column.tex_pos += column.step;
			column.offset = _3d_data->tex_y
				* tex->load_texture[_3d_data->tex_index].size_len
				+ _3d_data->tex_x
				* (tex->load_texture[_3d_data->tex_index].bpp / 8);
			column.color = *(int *)(tex->load_texture[_3d_data->tex_index].addr
					+ column.offset);
			ft_put_pixel(mlx, x, column.y, column.color);
			column.y++;
		}
	}
}

void	ft_draw_cieling_and_floor(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HIGHT)
		{
			if (y < HIGHT / 2)
				ft_put_pixel(map->mlx_data, x, y,
					convert_color(map->floor_color->r,
						map->floor_color->g, map->floor_color->b));
			else
				ft_put_pixel(map->mlx_data, x, y,
					convert_color(map->ceiling_color->r,
						map->ceiling_color->g, map->ceiling_color->b));
			y++;
		}
		x++;
		y = 0;
	}
}

void	ft_draw_minimap(t_map *map)
{
	draw_circular_minimap(map);
	ft_draw_player(map);
	draw_player_direction_ray(map, map->ray_line);
}

void	ft_draw(t_map *map)
{
	ft_draw_cieling_and_floor(map);
	render_3d_view(map, map->mlx_data);
	ft_draw_minimap(map);
	ft_define_weapon(map);
	if (map->keys->shift_sx && map->current_weapon == WEAPON_SNIPER)
		ft_draw_scope(map);
	else if (map->current_weapon == WEAPON_GUN)
		ft_draw_mini_gun(map);
	else if (map->current_weapon == WEAPON_SNIPER)
	{
		if (map->shooting)
		{
			if (get_time_in_ms() - map->shooting_time < 150)
				my_put_image(map->mlx_data,
					&map->texture->load_texture[8], WIDTH - 1440, HIGHT - 900);
			else
				map->shooting = false;
		}
		else
			ft_draw_sniper(map);
	}
}
