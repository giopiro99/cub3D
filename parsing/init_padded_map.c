/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_padded_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:17:24 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:19:10 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_fill_padded_map(t_map *map, char **line, char **trimmed_line, int fd)
{
	int	i;

	i = 0;
	while (i < map->count_line)
	{
		ft_memset(map->padded_map[i], ' ', map->max_len);
		ft_memcpy(map->padded_map[i], *trimmed_line, ft_strlen(*trimmed_line));
		free(*trimmed_line);
		*line = get_next_line(fd);
		*trimmed_line = ft_strtrim(*line, "\n");
		free(*line);
		if (!*trimmed_line && *line)
			ft_error_exit(map, "Error\nMalloc error\n", true);
		i++;
	}
	map->padded_map[i] = NULL;
}

void	get_padded_map(t_map *map)
{
	int		i;
	int		fd;
	char	*trimmed_line;
	char	*line;

	i = 0;
	trimmed_line = NULL;
	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	skip_until_map(&line, fd);
	trimmed_line = ft_strtrim(line, "\n");
	if (!trimmed_line)
	{
		close (fd);
		ft_error_exit(map, "Error\nMalloc error\n", true);
	}
	free(line);
	ft_fill_padded_map(map, &line, &trimmed_line, fd);
	if (trimmed_line)
		free(trimmed_line);
	close (fd);
}

void	init_padded_map(t_map *map)
{
	int	i;

	i = 0;
	map->max_len = get_max_len(map);
	map->count_line = get_n_line(map);
	if (map->count_line == 0 || map->max_len == 0)
		ft_error_exit(map, "Error\nThere is not a map\n", true);
	map->padded_map = ft_calloc((map->count_line + 1), sizeof(char *));
	if (!map->padded_map)
		ft_error_exit(map, "Error\nMalloc error\n", true);
	while (i < map->count_line)
	{
		map->padded_map[i] = ft_calloc((map->max_len + 1), sizeof(char *));
		if (!map->padded_map[i])
			ft_error_exit(map, "Error\nMalloc error\n", true);
		i++;
	}
	get_padded_map(map);
}
