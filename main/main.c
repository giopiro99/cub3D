/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:32:35 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/15 15:36:33 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_game_loop(t_map *map)
{
	move_player(map);
	ft_draw(map);
	return (0);
}

void	ft_create_window(t_map *map)
{
	ft_fill_mlx(map);
	mlx_hook(map->mlx_data->window, 2, 1L << 0, key_press, map);
	mlx_hook(map->mlx_data->window, 3, 1L << 1, key_release, map);
	if (!map->keys->q_press)
	{
		mlx_hook(map->mlx_data->window, 6, 1L << 6, mouse_move, map);
		mlx_mouse_hook(map->mlx_data->window, (void *)mouse_handler, map);
		mlx_hook(map->mlx_data->window, 5, (1L << 3), mouse_release, map);
	}
	mlx_loop_hook(map->mlx_data->connection,
		(void *)update_door_animation, map);
	mlx_loop_hook(map->mlx_data->connection, (void *)ft_game_loop, map);
	mlx_hook(map->mlx_data->window, 17, 0, (void *)ft_close_window, map);
	mlx_loop(map->mlx_data->connection);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (ft_printf(2, "Error\nMalloc error\n"), -1);
		ft_init_data(map);
		map->file_name = argv[1];
		ft_parsing(map);
		ft_create_window(map);
		ft_free_all(map);
	}
	else
		return (ft_printf(2, "Error\nInvalid args"), -1);
	return (0);
}
