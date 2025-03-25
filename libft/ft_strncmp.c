/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:47:12 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/13 12:36:29 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != '\0' && *s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	str2[] = "Helalo, world!";
// 	int		result;

// 	result = ft_strncmp(str1, str2, 6);
// 	if (result == 0)
// 	{
// 		printf("Characters are the same until n reached.\n");
// 	}
// 	else if (result < 0)
// 	{
// 		printf("The first character that does
// not match has a lower value in str1 than in str2.\n");
// 	}
// 	else
// 	{
// 		printf("The first character that does not match has a
// greater value in str1 than in str2.\n");
// 	}
// 	return (0);
// }
