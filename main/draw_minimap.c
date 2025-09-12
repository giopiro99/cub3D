/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:19:16 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:21:40 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_draw_player(t_map *map)
{
	int	size;
	int	px;
	int	py;
	int	x;
	int	y;

	size = 9;
	x = 0;
	y = -size / 2;
	py = (int)(map->p_data->yp * BLOCK_SIZE);
	px = (int)(map->p_data->xp * BLOCK_SIZE);
	while (y <= size / 2)
	{
		x = -size / 2;
		while (x <= size / 2)
		{
			ft_put_pixel(map->mlx_data,
				px + x, py + y, 0x00FF00);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_data->connection, map->mlx_data->window,
		map->mlx_data->img, 0, 0);
}

int	is_inside_circle(int x, int y, int center_x, int center_y)
{
	int	dx;
	int	dy;

	dx = x - center_x;
	dy = y - center_y;
	return (dx * dx + dy * dy <= RADIUS * RADIUS);
}

void	ft_draw_circle(int x, int y, t_map *map)
{
	int	bx;
	int	by;

	bx = x * BLOCK_SIZE;
	by = y * BLOCK_SIZE;
	if (is_inside_circle(bx, by, map->p_data->xp * BLOCK_SIZE,
			map->p_data->yp * BLOCK_SIZE))
	{
		if (map->real_map[y][x] == '1')
			ft_draw_block(map->mlx_data, bx, by, 0x808080);
		else if (map->real_map[y][x] == 'D')
			ft_draw_block(map->mlx_data, bx, by, 0x00FF00);
		else
			ft_draw_block(map->mlx_data, bx, by, 0xFFFFFF);
	}
}

void	draw_player_direction_ray(t_map *map, t_ray *ray)
{
	double	angle;
	double	length;

	length = 1.0;
	angle = atan2(map->p_data->dir_y_p, map->p_data->dir_x_p);
	ray->dir_x = cos(angle);
	ray->dir_y = sin(angle);
	ray->hit_x = map->p_data->xp + ray->dir_x * length;
	ray->hit_y = map->p_data->yp + ray->dir_y * length;
	ray->bresenham_data.ray_x0 = (int)(map->p_data->xp * BLOCK_SIZE);
	ray->bresenham_data.ray_y0 = (int)(map->p_data->yp * BLOCK_SIZE);
	ray->bresenham_data.ray_x1 = (int)(ray->hit_x * BLOCK_SIZE);
	ray->bresenham_data.ray_y1 = (int)(ray->hit_y * BLOCK_SIZE);
	draw_line(map, ray, 0xFF0000);
}

void	draw_circular_minimap(t_map *map)
{
	int	x;
	int	y;

	y = (map->p_data->yp * BLOCK_SIZE - RADIUS) / BLOCK_SIZE;
	while (y <= (map->p_data->yp * BLOCK_SIZE + RADIUS) / BLOCK_SIZE)
	{
		x = (map->p_data->xp * BLOCK_SIZE - RADIUS) / BLOCK_SIZE;
		while (x <= (map->p_data->xp * BLOCK_SIZE + RADIUS) / BLOCK_SIZE)
		{
			if (y >= 0 && x >= 0 && y < map->count_line
				&& x < (int)ft_strlen(map->real_map[y]))
				ft_draw_circle(x, y, map);
			x++;
		}
		y++;
	}
}
