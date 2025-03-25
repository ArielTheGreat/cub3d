/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:01:50 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/15 13:47:30 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str = "teste";
// 	char		searched;
// 	char		*found;

// 	searched = 'e';
// 	found = ft_strchr(str, searched);
// 	printf("The char '%c' was found and the rest of the string is: '%s'\n",
// 		searched, found);

// 	char		*found1;

// 	found1 = strchr(str, searched);
// 	printf("The char '%c' was found and the rest of the string is: '%s'\n",
// 		searched, found1);
// }
