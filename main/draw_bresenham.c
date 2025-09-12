/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:09:36 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:20:42 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_define_ray_value(t_bresenham *bresenham_data)
{
	bresenham_data->dx = bresenham_data->ray_x1 - bresenham_data->ray_x0;
	if (bresenham_data->dx < 0)
		bresenham_data->dx = -bresenham_data->dx;
	bresenham_data->dy = bresenham_data->ray_y1 - bresenham_data->ray_y0;
	if (bresenham_data->dy < 0)
		bresenham_data->dy = -bresenham_data->dy;
	bresenham_data->dy = -bresenham_data->dy;
	bresenham_data->sx = 1;
	if (bresenham_data->ray_x0 >= bresenham_data->ray_x1)
		bresenham_data->sx = -1;
	bresenham_data->sy = 1;
	if (bresenham_data->ray_y0 >= bresenham_data->ray_y1)
		bresenham_data->sy = -1;
	bresenham_data->err = bresenham_data->dx + bresenham_data->dy;
	bresenham_data->done = 0;
}

void	draw_line(t_map *map, t_ray *ray_line, int color)
{
	t_bresenham	*bresenham_data;

	bresenham_data = &ray_line->bresenham_data;
	ft_define_ray_value(bresenham_data);
	while (!bresenham_data->done)
	{
		ft_put_pixel(map->mlx_data,
			bresenham_data->ray_x0, bresenham_data->ray_y0, color);
		if (bresenham_data->ray_x0 == bresenham_data->ray_x1
			&& bresenham_data->ray_y0 == bresenham_data->ray_y1)
			bresenham_data->done = 1;
		bresenham_data->e2 = 2 * bresenham_data->err;
		if (bresenham_data->e2 >= bresenham_data->dy)
		{
			bresenham_data->err = bresenham_data->err + bresenham_data->dy;
			bresenham_data->ray_x0 = bresenham_data->ray_x0
				+ bresenham_data->sx;
		}
		if (bresenham_data->e2 <= bresenham_data->dx)
		{
			bresenham_data->err = bresenham_data->err + bresenham_data->dx;
			bresenham_data->ray_y0 = bresenham_data->ray_y0
				+ bresenham_data->sy;
		}
	}
}
