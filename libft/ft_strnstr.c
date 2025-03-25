/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:09:39 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/12 12:18:17 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*haystack = "Hello, World!";
// 	const char	*needle1 = "World";
// 	const char	*needle2 = "world";
// 	const char	*needle3 = "";
// 	const char	*needle4 = "Hello, World! Goodbye World!";
// 	char		*result1;
// 	char		*result2;
// 	char		*result3;
// 	char		*result4;

// 	size_t len = 13;
// 	result1 = ft_strnstr(haystack, needle1, len);
// 	result2 = ft_strnstr(haystack, needle2, len);
// 	result3 = ft_strnstr(haystack, needle3, len);
// 	result4 = ft_strnstr(haystack, needle4, len);
// 	if (result1)
// 		printf("'%s' found in '%s': %s\n", needle1, haystack, result1);
// 	else
// 		printf("'%s' not found in '%s'.\n", needle1, haystack);
// 	if (result2)
// 		printf("'%s' found in '%s': %s\n", needle2, haystack, result2);
// 	else
// 		printf("'%s' not found in '%s'.\n", needle2, haystack);
// 	if (result3)
// 		printf("Empty, so always found: %s\n", result3);
// 	if (result4)
// 		printf("'%s' found in '%s': %s\n", needle4, haystack, result4);
// 	else
// 		printf("'%s' not found in '%s', because len.\n", needle4, haystack);
// 	return (0);
// }
