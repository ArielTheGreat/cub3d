/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:33:12 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/12 12:18:48 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrs;
	unsigned char	*ptrd;
	size_t			i;

	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dst;
	if (ptrd < ptrs)
	{
		i = 0;
		while (i < len)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	else if (ptrd > ptrs)
	{
		i = len;
		while (i > 0)
		{
			ptrd[i - 1] = ptrs[i - 1];
			i--;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char		dest[] = "Nonsense";
// 	const char	src[] = "Hello";
// 	char		dest1[] = "Nonsense";
// 	const char	src1[] = "Hello";

// 	printf("Before ft_memmove dst = %s, src = %s\n", dest, src);
// 	ft_memmove(dest, src, 9);
// 	printf("After ft_memmove dst = %s, src = %s\n\n", dest, src);
// 	printf("Before memmove dst = %s, src = %s\n", dest1, src1);
// 	memmove(dest1, src1, 9);
// 	printf("After memmove dst = %s, src = %s\n", dest1, src1);
// 	return (0);
// }
