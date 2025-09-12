/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_drawing_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:27:18 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/09/10 12:57:22 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	convert_color(int r, int g, int b)
{
	int	a;

	a = r;
	a = (a << 8) | g;
	a = (a << 8) | b;
	return (a);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	offset;
	int	*dst;

	if (color != 0x00B0D0)
	{
		offset = ((y * (mlx->size_len / 4)) + x);
		dst = (int *)mlx->addr;
		dst[offset] = color;
	}
}

void	ft_draw_block(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			ft_put_pixel(mlx, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	my_put_image(t_mlx *mlx, t_texture_data *tex, int d_x, int d_y)
{
	int		x;
	int		y;
	char	*src;
	char	*dst;
	int		color;

	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			src = tex->addr + (y * tex->size_len + x * (tex->bpp / 8));
			color = *(int *)src;
			if (color != 0xFFFFFF && color != 0xE6E6E6 && color != 0x00B0D0)
			{
				dst = mlx->addr + ((d_y + y)
						* mlx->size_len + (d_x + x) * (mlx->bpp / 8));
				*(int *)dst = color;
			}
			x++;
		}
		y++;
	}
}
