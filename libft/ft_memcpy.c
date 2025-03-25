/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:28:17 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 13:09:21 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s = (const char *)src;
	size_t		i;

	d = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	src[] = "Hello World";
// 	char	dst[12];
// 	char	dst2[12];

// 	ft_memcpy(dst, src, strlen(src) + 1);
// 	printf("Copied string: %s\n", dst);
// 	memcpy(dst2, src, strlen(src) + 1);
// 	printf("Copied string: %s\n", dst2);
// 	return (0);
// }
