/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:28 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/13 12:36:12 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p = (const unsigned char *)s1;
	const unsigned char	*d = (const unsigned char *)s2;

	while (n > 0)
	{
		if (*p != *d)
		{
			return (*p - *d);
		}
		p++;
		d++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "Hello World";
// 	char	str2[] = "Hello World";
// 	int		n;

// 	n = ft_memcmp(str1, str2, sizeof(str1));
// 	if (n > 0)
// 		printf("'%s is greater than '%s'. \n", str1, str2);
// 	else if (n < 0)
// 		printf("'%s is less than '%s'. \n", str1, str2);
// 	else
// 		printf("'%s is the same as '%s'. \n", str1, str2);
// }
