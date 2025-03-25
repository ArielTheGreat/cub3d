/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:03:32 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/19 10:22:50 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = (const unsigned char *)s;

	while (n > 0)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	arr[] = "Hello, World!";
// 	char	ch;
// 	char	*p;

// 	ch = 'o';
// 	p = ft_memchr(arr, ch, sizeof(arr));
// 	if (p != NULL)
// 	{
// 		printf(" '%c' was found at: %ld\n", ch, (long)(p
// 				- arr));
// 	}
// 	else
// 	{
// 		printf(" '%c' was not found..\n", ch);
// 	}
// 	return (0);
// }
