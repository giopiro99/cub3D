/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:59:44 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:18:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	calculate_frame(void)
{
	static int	frame = 0;
	static int	last_time = 0;
	static int	direction = 1;
	int			current_time;

	current_time = get_time_in_ms();
	if (current_time - last_time >= FRAME_DURATION)
	{
		frame += direction;
		if (frame == DOOR_FRAMES - 1)
			direction = -1;
		else if (frame == 0)
			direction = 1;
		last_time = current_time;
	}
	return (frame);
}

int	update_door_animation(t_map *map)
{
	static int	last_time = 0;
	int			current_time;

	current_time = get_time_in_ms();
	if (current_time - last_time >= 100)
	{
		map->texture->frame = (map->texture->frame + 1) % 11;
		last_time = current_time;
	}
	return (0);
}

void	ft_draw_door_frame(t_mlx *mlx, int x, t_3d *_3d_data, t_texture *tex)
{
	int		y;
	int		offset;
	double	step;
	double	tex_pos;
	int		frame;

	frame = calculate_frame();
	step = 1.0 * tex->open_doors_texture[frame].height / _3d_data->line_height;
	tex_pos = (_3d_data->draw_start - HIGHT / 2
			+ _3d_data->line_height / 2) * step;
	y = _3d_data->draw_start;
	while (y < _3d_data->draw_end)
	{
		_3d_data->tex_y = (int)tex_pos
			& (tex->open_doors_texture[frame].height - 1);
		tex_pos += step;
		offset = _3d_data->tex_y * tex->open_doors_texture[frame].size_len
			+ _3d_data->tex_x * (tex->open_doors_texture[frame].bpp / 8);
		ft_put_pixel(mlx, x, y,
			*(int *)(tex->open_doors_texture[frame].addr + offset));
		y++;
	}
}
