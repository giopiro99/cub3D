/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:36:11 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/07/10 17:35:50 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_is_cardinal_point(char point)
{
	if (point == 'N' || point == 'S' || point == 'E' || point == 'W')
		return (true);
	return (false);
}

bool	ft_is_map_element(char point)
{
	if (point == '0' || point == '1' || point == 32 || point == 'D')
		return (true);
	return (false);
}

bool	ft_is_color(char point)
{
	if (point == 'F' || point == 'C')
		return (true);
	return (false);
}

int	ft_count_commas(char *line)
{
	int	commas_count;
	int	i;

	i = 0;
	commas_count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			commas_count++;
		i++;
	}
	return (commas_count);
}

bool	ft_is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
