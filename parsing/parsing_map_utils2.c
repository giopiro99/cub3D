/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:46:50 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/16 11:14:12 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_is_only_spaces_tabs(char *line)
{
	int		i;
	bool	has_space_tab;

	i = 0;
	has_space_tab = false;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		if (line[i] == ' ' || line[i] == '\t')
			has_space_tab = true;
		i++;
	}
	return (has_space_tab);
}

bool	ft_is_line_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((!ft_isspace(line[i]) && ft_is_map_element(line[i]))
			&& !ft_is_color(line[0]))
			return (true);
		i++;
	}
	return (false);
}

void	skip_until_map(char **line, int fd)
{
	*line = get_next_line(fd);
	while (*line && !ft_is_line_map(*line))
	{
		free(*line);
		*line = get_next_line(fd);
	}
}

int	get_max_len(t_map *map)
{
	char	*line;
	char	*trimmed_line;
	int		fd;
	int		max_len;
	int		len;

	max_len = 0;
	trimmed_line = NULL;
	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	skip_until_map(&line, fd);
	trimmed_line = ft_strtrim(line, "\n");
	free(line);
	len = ft_strlen(trimmed_line);
	max_len = take_max_len(&trimmed_line, &len, &line, fd);
	return (close(fd), max_len);
}

int	get_n_line(t_map *map)
{
	int		fd;
	int		count_line;
	char	*line;

	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(map, "Error\nOpen error\n", true);
	count_line = 0;
	skip_until_map(&line, fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count_line++;
	}
	if (line)
		free(line);
	return (close(fd), count_line);
}
