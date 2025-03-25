/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:23:27 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 12:56:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dst[20];
// 	size_t	copied;

// 	copied = ft_strlcpy(dst, src, sizeof(dst));
// 	printf("Copied length: %zu\n", copied);
// 	printf("String: %s\n", dst);
// 	return (0);
// }
