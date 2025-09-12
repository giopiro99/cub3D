/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:06:03 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:14:00 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>

bool	ft_parsing_texture(t_map *map)
{
	char	*line;
	char	*trimmed_line;
	int		fd;

	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	line = get_next_line(fd);
	trimmed_line = NULL;
	if (!line)
		return (false);
	while (line)
	{
		trimmed_line = ft_strtrim(line, " 	\n");
		free(line);
		if (!ft_find_texture_id(map, trimmed_line))
			return (free(trimmed_line), close(fd), false);
		line = get_next_line(fd);
		free(trimmed_line);
	}
	if (check_all_texture(map->texture))
		return (close(fd), true);
	return (close(fd), false);
}

bool	ft_parsing_color(t_map *map)
{
	char	*line;
	int		id_count;
	int		fd;
	char	*trimmed_line;

	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	line = get_next_line(fd);
	id_count = 0;
	trimmed_line = NULL;
	if (!line)
		return (false);
	while (line)
	{
		trimmed_line = ft_strtrim(line, " 	");
		free(line);
		if (!ft_find_color_id(map, trimmed_line, &id_count))
			return (free(trimmed_line), close(fd), false);
		line = get_next_line(fd);
		free(trimmed_line);
	}
	if (id_count == 2)
		return (close(fd), true);
	return (close(fd), false);
}

bool	ft_parsing_file(char *file)
{
	char	*line;
	int		fd;
	char	*trim_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_exit(NULL, "Error\nOpen error\n", true);
	line = get_next_line(fd);
	trim_line = NULL;
	if (!line)
		return (false);
	while (line)
	{
		trim_line = ft_strtrim(line, " 	");
		free(line);
		if (ft_is_cardinal_point(trim_line[0]) || ft_is_color(trim_line[0])
			|| trim_line[0] == '\n' || ft_is_map_element(trim_line[0]))
		{
			line = get_next_line(fd);
			free(trim_line);
		}
		else
			return (free(trim_line), close(fd), false);
	}
	return (close(fd), true);
}

bool	ft_parsing_map(t_map *map)
{
	check_double_map(map);
	init_padded_map(map);
	ft_fill_real_map(map);
	find_player_and_count(map);
	flood_fill(map, (int)map->p_data->yp,
		(int)map->p_data->xp, 'V');
	ft_check_external_spaces(map);
	return (true);
}

void	ft_parsing(t_map *map)
{
	int		fd;

	if (!ft_check_cub(map->file_name))
		ft_error_exit(map, NULL, true);
	fd = open(map->file_name, O_RDWR);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	close (fd);
	if (!ft_parsing_file(map->file_name))
		ft_error_exit(map, "Error\nInvalid element in the file\n", true);
	if (!ft_parsing_texture(map))
		ft_error_exit(map, "Error\nTextures are not valid\n", true);
	if (!ft_parsing_color(map) || !check_color_value(map))
		ft_error_exit (map, "Error\nColor format is not valid\n", true);
	if (!ft_parsing_map(map))
		ft_error_exit(map, "Error\nMap not valid\n", true);
}
