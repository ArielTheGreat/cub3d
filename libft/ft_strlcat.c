/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:54 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 12:56:39 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	while (src[i - dst_len] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	src[] = "World!";
// 	size_t	dstsize;
// 	size_t	result;

// 	char dst[20] = "Hello, ";
// 	dstsize = sizeof(dst);
// 	result = ft_strlcat(dst, src, dstsize);
// 	printf("Whole length: %zu\n", result);
// 	printf("Combined string: '%s'\n", dst);
// 	return (0);
// }
