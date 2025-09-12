/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:56:35 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/10 18:11:32 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * Iterates through the string until the null terminator is found,
 * counting the number of characters.
 * Returns 0 if the input string pointer is NULL.
 *
 * @param str Pointer to the null-terminated string.
 * @return size_t Number of characters
 * in the string excluding the null terminator.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	char str[] = "ciao";
	int c = ft_strlen(str) + 48;
	write(1, &c, 1);
}*/
