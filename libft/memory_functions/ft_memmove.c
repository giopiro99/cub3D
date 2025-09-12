/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:41:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/10 18:05:34 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Copies 'n' bytes from memory area
 * 'src' to memory area 'dest', handling overlap.
 *
 * Unlike memcpy, this function correctly handles overlapping memory areas by
 * copying bytes in a safe order to prevent data corruption.
 * If both 'dest' and 'src' are NULL, returns 'dest' (NULL).
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return void* Pointer to the destination memory area 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*str;

	if (!dest && !src)
		return (dest);
	i = 0;
	dst = dest;
	str = src;
	if (dest <= src)
	{
		while (n != 0)
		{
			dst[i] = str[i];
			i++;
			n--;
		}
	}
	else
	{
		while (n-- > 0)
			dst[n] = str[n];
	}
	return (dst);
}

/*int	main()
{
	char src[] = "ciao";
	char dest[10];
	ft_memmove(src - 10, src, 5);
	dest[5] = '\0';
	printf("%s", dest);
}*/
