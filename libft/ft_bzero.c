/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:05:01 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/12 12:19:24 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	size_t	num = 3;
// 	char	str[12] = "Hello World";
// 	char	str2[12] = "Hello World";
// 	printf("origin: %s\n", str);
// 	ft_bzero(str2, num);
// 	printf("changed ft_bzero: %s\n", str2);
// 	bzero(str, num);
// 	printf("changed bzero: %s\n", str);
// }
