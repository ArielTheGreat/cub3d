/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:25:43 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/18 13:05:45 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new_str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

// char	increment_char(unsigned int i, char c)
// {
// 	(void)i;
// 	return (c + 4);
// }

// int	main(void)
// {
// 	char const	*str;
// 	char		*result;

// 	str = "abc";
// 	result = ft_strmapi(str, increment_char);
// 	if (result != NULL)
// 	{
// 		printf("Original: %s\n", str);
// 		printf("Transformed: %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Error allocating memory.\n");
// 	}
// 	if (result)
// 		free(result);
// 	return (0);
// }
