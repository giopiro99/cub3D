/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:40:28 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/07/04 15:20:16 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_extract_texture(char **texture, char *line)
{
	char	*trimmed_line;

	trimmed_line = NULL;
	if (!(*texture))
	{
		while (line && ft_isspace(*line))
			line++;
		trimmed_line = ft_strtrim(line, " 	\n");
		if (!trimmed_line)
			return (false);
		if (ft_strncmp(trimmed_line + (ft_strlen(trimmed_line) - 4),
				".xpm", 4))
			return (free(trimmed_line), false);
		*texture = ft_strdup(trimmed_line);
		free(trimmed_line);
		if (!(*texture))
			return (false);
		return (true);
	}
	else
		return (false);
}

bool	ft_extract_color(t_color *color, char *line)
{
	char	**color_matrix;
	int		len;

	color_matrix = ft_split(line, ',');
	if (!color_matrix)
		return (false);
	len = ft_matrix_len(color_matrix);
	if (len == 3 && ft_check_rgb_format(color_matrix)
		&& ft_count_commas(line) == 2)
	{
		color->r = ft_atoi(color_matrix[0]);
		color->g = ft_atoi(color_matrix[1]);
		color->b = ft_atoi(color_matrix[2]);
		return (ft_free_matrix(color_matrix), true);
	}
	else
		return (ft_free_matrix(color_matrix), false);
}
