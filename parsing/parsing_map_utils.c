/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:59:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:12:42 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <string.h>

bool	process_map_line(t_map *map, char *line,
		bool *map_ended, bool *space_line)
{
	if (ft_is_line_map(line))
	{
		if (*map_ended && !(*space_line))
			return (true);
	}
	else
	{
		if (map->texture->ea_tex && map->texture->no_tex
			&& map->texture->so_tex && map->texture->we_tex
			&& map->floor_color && map->ceiling_color)
		{
			if (ft_is_empty_line(line))
			{
				*map_ended = true;
				*space_line = false;
			}
			else if (ft_is_only_spaces_tabs(line))
				*space_line = true;
			else
				return (true);
		}
	}
	return (false);
}

void	check_double_map(t_map *map)
{
	int		fd;
	char	*line;
	bool	map_ended;
	bool	space_line;

	line = NULL;
	map_ended = false;
	space_line = NULL;
	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	skip_until_map(&line, fd);
	while (line)
	{
		if (process_map_line(map, line, &map_ended, &space_line))
		{
			if (line)
				free(line);
			return (close (fd), ft_error_exit(map, "Error\nMap error\n", true));
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_filling_map(t_map *map, char **line, int *fd)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (*line)
	{
		map->real_map[y] = ft_strdup(*line);
		if (!map->real_map[y])
		{
			close (*fd);
			ft_error_exit(map, "Error\nMalloc error\n", true);
		}
		if (*line)
		{
			free(*line);
			*line = get_next_line(*fd);
		}
		y++;
	}
	map->real_map[y] = NULL;
}

void	ft_fill_real_map(t_map *map)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	skip_until_map(&line, fd);
	map->real_map = malloc(sizeof(char *) * (map->count_line + 1));
	if (!map->real_map)
	{
		close (fd);
		ft_error_exit(map, "Error\nMalloc error\n", true);
	}
	ft_filling_map(map, &line, &fd);
	close (fd);
}

int	take_max_len(char **trimmed_line, int *len, char **line, int fd)
{
	int	max_len;

	max_len = 0;
	while (*trimmed_line)
	{
		if (*len > max_len)
			max_len = *len;
		*len = ft_strlen(*trimmed_line);
		free(*trimmed_line);
		*line = get_next_line(fd);
		*trimmed_line = ft_strtrim(*line, "\n");
		free(*line);
	}
	return (max_len);
}
